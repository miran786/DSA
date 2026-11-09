#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isomorphicString(string s, string t) {
        map<char,char> alpha;
        map<char,char> rev;

        for(int i = 0; i < s.size();i++)
        {
            if(alpha[s[i]]==0)
            {
                alpha[s[i]]=t[i];
            }
            if(rev[t[i]]==0)
            {
                rev[t[i]]=s[i];
            }
            if(alpha[s[i]]!=t[i] || rev[t[i]]!=s[i])
            {
                return false;
            }
        }
        return true;
    }
};

void run(Solution &obj, string s, string t, bool expected) {
    cout << "Input: s = \"" << s << "\", t = \"" << t << "\"" << endl;
    cout << "Output: " << boolalpha << obj.isomorphicString(s, t) << endl;
    cout << "Expected: " << boolalpha << expected << endl << endl;
}

int main() {
    Solution obj;

    // Test Case 1: Example 1
    run(obj, "egg", "add", true);

    // Test Case 2: Example 2
    run(obj, "apple", "bbnbm", false);

    // Test Case 3: single character
    run(obj, "a", "b", true);

    // Test Case 4: character maps to itself
    run(obj, "abc", "abc", true);

    // Test Case 5: two different chars in s map to the same char in t
    run(obj, "ab", "aa", false);

    // Test Case 6: one char in s would need to map to two different chars in t
    run(obj, "aa", "ab", false);

    // Test Case 7: longer valid mapping
    run(obj, "paper", "title", true);

    // Test Case 8: mapping breaks late in the string
    run(obj, "badc", "baba", false);

    // Test Case 9: all same characters on both sides
    run(obj, "zzzz", "yyyy", true);

    // Test Case 10: digits and symbols
    run(obj, "13!1", "42?4", true);

    return 0;
}
