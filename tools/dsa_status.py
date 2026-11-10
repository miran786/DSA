#!/usr/bin/env python3
"""DSA status for Miran's boss agent: the numbers and the next day's set.

Reads PROBLEM_LOG.md, DSA_Calendar_Plan.md and links.csv (this repo) and prints:
  - total done, new problems done in the last 7 and 14 days, revisits in the last 7 days
  - the share of the last 10 logged new problems solved without the full solution
  - Phase 1 progress and topic coverage
  - the set for the next day: 1 new + 1 revisit on weekdays (Saturday: up to 2 revisits,
    Sunday: none), with the sheet location and links for each problem

Problem names and links only: this script never says how to solve anything.
Python 3.9 standard library only.

Examples:
  python3 tools/dsa_status.py                       # today (IST), set for tomorrow
  python3 tools/dsa_status.py --date 2026-11-09     # as of that evening
  curl -s https://raw.githubusercontent.com/miran786/DSA/main/tools/dsa_status.py \
    | python3 - --remote --assigned "Reverse Words in a String;Two Sum"
Options:
  --date D          the day being closed (default: today in IST)
  --for F           the day to plan (default: D + 1)
  --mode M          normal | exam | drive | rest (drive = revisits only, rest = nothing)
  --assigned "A;B"  the problems assigned for D: any not done by D goes first in F's set
  --extra-done "Name=YYYY-MM-DD;..."  new problems done but not yet in PROBLEM_LOG.md
  --extra-revisit "Name=YYYY-MM-DD;..."  revisits done (ticked) but not yet marked in the log
  --remote          read the three files from GitHub (main) instead of this checkout
  --json            print JSON instead of text
"""
import argparse
import csv
import datetime as dt
import io
import json
import os
import re
import sys
import urllib.request

RAW = "https://raw.githubusercontent.com/miran786/DSA/main/"
FILES = ("PROBLEM_LOG.md", "DSA_Calendar_Plan.md", "links.csv")
DATE = re.compile(r"\d{4}-\d{2}-\d{2}")
LEVELS = ("🟢", "🟡", "🔴")


def norm(name):
    return re.sub(r"[^a-z0-9]", "", name.lower())


def day(s):
    return dt.date.fromisoformat(s)


def read_sources(remote):
    out = {}
    root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    if not os.path.exists(os.path.join(root, FILES[0])):
        remote = True  # run from stdin (curl ... | python3 -): read from GitHub
    if remote:
        for name in FILES:
            with urllib.request.urlopen(RAW + name, timeout=30) as r:
                out[name] = r.read().decode("utf-8")
    else:
        root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
        for name in FILES:
            with open(os.path.join(root, name), encoding="utf-8") as f:
                out[name] = f.read()
    return out


def parse_log(text):
    rows = []
    for line in text.splitlines():
        if not re.match(r"\|\s*\d+\s*\|", line):
            continue
        c = [x.strip() for x in line.strip().strip("|").split("|")]
        if len(c) < 9:
            continue
        num, name, _file, _sig, _tech, status, level, started, done = c[:9]
        level = next((l for l in LEVELS if l in level), level)
        r = {
            "num": int(num), "name": name, "status": status, "level": level,
            "started": started if DATE.fullmatch(started) else None,
            "done": done if DATE.fullmatch(done) else None,
            "solved": status.startswith("✅"),
            "unfinished": status.startswith(("⏳", "⚠️")),
            "revisits": DATE.findall(" ".join(re.findall(r"revisited \d{4}-\d{2}-\d{2}", status))),
        }
        # A Done date that is really a revisit date is not a new problem that day.
        r["new_done"] = r["done"] if r["done"] and r["done"] not in r["revisits"] else None
        rows.append(r)
    parked = set()
    m = re.search(r"Parked[^\n]*\n((?:- .*\n)+)", text)
    if m:
        for line in m.group(1).splitlines():
            parked.add(norm(re.sub(r"\s*\(#.*", "", line[2:])))
    return rows, parked


def parse_plan(text):
    topics = []
    for m in re.finditer(r"^\d+\. \*\*(.+?):\*\* (.+)$", text, re.M):
        names = [n.strip().rstrip(".") for n in m.group(2).split(";")]
        topics.append((m.group(1), [n for n in names if n]))
    hards = set()
    m = re.search(r"\*\*Parked Hards:\*\* (.+)", text)
    if m:
        hards = {norm(n.strip().rstrip(".")) for n in m.group(1).split(";")}
    return topics, hards


def parse_links(text):
    return {norm(r["name"]): r for r in csv.DictReader(io.StringIO(text))}


