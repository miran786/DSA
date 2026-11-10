#!/usr/bin/env python3
"""Close a DSA problem in one command: log it, commit, push, and tick its Google Task.

  python3 tools/done.py "<problem>" <level> [--revisit] [options]

<level> is Miran's own: 🟢 / green / alone, 🟡 / yellow / hints, 🔴 / red / solution
(AGENTS.md legend). This script never guesses a level and never says how to solve anything.

What it does, in order:
  1. Updates the problem's row in PROBLEM_LOG.md in the existing format:
     new      -> Status "✅ solved" (plus --note), Level, Done = today; the problem's line is added
                 to the revisit list (🔴/🟡) or to Strengths (🟢)
     --revisit -> Status gets "(revisited YYYY-MM-DD — `file`, note)", Level is updated, the
                 original dates stay; its line in the revisit list gets "revisited YYYY-MM-DD <level>"
     A problem with no row (new only) gets one, if its .cpp exists: Started = the file's first
     commit or creation date, never a guessed date.
  2. Stages only PROBLEM_LOG.md and that problem's .cpp, commits only those two, pushes.
  3. Appends {"title": "DSA new|revisit: <name>", "date": ...} to TASKS_DONE.json in the boss's
     Drive folder; the bridge ticks the matching Study task within 15 minutes.

Options:
  --file X.cpp   the .cpp to commit (default: the row's file; for a revisit, the one changed or
                 new file whose name starts with the row's file name, e.g. two_sum_v2.cpp)
  --note "..."   a few words for the Status cell (what went wrong or right)
  --date D       the day it was done (default: today, from the system clock)
  --dry-run      print what would change; write nothing
  --no-push      commit but do not push
  --repo / --boss  other folders (tests only)
Python 3.9 standard library only.
"""
import argparse
import csv
import datetime as dt
import json
import os
import re
import subprocess
import sys

HERE = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BOSS = os.path.expanduser("~/Library/CloudStorage/GoogleDrive-miran786mj@gmail.com/My Drive/Miran Boss Agent")
LEVELS = {"🟢": "🟢", "green": "🟢", "g": "🟢", "alone": "🟢",
          "🟡": "🟡", "yellow": "🟡", "y": "🟡", "hints": "🟡", "hint": "🟡",
          "🔴": "🔴", "red": "🔴", "r": "🔴", "solution": "🔴"}
ROW = re.compile(r"^\|\s*(\d+)\s*\|")
DATE = re.compile(r"^\d{4}-\d{2}-\d{2}$")
HEAD_RED = "**🔴 Solution Given"
HEAD_YEL = "**🟡 Hints Needed"
KEEP_DONE = 40


class Stop(Exception):
    pass


def norm(s):
    return re.sub(r"[^a-z0-9]", "", s.lower())


def snake(s):
    return re.sub(r"_+", "_", re.sub(r"[^a-z0-9]+", "_", s.lower())).strip("_")


def git(repo, *args, check=True):
    r = subprocess.run(["git", "-C", repo] + list(args), capture_output=True, text=True)
    if check and r.returncode != 0:
        raise Stop("git %s failed: %s" % (" ".join(args), (r.stderr or r.stdout).strip()))
    return r


def split_row(line):
    return [c.strip() for c in line.strip().strip("|").split("|")]


def join_row(cells):
    return "| " + " | ".join(cells) + " |"


def find_row(lines, name):
    rows = [(i, split_row(l)) for i, l in enumerate(lines) if ROW.match(l)]
    rows = [(i, c) for i, c in rows if len(c) >= 9]
    key = norm(name)
    m = re.fullmatch(r"#?(\d+)", name.strip())
    if m:
        hit = [(i, c) for i, c in rows if c[0] == m.group(1)]
    else:
        hit = [(i, c) for i, c in rows if norm(c[1]) == key]
        if not hit:
            hit = [(i, c) for i, c in rows if key and key in norm(c[1])]
    if len(hit) > 1:
        raise Stop("more than one row matches %r: %s. Use the exact name or the row number."
                   % (name, ", ".join("#%s %s" % (c[0], c[1]) for _, c in hit)))
    return (hit[0] if hit else (None, None)), rows


def changed_files(repo):
    out = git(repo, "status", "--porcelain", "--untracked-files=all").stdout
    return [l[3:].strip().strip('"') for l in out.splitlines() if l[3:].strip()]


