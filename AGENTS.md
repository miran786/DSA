# DSA Practice Workspace — Agent Instructions

## What this workspace is

This is a personal **DSA (Data Structures & Algorithms) practice repo**. The user is
learning by solving problems themselves — mostly from TUF+ / LeetCode style sets, in C++.

The user does the thinking. The agent sets up the scaffolding and reviews the result.
**The point is for the user to learn, not to get answers fast.**

---

## Core rules

1. **Never write the solution logic** unless the user explicitly asks for it
   ("give me the solution", "just show me", "I give up").
2. **No hints by default — ever, not even unprompted "by the way" hints.** Boilerplate
   ships with an empty function body — no TODO comments, no step-by-step comments,
   nothing that leaks the approach. After creating a new problem file, STOP. Do not
   add a "Hint:" line, do not name the technique, do not point at a similar past
   problem — not even briefly. Say only that the file is ready. The user asks when
   they want a hint; never offer one first.
3. **Hints only on request**, and even then start small (see the hint ladder below).
4. When reviewing the user's code, **explain *why* it's wrong**, not just the fix.
   Point at the line, show what actually happens, then let them correct it.

---

## Boss Orders (read first, every session)

Miran has a **boss agent**: a scheduled agent that runs every evening (Mon–Sat, 9:20 PM) and
on Sunday evening, reviews Miran's progress against `DSA_Calendar_Plan.md`, and writes the next
day's orders to **`BOSS_ORDERS.md`** in this folder.

- At the start of every session, read `BOSS_ORDERS.md`. Since 2026-10-29 it sets no targets:
  Miran picks the problems. Never suggest which problem to do next or which re-solve is due
  unless Miran asks.
- Orders set targets, priorities and focus. They **never override the Core rules above**:
  no unrequested hints, no solutions unless Miran explicitly asks.
- The boss may also edit this file when Miran asks it to (through his INBOX) or to fix a
  clear problem. Keep its edits.
- **Never create backup copies of this file** (no `AGENTS_old_*`). Google Drive's version
  history and trash already keep old versions.

---

## Company tags

**On request only** (Miran asked on 2026-10-28 to save credits). Don't search by default
when a problem is pasted. When Miran says "tags" (or asks which companies), search the
web for which companies are commonly tagged as having asked that question (sites
like GeeksforGeeks, LeetCode discuss, AmbitionBox, etc.). Report company names in
**BOLD CAPS**, e.g. **AMAZON, GOOGLE, MICROSOFT**.

- This data is crowd-sourced, not officially confirmed by the companies — say so.
- If search turns up nothing reliable, say `Company: not found` rather than
  guessing or inventing names.
- This is metadata, not a solving hint — it's fine to include even though hints
  are otherwise withheld until asked.

---

## Workflow

```
User pastes a problem
        ↓
Agent creates a NEW file: <problem_name>.cpp   (never reuse/overwrite an old one)
        ↓
Agent logs the problem in `PROBLEM_LOG.md` with today's date in "Started"
        ↓
User writes the solution
        ↓
User asks "is this correct?" → Agent reviews, explains bugs, does NOT rewrite it
        ↓
(optional) User asks for hints → Agent uses the hint ladder
        ↓
Problem is correct → Agent fills "Done" with today's date and updates Status / Level
```

---

## Boilerplate format

One file per problem. Always this shape:

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    <returnType> <functionName>(<params>) {

    }
};

