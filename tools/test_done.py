"""Offline tests for tools/done.py. Run: python3 -I tools/test_done.py
Each test works on a throwaway git repo (a copy of this repo's PROBLEM_LOG.md and links.csv) with a
local bare remote, so no real log row, commit or push is touched."""
import contextlib
import io
import json
import os
import shutil
import subprocess
import sys
import tempfile
import unittest

TOOLS = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(TOOLS)
sys.path.insert(0, TOOLS)
import done  # noqa: E402

CPP = """#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findPages(vector<int> &nums, int m) {
        return 0;
    }
};
"""


def read(path):
    with open(path, encoding="utf-8") as f:
        return f.read()


def write(path, text, mode="w"):
    with open(path, mode, encoding="utf-8") as f:
        f.write(text)


def sh(cwd, *cmd):
    return subprocess.run(list(cmd), cwd=cwd, capture_output=True, text=True, check=True).stdout


class T(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.mkdtemp()
        self.remote = os.path.join(self.tmp, "remote.git")
        self.repo = os.path.join(self.tmp, "repo")
        self.boss = os.path.join(self.tmp, "boss")
        os.makedirs(self.repo)
        os.makedirs(self.boss)
        sh(self.tmp, "git", "init", "-q", "--bare", self.remote)
        for f in ("PROBLEM_LOG.md", "links.csv"):
            shutil.copy(os.path.join(REPO, f), self.repo)
        for f in ("book_allocation.cpp", "isomorphic_strings.cpp", "notes.cpp"):
            write(os.path.join(self.repo, f), CPP)
        sh(self.repo, "git", "init", "-q", "-b", "main")
        sh(self.repo, "git", "config", "user.email", "t@t")
        sh(self.repo, "git", "config", "user.name", "t")
        sh(self.repo, "git", "add", "-A")
        sh(self.repo, "git", "commit", "-q", "-m", "init")
        sh(self.repo, "git", "remote", "add", "origin", self.remote)
        sh(self.repo, "git", "push", "-q", "-u", "origin", "main")
        # Miran's own uncommitted work, which must never be staged or changed
        write(os.path.join(self.repo, "notes.cpp"), "// mine\n", "a")
        os.makedirs(os.path.join(self.repo, "bits"))
        write(os.path.join(self.repo, "bits", "stdc++.h"), "#include <vector>\n")

    def tearDown(self):
        shutil.rmtree(self.tmp)

    def run_done(self, *args):
        out, err = io.StringIO(), io.StringIO()
        with contextlib.redirect_stdout(out), contextlib.redirect_stderr(err):
            code = done.main(list(args) + ["--repo", self.repo, "--boss", self.boss])
        return code, out.getvalue() + err.getvalue()

    def log(self):
        return read(os.path.join(self.repo, "PROBLEM_LOG.md"))

    def row(self, num):
        return [l for l in self.log().splitlines() if l.startswith("| %s |" % num)][0]

    def last_commit_files(self):
        return sorted(sh(self.repo, "git", "show", "--name-only", "--format=", "HEAD").split())

    def test_new_closes_row_commits_two_files_and_pushes(self):
        write(os.path.join(self.repo, "book_allocation.cpp"), "// Miran's solution\n", "a")
        code, out = self.run_done("Book Allocation Problem", "red", "--date", "2026-11-11", "--note", "binary search on answer")
        self.assertEqual(code, 0, out)
        r = done.split_row(self.row(40))
        self.assertEqual(r[5], "✅ solved — binary search on answer")
        self.assertEqual((r[6], r[7], r[8]), ("🔴", "2026-10-27", "2026-11-11"))
        self.assertIn("- Book Allocation Problem (#40) — binary search on answer", self.log())
        self.assertEqual(self.last_commit_files(), ["PROBLEM_LOG.md", "book_allocation.cpp"])
        status = sh(self.repo, "git", "status", "--porcelain")
        self.assertIn(" M notes.cpp", status)
        self.assertIn("?? bits/", status)
        self.assertTrue(read(os.path.join(self.repo, "notes.cpp")).endswith("// mine\n"))
        self.assertEqual(sh(self.repo, "git", "rev-parse", "HEAD"), sh(self.remote, "git", "rev-parse", "main"))
        d = json.loads(read(os.path.join(self.boss, "TASKS_DONE.json")))
        self.assertEqual(d["done"], [{"title": "DSA new: Book Allocation Problem", "date": "2026-11-11"}])

    def test_revisit_marks_status_keeps_dates_and_commits_new_file(self):
        write(os.path.join(self.repo, "isomorphic_strings_v2.cpp"), CPP)
        before = done.split_row(self.row(51))
        code, out = self.run_done("Isomorphic Strings", "🟡", "--revisit", "--date", "2026-11-11", "--no-push")
        self.assertEqual(code, 0, out)
        r = done.split_row(self.row(51))
        self.assertTrue(r[5].endswith("(revisited 2026-11-11 — `isomorphic_strings_v2.cpp`, 🟡)"), r[5])
        self.assertEqual(r[6], "🟡")
        self.assertEqual(r[7:9], before[7:9])
        self.assertIn("- Isomorphic Strings (#51) — two-way mapping (revisited 2026-11-11 🟡)", self.log())
        self.assertEqual(self.last_commit_files(), ["PROBLEM_LOG.md", "isomorphic_strings_v2.cpp"])
        code, out = self.run_done("#51", "green", "--revisit", "--date", "2026-11-18", "--file",
                                  "isomorphic_strings_v2.cpp", "--no-push")
        self.assertEqual(code, 0, out)
        r = done.split_row(self.row(51))
        self.assertIn("(revisited 2026-11-11 — `isomorphic_strings_v2.cpp`, 🟡; revisited 2026-11-18 — "
                      "`isomorphic_strings_v2.cpp`, 🟢)", r[5])
        self.assertIn("(revisited 2026-11-11 🟡; revisited 2026-11-18 🟢)", self.log())
        titles = [x["title"] for x in json.loads(read(os.path.join(self.boss, "TASKS_DONE.json")))["done"]]
        self.assertEqual(titles, ["DSA revisit: Isomorphic Strings"] * 2)

    def test_existing_revisit_format_is_extended(self):
        s = "✅ fixed bugs — x (revisited 2026-10-26 — `a_v2.cpp`, y)"
        self.assertEqual(done.add_revisit_mark(s, "2026-11-12", "`a_v3.cpp`, 🟢"),
                         "✅ fixed bugs — x (revisited 2026-10-26 — `a_v2.cpp`, y; revisited 2026-11-12 — `a_v3.cpp`, 🟢)")

    def test_level_is_never_guessed(self):
        before = self.log()
        code, out = self.run_done("Book Allocation Problem", "ok")
        self.assertEqual(code, 2)
        self.assertIn("level must be", out)
        with self.assertRaises(SystemExit):
            with contextlib.redirect_stderr(io.StringIO()):
                done.main(["Book Allocation Problem", "--repo", self.repo])
        self.assertEqual(self.log(), before)

    def test_refusals_change_nothing(self):
        before = self.log()
        self.assertEqual(self.run_done("Two Sum", "green")[0], 2)                       # already done
        self.assertEqual(self.run_done("Book Allocation Problem", "green", "--revisit")[0], 2)  # not solved yet
        self.assertEqual(self.run_done("Sort", "green")[0], 2)                          # ambiguous
        self.assertEqual(self.run_done("Valid Anagram", "green")[0], 2)                 # no row, no file
        self.assertEqual(self.log(), before)
        self.assertFalse(os.path.exists(os.path.join(self.boss, "TASKS_DONE.json")))

    def test_dry_run_writes_nothing(self):
        before = self.log()
        code, out = self.run_done("Book Allocation Problem", "yellow", "--dry-run")
        self.assertEqual(code, 0, out)
        self.assertIn("dry run", out)
        self.assertEqual(self.log(), before)
        self.assertEqual(sh(self.repo, "git", "log", "--oneline").count("\n"), 1)

    def test_new_problem_without_row_gets_one_from_its_file(self):
        write(os.path.join(self.repo, "valid_anagram.cpp"), CPP.replace("int findPages(vector<int> &nums, int m)",
                                                                                 "bool isAnagram(string s, string t)"))
        code, out = self.run_done("Valid Anagram", "green", "--date", "2026-11-12", "--no-push")
        self.assertEqual(code, 0, out)
        r = done.split_row(self.row(52))
        self.assertEqual(r[1:4], ["Valid Anagram", "`valid_anagram.cpp`", "`bool isAnagram(string s, string t)`"])
        self.assertEqual((r[6], r[8]), ("🟢", "2026-11-12"))
        self.assertRegex(r[7], r"^\d{4}-\d{2}-\d{2}$")
        self.assertIn("Factorial, Valid Anagram", self.log())


if __name__ == "__main__":
    unittest.main(verbosity=1)