def pick_cpp(repo, cells, revisit, given):
    if given:
        if not os.path.exists(os.path.join(repo, given)):
            raise Stop("--file %s does not exist in %s" % (given, repo))
        return given
    base = re.sub(r"[`\s]", "", cells[2]) if cells else ""
    if not revisit:
        return base if base and os.path.exists(os.path.join(repo, base)) else None
    stem = base[:-4] if base.endswith(".cpp") else base
    cands = [f for f in changed_files(repo) if f.endswith(".cpp") and "/" not in f and stem
             and (f == base or f.startswith(stem + "_"))]
    if len(cands) > 1:
        raise Stop("several changed files could be this revisit: %s. Pass --file." % ", ".join(cands))
    return cands[0] if cands else None


def started_date(repo, cpp):
    r = git(repo, "log", "--diff-filter=A", "--follow", "--format=%cs", "--", cpp, check=False)
    dates = [d for d in r.stdout.split() if DATE.match(d)]
    if dates:
        return dates[-1]
    st = os.stat(os.path.join(repo, cpp))
    t = getattr(st, "st_birthtime", st.st_mtime)
    return dt.date.fromtimestamp(t).isoformat()


def signature(repo, cpp):
    try:
        with open(os.path.join(repo, cpp), encoding="utf-8") as f:
            text = f.read()
    except OSError:
        return "—"
    m = re.search(r"public:\s*\n\s*([^\n{]+\))\s*\{", text)
    return "`%s`" % m.group(1).strip() if m else "—"


def add_revisit_mark(status, when, extra):
    """'… (revisited A — x)' -> '… (revisited A — x; revisited B — y)'; else append '(revisited B — y)'."""
    piece = "revisited %s%s" % (when, " — " + extra if extra else "")
    m = re.search(r"\(revisited [^()]*\)\s*$", status)
    if m:
        return status[:m.end()].rstrip()[:-1] + "; " + piece + ")"
    return status + " (" + piece + ")"


def update_lists(lines, num, name, level, revisit, when, note):
    """Keep the Summary & Revisit List in step, as AGENTS.md asks."""
    tag = "(#%s)" % num
    idx = [i for i, l in enumerate(lines) if l.startswith("- ") and tag in l]
    if revisit:
        for i in idx:
            l = lines[i]
            mark = "revisited %s %s" % (when, level)
            m = re.search(r"\(revisited [^()]*\)\s*$", l)
            lines[i] = l[:m.end()].rstrip()[:-1] + "; " + mark + ")" if m else l.rstrip() + " (" + mark + ")"
        return lines
    if idx:
        return lines
    if level == "🟢":
        for i, l in enumerate(lines):
            if l.startswith("## Strengths"):
                if i + 1 < len(lines) and lines[i + 1].startswith("✅"):
                    lines[i + 1] = lines[i + 1].rstrip() + ", " + name
                return lines
        return lines
    head = HEAD_RED if level == "🔴" else HEAD_YEL
    for i, l in enumerate(lines):
        if l.startswith(head):
            lines.insert(i + 1, "- %s %s — %s" % (name, tag, note or "re-solve from a blank file"))
            return lines
    return lines


