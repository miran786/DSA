# Problem Log

Miran's DSA problem log. Rules for filling it in (dates, Status, Level) are in `AGENTS.md`.


## Legend
- 🟢 **Solved alone** — You implemented without solution code
- 🟡 **Hints needed** — You needed hints (Rung 1, 2, 3)
- 🔴 **Solution given** — Full code was provided
- ⚠️ **Revisit** — Problems to practice again

| # | Problem | File | Signature | Technique | Status | Level | Started | Done |
|---|---------|------|-----------|-----------|--------|-------|---------|------|
| 1 | Check if String is Palindrome | `palindrome.cpp` | `bool isPalindrome(string s)` | two-pointer / string | ✅ solved — reversed-copy approach, O(n) space | 🟢 | — | — |
| 2 | Bubble Sort | `bubble_sort.cpp` | `void bubbleSort(vector<int> &arr)` | sorting | ✅ solved — O(n²) with early termination | 🟢 | — | — |
| 3 | Selection Sort | `selection_sort.cpp` | `void selectionSort(vector<int> &arr)` | sorting | ✅ fixed bugs — O(n²) min-finding (revisited 2026-10-24 — re-solved alone, `selection_sort_v2.cpp`) | 🟢 | — | — |
| 4 | Insertion Sort | `insertion_sort.cpp` | `void insertionSort(vector<int> &arr)` | sorting | ✅ solved — O(n²) with shifts | 🟢 | — | — |
| 5 | Merge Sort | `merge_sort.cpp` | `void mergeSort(vector<int> &arr)` | sorting / divide-conquer | ✅ solution provided — O(n log n) | 🔴 | — | — |
| 6 | Counting Frequencies | `counting_frequencies.cpp` | `vector<pair<int, int>> countFrequencies(vector<int> &nums)` | hashing | ✅ solved — map approach | 🟢 | — | — |
| 7 | Highest Occurring Element | `highest_occurring_element.cpp` | `int highestOccurringElement(vector<int> &nums)` | hashing | ✅ fixed bugs — two-variable tracking (revisited 2026-10-26 — `highest_occurring_element_v2.cpp`, tie-break bug found on check, fixed after rung 1–2; revisited 2026-11-08 — `highest_occurring_element_v3.cpp`, map counting) | 🟡 | — | 2026-11-08 |
| 8 | Search X in Sorted Array | `search_in_sorted_array.cpp` | `int searchInSortedArray(vector<int> &nums, int target)` | binary-search | ✅ solution provided — binary search O(log n) | 🔴 | — | — |
| 9 | Lower Bound | `lower_bound.cpp` | `int lowerBound(vector<int> &nums, int x)` | binary-search | ⚠️ In progress — needs fixes | ⚠️ | — | — |
| 10 | Upper Bound | `upper_bound.cpp` | `int upperBound(vector<int> &nums, int x)` | binary-search | ✅ solved (linear scan, not binary search yet) | 🟡 | — | — |
| 11 | Print All Divisors | `print_all_divisors.cpp` | `vector<int> printAllDivisors(int n)` | math | ✅ solved — O(n) loop | 🟢 | — | — |
| 12 | Check Prime Number | `check_prime.cpp` | `bool isPrime(int n)` | math | ✅ solution provided — O(√n) optimized | 🔴 | — | — |
| 13 | Recursive Bubble Sort | `recursive_bubble_sort.cpp` | `void recursiveBubbleSort(vector<int> &nums)` | sorting / recursion | ✅ fixed pass-by-reference bug | 🟡 | — | — |
| 14 | Recursive Insertion Sort | `recursive_insertion_sort.cpp` | `void recursiveInsertionSort(vector<int> &nums)` | sorting / recursion | ✅ solution provided — recursive insertion | 🔴 | — | — |
| 15 | Print 1 to N using Recursion | `print_1_to_n.cpp` | `void print1ToN(int n)` | recursion | ✅ solved — print after recursion | 🟢 | — | — |
| 16 | Print N to 1 using Recursion | `print_n_to_1.cpp` | `void printNTo1(int n)` | recursion | ✅ fixed order bug — print before recurse | 🟡 | — | — |
| 17 | Sum of First N Numbers | `sum_of_first_n.cpp` | `int sumOfFirstN(int n)` | recursion | ✅ fixed member variable — return value accumulation | 🟡 | — | — |
| 18 | Factorial of a Number | `factorial.cpp` | `long long factorial(int n)` | recursion | ✅ solved — multiply recursively | 🟢 | — | — |
| 19 | Fibonacci Number | `fibonacci.cpp` | `long long fibonacci(int n)` | recursion | ✅ solution provided — two recursive calls | 🔴 | — | — |
| 20 | Quick Sort | `quick_sort.cpp` | `void quickSort(vector<int> &nums)` | sorting / divide-conquer | ✅ solution provided — partition & recurse (needs revisit) | 🔴 | — | — |
| 21 | Search Insert Position | `search_insert_position.cpp` | `int searchInsert(vector<int> &nums, int target)` | binary-search | ✅ fixed `<` vs `<=` bug — lower-bound pattern | 🟡 | — | — |
| 22 | Floor and Ceil in Sorted Array | `floor_and_ceil.cpp` | `vector<int> getFloorAndCeil(vector<int> &nums, int x)` | binary-search | ✅ fixed bounds-check bug — two binary searches | 🟡 | — | — |
| 23 | First and Last Occurrence | `first_and_last_occurrence.cpp` | `vector<int> searchRange(vector<int> &nums, int target)` | binary-search | ✅ fixed out-of-bounds + low-vs-mid bugs — two binary searches | 🟡 | — | — |
| 24 | Count Occurrences in a Sorted Array | `count_occurrences.cpp` | `int countOccurrences(vector<int> &arr, int target)` | binary-search | ✅ fixed out-of-bounds guard — built on first/last occurrence | 🟡 | — | — |
| 25 | Search in Rotated Sorted Array-I | `search_rotated_sorted_array.cpp` | `int search(vector<int> &nums, int k)` | binary-search | ✅ solution provided — single loop, sorted-half detection | 🔴 | — | — |
| 26 | Search in Rotated Sorted Array-II | `search_rotated_sorted_array_ii.cpp` | `bool search(vector<int> &nums, int k)` | binary-search | ✅ solution provided — Rotated I + duplicate shrink | 🔴 | — | — |
| 27 | Find Minimum in Rotated Sorted Array | `find_min_rotated_sorted_array.cpp` | `int findMin(vector<int> &nums)` | binary-search | ✅ solution provided — compare mid with high | 🔴 | — | — |
| 28 | Count Rotations in Sorted Array | `count_rotations.cpp` | `int countRotations(vector<int> &nums)` | binary-search | ✅ fixed out-of-bounds `high` bug — returns index of min | 🟡 | — | — |
| 29 | Single Element in Sorted Array | `single_element_sorted_array.cpp` | `int singleNonDuplicate(vector<int> &nums)` | binary-search | ✅ solution provided — even-index pairing trick | 🔴 | — | — |
| 30 | Find Peak Element | `find_peak_element.cpp` | `int findPeakElement(vector<int> &arr)` | binary-search | ✅ O(n) version solved alone; O(log n) binary search solution provided after bugs | 🔴 | 2026-10-09 | 2026-10-09 |
| 31 | Find Square Root of a Number | `floor_sqrt.cpp` | `int floorSqrt(int n)` | binary-search | ✅ O(log n) binary search — solution provided after multiple return-value bugs | 🔴 | 2026-10-09 | 2026-10-09 |
| 32 | Find Nth root of a number | `nth_root.cpp` | `int NthRoot(int n, int m)` | binary-search | ✅ fixed `low<high` vs `low<=high` bug — O(log m) binary search (pow() float risk noted) | 🟡 | 2026-10-10 | 2026-10-10 |
| 33 | Koko Eating Bananas | `koko_eating_bananas.cpp` | `int minEatingSpeed(vector<int> &nums, int h)` | binary-search (on answer) | ✅ fixed ceiling-division + exact-match bugs — O(100n) linear scan (binary search on answer O(n log maxPile) still worth trying) | 🔴 | 2026-10-12 | 2026-10-12 |
| 34 | Minimum Days to make M Bouquets | `min_days_bouquets.cpp` | `int minDays(vector<int> &nums, int m, int k)` | binary-search (on answer) | ✅ solution provided — binary search over days + feasibility-check helper (first attempt drifted off-approach, had compile errors) | 🔴 | 2026-10-12 | 2026-10-15 |
| 35 | Find the Smallest Divisor | `smallest_divisor.cpp` | `int smallestDivisor(vector<int> &nums, int limit)` | binary-search (on answer) | ✅ solution provided — wrong search range, stale sum, ceiling-div, wrong return var | 🔴 | 2026-10-16 | 2026-10-16 |
| 36 | Capacity to Ship Packages Within D Days | `ship_packages_within_days.cpp` | `int shipWithinDays(vector<int> &weights, int days)` | binary-search (on answer) | ✅ solution provided — missing feasibility check + low/high update (good faith attempt on binary search shape and inner loop) | 🔴 | 2026-10-16 | 2026-10-16 |
| 37 | Kth Missing Positive Number | `kth_missing_positive.cpp` | `int findKthPositive(vector<int> &arr, int k)` | binary-search | ✅ fixed `<=` vs `<`, missing-count parens, out-of-bounds return — found the binary-search shape alone | 🟡 | 2026-10-22 | 2026-10-23 |
| 38 | Aggressive Cows | `aggressive_cows.cpp` | `int aggressiveCows(vector<int> &nums, int k)` | binary-search (on answer) | ✅ solution provided — binary search on the minimum distance + greedy placement check (re-code from a blank file) | 🔴 | 2026-10-24 | 2026-10-26 |
| 39 | Second Highest Occurring Element | `second_highest_occurring_element.cpp` | `int secondMostFrequent(vector<int> &arr)` | — | ⏳ In progress | — | 2026-10-26 | — |
| 40 | Book Allocation Problem | `book_allocation.cpp` | `int findPages(vector<int> &nums, int m)` | — | ⏳ In progress | — | 2026-10-27 | — |
| 41 | Linear Search | `linear_search.cpp` | `int linearSearch(vector<int> &nums, int target)` | array / linear scan | ✅ solved — O(n) scan, return first match | 🟢 | 2026-10-28 | 2026-10-28 |
| 42 | Largest Element | `largest_element.cpp` | `int largestElement(vector<int> &nums)` | array / linear scan | ✅ solved — O(n) running max, INT_MIN start | 🟢 | 2026-10-28 | 2026-10-28 |
| 43 | Second Largest Element | `second_largest_element.cpp` | `int secondLargestElement(vector<int> &nums)` | — | ✅ solution provided — missing else-if branch, INT_MIN sentinel leak (LLONG_MIN + `-1` when none) | 🔴 | 2026-10-28 | 2026-10-28 |
| 44 | Two Sum | `two_sum.cpp` | `vector<int> twoSum(vector<int> &nums, int target)` | — | ✅ solved — with hints | 🟡 | 2026-10-28 | 2026-10-30 |
| 45 | Maximum Consecutive Ones | `max_consecutive_ones.cpp` | `int findMaxConsecutiveOnes(vector<int>& nums)` | array / linear scan | ✅ solved — O(n) running count, reset on 0 | 🟢 | 2026-10-29 | 2026-10-29 |
| 46 | Left Rotate Array by One | `left_rotate_array_by_one.cpp` | `void leftRotateByOne(vector<int>& nums)` | array | ✅ solved — save first, shift left, write saved value to end; guard `size() > 1` | 🟡 | 2026-10-29 | 2026-10-29 |
| 47 | Left Rotate Array by K Places | `left_rotate_array_by_k.cpp` | `void leftRotateByK(vector<int>& nums, int k)` | array | ✅ solution provided — missing `k %= n` (k > n out-of-bounds, empty array guard); temp-copy off-by-one at write index fixed alone (re-code from a blank file) | 🔴 | 2026-10-30 | 2026-10-30 |
| 48 | Move Zeros to End | `move_zeros_to_end.cpp` | `void moveZerosToEnd(vector<int>& nums)` | array / two-pointer | ✅ fixed self-zeroing bug (`ptr == i`) — one pass, write pointer + zero the source slot | 🟡 | 2026-10-30 | 2026-10-30 |
| 49 | Remove Duplicates from Sorted Array | `remove_duplicates_from_sorted_array.cpp` | `int removeDuplicates(vector<int>& nums)` | array / two-pointer | ✅ solution provided — second loop overwrote values with indices; rewritten as one-pass write pointer | 🔴 | 2026-10-31 | 2026-10-31 |
| 50 | Find Missing Number | `find_missing_number.cpp` | `int missingNumber(vector<int> &nums)` | — | ✅ solved — expected sum minus actual sum, O(n) | 🟡 | 2026-11-01 | 2026-11-01 |

