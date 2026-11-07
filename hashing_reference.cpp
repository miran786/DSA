// ============================================================
//  BASIC HASHING — REFERENCE FILE
//  Not a problem to solve. Compile it, run it, read the output,
//  then change things and re-run to see what breaks.
//
//    g++ hashing_reference.cpp -o hashing_reference.exe
//    .\hashing_reference.exe
// ============================================================

#include <bits/stdc++.h>
using namespace std;

int main() {

    // ========================================================
    // 1. FREQUENCY ARRAY  — fastest, but only for small ranges
    // ========================================================
    // Use when you know the values are small (say 0..1000).
    // The value itself is the index. O(1) lookup, no overhead.

    cout << "--- 1. Frequency array ---\n";

    int arr[] = {1, 3, 2, 1, 3, 3};
    int n = 6;

    int freq[10] = {0};              // must init to 0, else garbage
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;              // value -> index
    }

    cout << "count of 1 = " << freq[1] << "\n";
    cout << "count of 3 = " << freq[3] << "\n";
    cout << "count of 9 = " << freq[9] << "\n";   // never appeared, still 0

    // Limits: freq[1000000] blows the stack. Negative values crash it.
    // When the range is big or unknown, use a map instead.


    // ========================================================
    // 2. CHARACTER HASHING — frequency array, sized 26 or 256
    // ========================================================

    cout << "\n--- 2. Character hashing ---\n";

    string s = "abcdabefc";

    int chFreq[26] = {0};
    for (int i = 0; i < s.size(); i++) {
        chFreq[s[i] - 'a']++;        // 'a'->0, 'b'->1, ... 'z'->25
    }

    cout << "count of 'a' = " << chFreq['a' - 'a'] << "\n";
    cout << "count of 'c' = " << chFreq['c' - 'a'] << "\n";
    cout << "count of 'z' = " << chFreq['z' - 'a'] << "\n";

    // Only works for lowercase. For mixed case / digits / symbols,
    // use size 256 and index by the raw char:
    int allChars[256] = {0};
    string mixed = "aAbB1!";
    for (int i = 0; i < mixed.size(); i++) {
        allChars[(int)mixed[i]]++;
    }
    cout << "count of 'A' = " << allChars[(int)'A'] << "\n";
    cout << "count of '!' = " << allChars[(int)'!'] << "\n";


    // ========================================================
    // 3. map<int,int> — sorted keys, O(log n) per operation
    // ========================================================

    cout << "\n--- 3. map (sorted) ---\n";

    map<int, int> mp;
    int big[] = {1000000, 5, 1000000, 5, 7};
    for (int i = 0; i < 5; i++) {
        mp[big[i]]++;                // missing key auto-creates with 0, then ++
    }

    for (auto it : mp) {             // always comes out in sorted key order
        cout << it.first << " -> " << it.second << "\n";
    }

    cout << "count of 5       = " << mp[5] << "\n";
    cout << "count of 999 = " << mp[999] << "\n";   // returns 0 ...


    // ========================================================
    // 4. THE TRAP — mp[x] on a missing key INSERTS it
    // ========================================================

    cout << "\n--- 4. The [] trap ---\n";

    cout << "map size before reading mp[424242] : " << mp.size() << "\n";
    int v = mp[424242];              // just a read... but it inserts {424242, 0}
    cout << "map size after  reading mp[424242] : " << mp.size() << "\n";

    // Read without inserting — use .count() or .find()
    if (mp.count(555)) {
        cout << "555 is present\n";
    } else {
        cout << "555 not present (and was NOT inserted)\n";
    }
    cout << "map size still : " << mp.size() << "\n";


    // ========================================================
    // 5. unordered_map — O(1) average, but NO order
    // ========================================================

    cout << "\n--- 5. unordered_map ---\n";

    unordered_map<int, int> ump;
    for (int i = 0; i < n; i++) {
        ump[arr[i]]++;
    }

    for (auto it : ump) {            // order is arbitrary — do not rely on it
        cout << it.first << " -> " << it.second << "\n";
    }

    // Default to unordered_map. Switch to map only when you need sorted keys.
    // (unordered_map is O(n) worst case on adversarial input; rare in practice.)


    // ========================================================
    // 6. COMMON PATTERN — highest / lowest frequency element
    // ========================================================

    cout << "\n--- 6. Highest frequency ---\n";

    int bestVal = -1, bestCount = 0;
    for (auto it : ump) {
        if (it.second > bestCount) {
            bestCount = it.second;
            bestVal = it.first;
        }
    }
    cout << bestVal << " appears " << bestCount << " times\n";


    // ========================================================
    // 7. set — membership only, no counts
    // ========================================================

    cout << "\n--- 7. set ---\n";

    set<int> st;                     // unordered_set for O(1), set for sorted
    for (int i = 0; i < n; i++) st.insert(arr[i]);

    cout << "distinct values: " << st.size() << "\n";
    cout << "contains 3? " << (st.count(3) ? "yes" : "no") << "\n";


    // ========================================================
    //  CHEAT SHEET
    // ========================================================
    //
    //  small known range of ints   ->  int freq[N] = {0}
    //  lowercase letters           ->  int freq[26], index s[i]-'a'
    //  any char                    ->  int freq[256], index (int)s[i]
    //  big / unknown / negative    ->  unordered_map<int,int>
    //  need keys in sorted order   ->  map<int,int>
    //  only "is it there?"         ->  unordered_set / set
    //
    //  build   :  mp[x]++
    //  read    :  mp[x]              (careful: inserts if missing)
    //  safe    :  mp.count(x)        (does not insert)
    //  iterate :  for (auto it : mp) { it.first, it.second }
    //
    //  Building the hash is O(n) once. Every query after is O(1).
    //  That is the whole point — pay once, answer Q queries free.

    return 0;
}