def close(args):
    repo, boss = os.path.abspath(args.repo), os.path.abspath(args.boss)
    level = LEVELS.get(args.level.strip().lower())
    if not level:
        raise Stop("level must be 🟢/green/alone, 🟡/yellow/hints or 🔴/red/solution (got %r)" % args.level)
    when = args.date or dt.date.today().isoformat()
    if not DATE.match(when):
        raise Stop("--date must be YYYY-MM-DD")
    log_path = os.path.join(repo, "PROBLEM_LOG.md")
    with open(log_path, encoding="utf-8") as f:
        text = f.read()
    lines = text.split("\n")
    (i, cells), rows = find_row(lines, args.problem)

    if cells is None:
        if args.revisit:
            raise Stop("no PROBLEM_LOG.md row for %r, so there is nothing to revisit" % args.problem)
        cpp = args.file or (snake(args.problem) + ".cpp")
        if not os.path.exists(os.path.join(repo, cpp)):
            raise Stop("no row for %r and no %s: create the problem file first (AGENTS.md workflow), or pass --file"
                       % (args.problem, cpp))
        num = str(max(int(c[0]) for _, c in rows) + 1)
        name = args.problem.strip()
        cells = [num, name, "`%s`" % cpp, signature(repo, cpp), "—",
                 "✅ solved" + (" — " + args.note if args.note else ""), level,
                 started_date(repo, cpp), when]
        last = max(j for j, _ in rows)
        lines.insert(last + 1, join_row(cells))
        action = "added row #%s" % num
    else:
        num, name = cells[0], cells[1]
        cpp = pick_cpp(repo, cells, args.revisit, args.file)
        if args.revisit:
            if not (cells[5].startswith("✅") or DATE.match(cells[8])):
                raise Stop("#%s %s is not solved yet: close it as new first (no --revisit)" % (num, name))
            if "revisited %s" % when in cells[5]:
                raise Stop("#%s %s already has a revisit on %s" % (num, name, when))
            extra = ", ".join(x for x in ("`%s`" % cpp if cpp else "", args.note or "", level) if x)
            cells[5] = add_revisit_mark(cells[5], when, extra)
            cells[6] = level
            action = "revisit marked on #%s" % num
        else:
            if DATE.match(cells[8]) or cells[5].startswith("✅"):
                raise Stop("#%s %s is already done (%s). For a re-solve use --revisit."
                           % (num, name, cells[8]))
            cells[5] = "✅ solved" + (" — " + args.note if args.note else "")
            cells[6] = level
            cells[8] = when
            action = "row #%s closed" % num
        lines[i] = join_row(cells[:9] + cells[9:])
    lines = update_lists(lines, num, name, level, args.revisit, when, args.note)
    new_text = "\n".join(lines)
    kind = "revisit" if args.revisit else "new"
    title = "DSA %s: %s" % (kind, name)
    msg = "%s %s: %s %s" % ("Revisit" if args.revisit else "Done", when, name, level)

    lp = os.path.join(repo, "links.csv")
    names = set()
    if os.path.exists(lp):
        with open(lp, encoding="utf-8") as f:
            names = {norm(r.get("name") or "") for r in csv.DictReader(f)}
    no_links = norm(name) not in names

    print("%s: %s" % (action, name))
    print("  " + [l for l in lines if ROW.match(l) and split_row(l)[0] == num][0])
    print("  commit: %s  (%s)" % (msg, ", ".join(["PROBLEM_LOG.md"] + ([cpp] if cpp else []))))
    if not cpp:
        print("  note: no .cpp found for this problem; only the log is committed")
    if no_links:
        print("  note: links.csv has no row for %s; add one (AGENTS.md)" % name)
    if args.dry_run:
        print("dry run: nothing written")
        return 0

    with open(log_path + ".tmp", "w", encoding="utf-8") as f:
        f.write(new_text)
    os.replace(log_path + ".tmp", log_path)
    paths = ["PROBLEM_LOG.md"] + ([cpp] if cpp else [])
    git(repo, "add", "--", *paths)
    git(repo, "commit", "-m", msg, "--only", "--", *paths)
    pushed = "not pushed (--no-push)"
    if not args.no_push:
        r = git(repo, "push", check=False)
        pushed = "pushed" if r.returncode == 0 else "PUSH FAILED: " + (r.stderr or r.stdout).strip().splitlines()[-1]
    print("  " + pushed)

    done_path = os.path.join(boss, "TASKS_DONE.json")
    if os.path.isdir(boss):
        try:
            with open(done_path, encoding="utf-8") as f:
                data = json.load(f)
        except (OSError, ValueError):
            data = {"done": []}
        items = [d for d in data.get("done", []) if not (d.get("title") == title and d.get("date") == when)]
        items.append({"title": title, "date": when})
        with open(done_path + ".tmp", "w", encoding="utf-8") as f:
            json.dump({"done": items[-KEEP_DONE:]}, f, ensure_ascii=False, indent=1)
        os.replace(done_path + ".tmp", done_path)
        print("  Google Task \"%s\" ticks within 15 minutes" % title)
    else:
        print("  boss folder not found: tick the Google Task by hand")
    return 0 if pushed in ("pushed", "not pushed (--no-push)") else 1


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("problem")
    ap.add_argument("level")
    ap.add_argument("--revisit", action="store_true")
    ap.add_argument("--file")
    ap.add_argument("--note")
    ap.add_argument("--date")
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--no-push", action="store_true")
    ap.add_argument("--repo", default=HERE)
    ap.add_argument("--boss", default=BOSS)
    args = ap.parse_args(argv)
    try:
        return close(args)
    except Stop as e:
        print("done.py: " + str(e), file=sys.stderr)
        return 2


if __name__ == "__main__":
    sys.exit(main())
