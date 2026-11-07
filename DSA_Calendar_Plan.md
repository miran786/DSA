# DSA Plan: breadth first (Nov 2, 2026 – Jul 2027)

Miran's decision on Nov 2, 2026: **completion before perfection.** Cover every topic that campus tests ask, once, at the standard level, then go deeper. This replaces the core interview set plan (Oct 15 – Apr 21), which went topic by topic in depth. Written by a Claude session at Miran's request. Problem and section names only: this file never says how to solve anything.

**Arrays and Binary Search are closed** (Miran, Nov 2). Their Hards (Book Allocation Problem, Split Array - Largest Sum, Median of Two Sorted Arrays, Count Inversions) are parked for Phase 3.

## Why breadth first (the numbers)
- At Miran's real pace (about 5.5 new problems a week over Oct 9 – Nov 1; 11 in the best week), the old plan reached Graphs around mid-April and DP around late May, after the April–July campus window had opened. Breadth first reaches Graphs around early February and DP around mid-February even at 5.5 a week, ignoring the exam slowdown.
- The hard binary-search problems took 2–3 hours each and mostly ended 🔴. The campus drives open to graduating students in April–July (last year: Clinware, Data-axle, ITANTA, Oneirix, Michelin, Citi and others) test mostly easy-to-medium coding, plus aptitude and CS multiple-choice questions. BizAmica's first round was a 30-minute multiple-choice paper: 77 students were cut to 12 on those marks.

## Rules
- **The 7:30–10:30 block is for DSA only.** No CS subjects in it, and nothing in 11 AM – 3 PM.
- **Time box (unchanged):** 25 minutes cold, then hints only if asked, one rung at a time; cap 45 minutes for a Medium, 60 for a Hard. At the cap: read the solution, close it, code it from a blank file, log it 🔴.
- **Phase 1 skips every problem labelled Hard.** It goes to the parked list, not in the way.
- **A topic is done when its list is done**, not when it is perfect. Sundays: the LeetCode contest at 8:00 if wanted, no new problems.
- **The boss picks every day's problems** (full plan mode, Miran, Nov 3). Weekdays: 4 problems = 2 new (the next unsolved ones in this list, in order) + 2 revisits. Exams (Nov 16 – Dec 15): 3 = 1 new + 2 revisits. Saturdays: revisits only (7–9 AM and 3–5 PM, up to 4 each). The list arrives as Google Tasks ("DSA new: …", "DSA revisit: …") and in BOSS_ORDERS.md.
- **Revisits:** every problem logged 🔴 (solution given) or 🟡 (hints), plus unfinished ones, except Hards. A 🔴 comes back 2 days after it was done and again 7 days later; a 🟡 comes back 7 days later; older ones not yet revisited come back oldest first. Solved alone on a revisit = it leaves the list; hints again = back in 7 days; solution again = back in 2 days.
- **Missed problems roll over** to the next day first, without raising the day's count.
- **Striver's A2Z sheet:** the names here come from it. A problem from the sheet that Miran solves outside the list still counts; PROBLEM_LOG.md is the record (the Notion tracker is stale).
- **Drive days come first.** Shift the plan, don't cram.

## Phase 1: one pass over every topic (87 problems, now to about Feb 7)

| # | Topic | Problems | Rough window |
|---|---|---|---|
| 1 | Strings | 6 | Nov 3–8 |
| 2 | Linked List | 9 | Nov 9–15 |
| 3 | Recursion & Backtracking | 6 | Nov 16 – Dec 15 (exams: about 5 a week) |
| 4 | Sliding Window & Two Pointer | 6 | Nov 16 – Dec 15 |
| 5 | Stack & Queue | 8 | Nov 16 – Dec 15 |
| 6 | Heaps | 4 | Dec 16 – Jan 10 |
| 7 | Greedy | 5 | Dec 16 – Jan 10 |
| 8 | Binary Trees | 12 | Dec 16 – Jan 10 |
| 9 | Binary Search Trees | 5 | Dec 16 – Jan 10 |
| 10 | Graphs | 10 | Jan 11 – Feb 7 |
| 11 | Dynamic Programming | 12 | Jan 11 – Feb 7 |
| 12 | Bits & Trie | 4 | Jan 11 – Feb 7 |