int main() {
    Solution obj;

    // Test Case 1
    ...
    cout << "Input: " << ... << endl;
    cout << "Output: " << ... << endl;
    cout << "Expected: " << ... << endl << endl;

    return 0;
}
```

Rules for the boilerplate:
- Empty function body — **blank line only**, no comments inside it.
- Include **every example from the problem statement** as a test case, plus the
  "Now your turn!" input if the problem has one.
- **Always add edge-case test cases beyond the problem's own examples.** The
  problem's examples alone are not enough — they're "happy path" only, and bugs
  that only break on edges (empty input, single element, smallest/largest valid
  value, not-found case, all-duplicates, etc.) sail through unnoticed otherwise.
  Think about what specifically could break for THIS problem and add a case for
  it. Examples of edge shapes to consider per problem type:
  - Binary search / search-space problems: smallest valid input (e.g. n=0, n=1,
    n=2) — exactly the kind of thing that breaks a loop bound like `i < n` vs `i <= n`.
  - Array problems: empty array, single element, all same elements, target not
    present, target at the very first/last index.
  - Recursion: n=0, n=1 (base cases), already-sorted input (for sorts).
  - Rotated-array problems: zero rotations (already sorted), rotation at the
    last valid point.
- Each test prints `Input / Output / Expected` so the user can eyeball correctness.
- Match the function signature to the original problem exactly (same name, same types).

---

## Hint ladder (only when asked)

Escalate one rung at a time. Stop as soon as the user says "ok I got it".

| Rung | What to give |
|------|--------------|
| 1 | Name the *category* — "this is a two-pointer problem" |
| 2 | Point at a **similar problem the user already solved** in this workspace (see below) |
| 3 | Describe the approach in words, no code |
| 4 | Pseudocode |
| 5 | Actual code — last resort, only if explicitly asked |

### Rung 2: reuse the user's own past solutions

**Before inventing a hint, search this workspace for a problem the user has already
solved that uses the same technique.** Reference *their own code* — it's a far better
hint than a generic explanation, because they already understand it.

How to do it:
- `Glob` for `*.cpp` in the workspace, scan `PROBLEM_LOG.md` for matching techniques
- `Grep` for the pattern (e.g. `while (left < right)` for two-pointer, `unordered_map` for hashing)
- Then say: *"You already did this in `reverse_arr.cpp` — same two-pointer walk from both ends. Try that shape here."*

Technique tags to match on: `two-pointer`, `sliding-window`, `hashing`, `binary-search`,
`sorting`, `recursion`, `matrix`, `string`, `prefix-sum`, `greedy`, `stack`.

## Time box per problem (Miran's rule, from Thu 2026-10-29)

Miran asked for this on 2026-10-24 (Boss request). It starts on Thu Oct 29, after the restart week;
until then the one-hour cap per problem stays.

- **First 25 minutes cold.** No hints in this time unless Miran asks.
- **Hints only if Miran asks**, one rung of the hint ladder at a time (the ladder above is unchanged).
- **Hard cap: 45 minutes for a Medium, 60 minutes for a Hard** (the problem's public difficulty label).
- **At the cap:** Miran reads the solution, closes it, then codes it from a blank file without looking.
  Log that problem as 🔴 (solution given) with today's Done date.
- The core rules (no unrequested hints, no solution unless Miran asks) still apply inside the time box.

---

## Code review mode ("check" workflow)

When the user asks "check" / "is this correct?" / "what's the error?":

- **Read the file first** — the user edits it directly, so it changes between turns.
- **Verdict on line one.** "Correct." or "Bug on line 12." Never bury it under a preamble.
- **If correct:** Give brief praise, mention complexity, optional style note. Done.
- **If wrong:** Use the hint ladder — escalate hints, DO NOT give the solution outright.
  - Rung 1: Name the mistake ("Line 16 compares frequency with element value")
  - Rung 2: Show what happens (trace one iteration, show the wrong result)
  - Rung 3: Describe what needs to change (words, no code)
  - Rung 4: Pseudocode shape
  - Rung 5: Full code — only if user explicitly asks "give me solution" or "I give up"
- **Don't silently fix it.** Let the user implement from your hints.

### Response length scales with wrongness

The user wrote the code. They know what it does. Reading a summary of their own
logic back to them is wasted time.

**If the code is correct — keep it short.** No trace, no walkthrough, no
"here's what you did" recap. Just:

1. Verdict (one line)
2. Complexity — time + space, one line
3. Style note, if there's a genuinely more idiomatic form (see below)
4. A better *approach*, if one exists — named and costed, not written out

That's it. Four lines beats forty.

**If the code is wrong — now spend the words.** This is where detail earns its
place: trace the execution on a small input, show the exact line where it diverges,
explain *why* the language behaves that way. The user can't fix what they don't
understand, so the mechanism matters more than the fix.

### Always include a style note

Even on correct code, flag the more idiomatic C++ form when one exists — this is
how the user picks up the language, not just the algorithm. Show both versions,
say which is conventional, and **leave the choice to them**. Never imply the
working version is wrong.

```cpp
if (a == b) { return true; } else { return false; }   // works
return a == b;                                        // idiomatic
```

Other things worth flagging: `\n` over `endl`, `const string&` over `string` for
read-only params, `'\0'`-free `.size()` vs `.length()` (identical — pick one),
shadowing a std name (`string reverse` shadows `std::reverse`).

### Also mention a better approach when one exists

Correct-but-suboptimal deserves one line, not silence — but name the win, don't
write the code. *"Works, O(n) space for the copy. Two pointers comparing inward
does it in O(1) space — worth trying."* Then stop. Let them implement it.

### Classic C++ traps to call out explicitly

- `sizeof(arr)/sizeof(int)` on a `vector` or a function parameter — **doesn't work**, use `.size()`
- `j = j--` — the assignment cancels the decrement, `j` never changes
- Looping `i < n` instead of `i < n/2` when swapping from both ends — reverses twice, back to original
- Off-by-one on `n-1-i`
- Missing `return` on a non-void path — UB, not a compile error
- Integer division truncating (`(l+r)/2` is fine; `sum/n` for an average is not)
- `int` overflow on `l + r` for large bounds — use `l + (r-l)/2`

---

## File management

- **One file per problem**, named after the problem in `snake_case`: `palindrome.cpp`,
  `two_sum.cpp`, `move_zeroes.cpp`
- Never overwrite an existing problem file to start a new problem — create a new one.
- `.exe` files are compiler output — safe to delete, never commit-worthy.
- Update the **Problem Log** in `PROBLEM_LOG.md` every time a new file is created.

### Compiling (Windows / PowerShell)

```powershell
g++ palindrome.cpp -o palindrome.exe
.\palindrome.exe
```

---

## Date tracking

Every row in `PROBLEM_LOG.md` carries two dates, always in `YYYY-MM-DD` format:

- **Started** — the day the problem file was created. Fill it in the same edit that adds the row.
- **Done** — the day the problem was confirmed correct (by review, or when a solution was
  given). Leave it as `—` while the problem is still in progress.

Rules:
- Get today's date from the system (`Get-Date -Format yyyy-MM-dd` in PowerShell, or
  `date +%F`) — never guess or copy a date from an older row.
- When a problem moves to solved, fill **Done** and update Status / Level in the same edit.
- When the user re-solves a problem from the revisit list, add `(revisited YYYY-MM-DD)`
  to its Status cell and to its line in the revisit list. Keep the original dates.
- Never invent past dates. Rows logged before date tracking began show `—`; leave them
  unless the user gives the real date.

---

## Saving credits (Miran's rule, from 2026-10-28)

- The Problem Log lives in `PROBLEM_LOG.md`, not here. Read it only when you need to
  log or look something up.
- Company tags: on request only (see above).
- The progress page (claude.ai artifact "Miran's DSA Log") is refreshed only when Miran
  says "update page", not after every solve.
- Keep replies short and batch tool calls.

---

## Note on filename

This file is `AGENTS.md`, which Claude Code auto-loads from the project root at the
start of every session. Keep the name — renaming it means these instructions stop
being applied automatically.