def due_of(r):
    """Next revisit due date of a log row, or None for 'due now' (backlog with no date)."""
    if r["unfinished"]:
        return None
    if r["revisits"]:
        last = day(max(r["revisits"]))
        return last + dt.timedelta(days=2 if r["level"] == "🔴" else 7)
    base = r["new_done"] or r["done"]
    if not base:
        return None
    return day(base) + dt.timedelta(days=2 if r["level"] == "🔴" else 7)


def build(args, src):
    rows, parked = parse_log(src["PROBLEM_LOG.md"])
    topics, hards = parse_plan(src["DSA_Calendar_Plan.md"])
    links = parse_links(src["links.csv"])
    D = day(args.date)
    F = day(args.for_) if args.for_ else D + dt.timedelta(days=1)

    extra = {}
    for item in filter(None, (args.extra_done or "").split(";")):
        name, _, when = item.partition("=")
        extra[norm(name)] = (name.strip(), when.strip() or None)
    for item in filter(None, (args.extra_revisit or "").split(";")):
        name, _, when = item.partition("=")
        for r in rows:
            if norm(r["name"]) == norm(name) and DATE.fullmatch(when.strip()):
                r["revisits"].append(when.strip())
    logged = {norm(r["name"]) for r in rows}
    extra = {k: v for k, v in extra.items() if k not in logged}

    done_names = {norm(r["name"]) for r in rows if r["solved"]} | set(extra)
    new_dates = [day(r["new_done"]) for r in rows if r["new_done"]]
    new_dates += [day(w) for _, w in extra.values() if w]

    def count(days):
        return sum(1 for x in new_dates if D - dt.timedelta(days=days - 1) <= x <= D)

    revisit_dates = [day(x) for r in rows for x in r["revisits"]]
    last10 = [r for r in sorted(rows, key=lambda r: r["num"]) if r["level"] in LEVELS][-10:]
    non_red = sum(1 for r in last10 if r["level"] != "🔴")
    green = sum(1 for r in last10 if r["level"] == "🟢")

    plan_names = [n for _, names in topics for n in names]
    p1_done = sum(1 for n in plan_names if norm(n) in done_names)
    coverage = sum(1 for _, names in topics if all(norm(n) in done_names for n in names))
    current = next(((t, names) for t, names in topics
                    if not all(norm(n) in done_names for n in names)), None)

    # ---- the next day's set ----
    by_name = {norm(r["name"]): r for r in rows}
    plan_set = {norm(n) for n in plan_names}

    def done_on(name):
        k = norm(name)
        r = by_name.get(k)
        if k in plan_set and k in done_names and not (r and r["level"] in ("🔴", "🟡")
                                                      and r["revisits"]):
            return True  # a new problem counts once it is done at all
        if r and (D.isoformat() in r["revisits"] or r["done"] == D.isoformat()):
            return True
        return False

    assigned = [a.strip() for a in (args.assigned or "").split(";") if a.strip()]
    rolled = [a for a in assigned if not done_on(a)]
    rolled_new = [a for a in rolled if norm(a) in plan_set and norm(a) not in done_names]
    rolled_rev = [a for a in rolled if a not in rolled_new]

    pool = []
    for r in rows:
        k = norm(r["name"])
        if k in hards or k in parked:
            continue
        if not (r["level"] in ("🔴", "🟡") or r["unfinished"]):
            continue
        if D.isoformat() in r["revisits"]:
            continue
        due = due_of(r)
        if due and due > F:
            continue
        fresh = due is not None and F - dt.timedelta(days=3) <= due <= F
        key = (0, 0 if r["level"] == "🔴" else 1, due) if fresh else \
              (1, due or dt.date.min, r["num"])
        pool.append((key, r["name"], due))
    pool.sort(key=lambda x: x[0])
    pool_names = [n for _, n, _ in pool if norm(n) not in {norm(x) for x in rolled_rev}]

    next_new = [n for n in plan_names if norm(n) not in done_names and norm(n) not in hards]

    wd = F.weekday()  # 0 = Monday
    s_new, s_rev = [], []
    if args.mode == "rest" or wd == 6:
        pass
    elif args.mode == "drive" or wd == 5:
        s_rev = (rolled_rev + pool_names)[:2]
    else:
        s_new = (rolled_new + [n for n in next_new if n not in rolled_new])[:1]
        s_rev = (rolled_rev + pool_names)[:1]
        if not s_rev:  # pool dry: a second new problem
            s_new = (rolled_new + [n for n in next_new if n not in rolled_new])[:2]

    def item(kind, name):
        r = by_name.get(norm(name))
        l = links.get(norm(name), {})
        due = due_of(r) if r and kind == "revisit" else None
        return {
            "kind": kind, "name": name,
            "level": r["level"] if r else None,
            "due": due.isoformat() if due else None,
            "rolled_over": name in rolled,
            "sheet": l.get("sheet") or None,
            "striver": l.get("striver") or None,
            "tuf_plus": bool(l.get("tuf_plus")),
            "leetcode": l.get("leetcode") or None,
            "difficulty": l.get("difficulty") or None,
        }

    return {
        "as_of": D.isoformat(), "for": F.isoformat(), "mode": args.mode,
        "total_done": len(done_names),
        "new_7": count(7), "new_14": count(14),
        "revisits_7": sum(1 for x in revisit_dates if D - dt.timedelta(days=6) <= x <= D),
        "last10": {"n": len(last10), "non_red": non_red, "green": green,
                   "rows": "#%d-#%d" % (last10[0]["num"], last10[-1]["num"]) if last10 else ""},
        "phase1": {"done": p1_done, "of": len(plan_names), "topics_done": coverage,
                   "topics": len(topics),
                   "current_topic": current[0] if current else None,
                   "current_done": sum(1 for n in current[1] if norm(n) in done_names) if current else 0,
                   "current_of": len(current[1]) if current else 0},
        "logged_on_date": [("new: " if r["new_done"] == D.isoformat() else "revisit: ")
                           + r["name"] + " " + r["level"] for r in rows
                           if r["new_done"] == D.isoformat() or D.isoformat() in r["revisits"]]
                          + ["new: " + n for n, w in extra.values() if w == D.isoformat()],
        "not_logged": [v[0] for v in extra.values()],
        "open_rows": [r["name"] for r in rows if r["unfinished"]],
        "set": [item("new", n) for n in s_new] + [item("revisit", n) for n in s_rev],
        "missing_links": [n for n in s_new + s_rev if norm(n) not in links],
    }