1. **Strings:** Reverse Words in a String; Longest Common Prefix; Isomorphic Strings; Valid Anagram; Sort Characters by Frequency; Longest Palindromic Substring.
2. **Linked List:** Middle of a Linked List; Reverse a Linked List (iterative); Reverse a Linked List (recursive); Detect a Loop in a Linked List; Starting Point of the Loop in a Linked List; Palindrome Linked List; Remove Nth Node From End of List; Intersection Point of Two Linked Lists; Add Two Numbers.
3. **Recursion & Backtracking:** Pow(x, n); Generate Parentheses; Power Set; Combination Sum; Subsets II; Letter Combinations of a Phone Number.
4. **Sliding Window & Two Pointer:** Longest Substring Without Repeating Characters; Max Consecutive Ones III; Fruit Into Baskets; Longest Repeating Character Replacement; Binary Subarrays With Sum; Maximum Points You Can Obtain from Cards.
5. **Stack & Queue:** Implement Stack and Queue using Arrays; Implement Queue using Stacks; Valid Parentheses; Min Stack; Next Greater Element; Next Greater Element II; Asteroid Collision; Online Stock Span.
6. **Heaps:** Implement a Min Heap; Kth Largest Element in an Array; Top K Frequent Elements; Kth Largest Element in a Stream.
7. **Greedy:** N Meetings in One Room; Jump Game; Minimum Number of Platforms; Job Sequencing Problem; Non-overlapping Intervals.
8. **Binary Trees:** Preorder, Inorder and Postorder Traversal; Level Order Traversal; Iterative Inorder Traversal; Maximum Depth of Binary Tree; Balanced Binary Tree; Diameter of Binary Tree; Same Tree; Symmetric Tree; Zigzag Level Order Traversal; Right and Left View of a Binary Tree; Lowest Common Ancestor of a Binary Tree; Maximum Width of Binary Tree.
9. **Binary Search Trees:** Search in a BST; Insert into a BST; Validate Binary Search Tree; Kth Smallest Element in a BST; Lowest Common Ancestor of a BST.
10. **Graphs:** graph representation and traversal (theory); Number of Provinces; Flood Fill; Number of Islands; Rotting Oranges; Detect a Cycle in an Undirected Graph; Is Graph Bipartite; Topological Sort (theory) + Course Schedule; Shortest Path in an Undirected Graph with Unit Weights; Dijkstra (theory) + Network Delay Time.
11. **Dynamic Programming:** Climbing Stairs; Frog Jump; House Robber; House Robber II; Unique Paths; Minimum Path Sum; Subset Sum Equal to Target; 0/1 Knapsack; Coin Change; Longest Common Subsequence; Longest Increasing Subsequence; Best Time to Buy and Sell Stock II.
12. **Bits & Trie:** Single Number; Count Set Bits; Power of Two; Implement Trie.

Pace check: 87 problems at 8 a week (5 a week during exams) ends about Feb 7; at 5.5 a week, about Feb 20. Either way it is done before the April window.

## Phase 2: the second layer (about Feb 8 – Mar 31)
- **High-frequency mediums parked from Phase 1:** Sort a Linked List; Delete the Middle Node of a Linked List; Rotate a Linked List; Copy List with Random Pointer; Combination Sum II; Word Search; Palindrome Partitioning; Count Number of Nice Subarrays; Number of Substrings Containing All Three Characters; LRU Cache; Remove K Digits; Sum of Subarray Minimums; Task Scheduler; Hand of Straights; Jump Game II; Insert Interval; Top View of a Binary Tree; Boundary Traversal of a Binary Tree; Construct Binary Tree from Preorder and Inorder; All Nodes Distance K in Binary Tree; Delete Node in a BST; Construct BST from Preorder; Two Sum IV (BST); 01 Matrix; Surrounded Regions; Number of Enclaves; Course Schedule II; Find Eventual Safe States; Shortest Path in Binary Matrix; Number of Operations to Make Network Connected; Triangle; Ninja's Training; Partition Equal Subset Sum; Coin Change II; Target Sum; Longest Palindromic Subsequence; Edit Distance.
- **Two timed test-style sets a week:** 2 problems in 60 minutes, mixed topics.
- **Re-solve every 🔴** from a blank file (Saturdays).

## Phase 3: from Apr 1 (drives first)
- **Campus drive days come first**, then company-tagged practice for the companies coming.
- **Parked Hards:** Median of Two Sorted Arrays; Book Allocation Problem; Split Array - Largest Sum; Count Inversions; Reverse Nodes in k-Group; N-Queens; Minimum Window Substring; Subarrays with K Different Integers; Trapping Rain Water; Largest Rectangle in Histogram; Sliding Window Maximum; Merge k Sorted Lists; Find Median from Data Stream; Candy; Binary Tree Maximum Path Sum; Vertical Order Traversal; Serialize and Deserialize Binary Tree; Word Ladder; Alien Dictionary; Cheapest Flights Within K Stops; Wildcard Matching; Distinct Subsequences; Burst Balloons; Matrix Chain Multiplication; Palindrome Partitioning II.
- **Low-level design** (object-oriented design) first; high-level system design basics later.
- **MAANG/NVIDIA gate:** Phase 1 and Phase 2 done, and the non-🔴 share of the last 20 new problems at 70% or more.

## CS subjects (evenings and Sundays only)
| When | Subject | Done when |
|---|---|---|
| Nov 16 – Dec 15 | none (end-semester exams) | — |
| Dec 16–31 | OOP revision (1–2 evenings), CN revision (1–2 evenings) | 20-question self-test at 70% or more, else one more evening |
| January | DBMS + SQL (about 2 weeks; 20–30 SQL queries) | self-test at 70% or more and the queries written |
| Early February | OS (about a week) | self-test at 70% or more |
| Jan – Mar | Aptitude, 20 minutes a day | — |
| March | One mixed multiple-choice mock a week (Sunday morning) | — |