<!-- Add a row here every time a new problem file is created. Fill "Started" with today's date (YYYY-MM-DD); fill "Done" when it's solved. -->

---

---

# Summary & Revisit List

## Problems to Revisit (Needed Help)
**🔴 Solution Given (Learn & re-implement):**
- Merge Sort (#5) — understand divide-and-conquer
- Search X in Sorted Array (#8) — practice binary search
- Check Prime Number (#12) — O(√n) optimization
- Recursive Insertion Sort (#14) — complex recursion
- Fibonacci Number (#19) — two recursive calls pattern

**🟡 Hints Needed (Re-solve independently):**
- Selection Sort (#3) — algorithm correctness (revisited 2026-10-24)
- Highest Occurring Element (#7) — logic debugging (revisited 2026-10-26; revisited 2026-11-08 🟡)
- Recursive Bubble Sort (#13) — pass-by-reference
- Print N to 1 (#16) — order of operations in recursion
- Sum of First N (#17) — return vs. member variables

**⚠️ Incomplete:**
- Lower Bound (#9) — binary search variant
- Upper Bound (#10) — not started yet

## Strengths (Solved Alone 🟢)
✅ Palindrome, Bubble Sort, Insertion Sort, Counting Frequencies, Print All Divisors, Print 1 to N, Factorial

---