def text(s):
    pct = lambda a, b: "%d%%" % round(100 * a / b) if b else "n/a"
    q = s["last10"]
    p = s["phase1"]
    out = [
        "DSA status as of %s (set for %s, mode %s)" % (s["as_of"], s["for"], s["mode"]),
        "Total done: %d | new in 7 days: %d | new in 14 days: %d | revisits logged in 7 days: %d"
        % (s["total_done"], s["new_7"], s["new_14"], s["revisits_7"]),
        "Last %d logged new (%s): %s without the full solution, %s solved alone"
        % (q["n"], q["rows"], pct(q["non_red"], q["n"]), pct(q["green"], q["n"])),
        "Phase 1: %d of %d | topics fully done: %d of %d | now: %s %d of %d"
        % (p["done"], p["of"], p["topics_done"], p["topics"], p["current_topic"],
           p["current_done"], p["current_of"]),
    ]
    out.append("Logged on %s: %s" % (s["as_of"], ", ".join(s["logged_on_date"]) or "nothing"))
    if s["not_logged"]:
        out.append("Done but not in PROBLEM_LOG.md: " + ", ".join(s["not_logged"]))
    if s["open_rows"]:
        out.append("Started, not finished: " + ", ".join(s["open_rows"]))
    out.append("Set for %s:" % s["for"] if s["set"] else "Set for %s: none" % s["for"])
    for i in s["set"]:
        tag = "DSA %s: %s" % (i["kind"], i["name"])
        extra = []
        if i["rolled_over"]:
            extra.append("rolled over")
        if i["level"]:
            extra.append("last " + i["level"])
        if i["difficulty"]:
            extra.append(i["difficulty"])
        out.append("- " + tag + (" (" + ", ".join(extra) + ")" if extra else ""))
        if i["sheet"]:
            out.append("  Striver sheet: " + i["sheet"])
        if i["striver"]:
            out.append("  Striver%s: %s" % (" (TUF+)" if i["tuf_plus"] else "", i["striver"]))
        if i["leetcode"]:
            out.append("  LeetCode: " + i["leetcode"])
    if s["missing_links"]:
        out.append("No links row for: " + ", ".join(s["missing_links"]) + " (add it to links.csv)")
    return "\n".join(out)


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ist_today = (dt.datetime.utcnow() + dt.timedelta(hours=5, minutes=30)).date().isoformat()
    ap.add_argument("--date", default=ist_today)
    ap.add_argument("--for", dest="for_")
    ap.add_argument("--mode", default="normal", choices=("normal", "exam", "drive", "rest"))
    ap.add_argument("--assigned")
    ap.add_argument("--extra-done")
    ap.add_argument("--extra-revisit")
    ap.add_argument("--remote", action="store_true")
    ap.add_argument("--json", action="store_true")
    args = ap.parse_args()
    s = build(args, read_sources(args.remote))
    print(json.dumps(s, ensure_ascii=False, indent=1) if args.json else text(s))


if __name__ == "__main__":
    sys.exit(main())
