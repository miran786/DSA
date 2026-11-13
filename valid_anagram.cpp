#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isAnagram(string s, string t) {
      map <char,int> an;
      if(s.size() !=t.size())
      {
        return false;
      }
      for(char i : t)
      {
        an[i]++;
        //cout<<"an{i} is "<<an[i]<< endl;
      }
      for(char j : s)
      {
        if(an[j]==0)
        {
          return false;
        }
        else
        {
          an[j]--;
        }
      }
      return true;
    }
};

int main() {
    Solution obj;
    cout << boolalpha;

    // Test Case 1
    cout << "Input: s = \"anagram\", t = \"nagaram\"" << endl;
    cout << "Output: " << obj.isAnagram("anagram", "nagaram") << endl;
    cout << "Expected: true" << endl << endl;

    // Test Case 2
    cout << "Input: s = \"dog\", t = \"cat\"" << endl;
    cout << "Output: " << obj.isAnagram("dog", "cat") << endl;
    cout << "Expected: false" << endl << endl;

    // Test Case 3 (edge: both empty)
    cout << "Input: s = \"\", t = \"\"" << endl;
    cout << "Output: " << obj.isAnagram("", "") << endl;
    cout << "Expected: true" << endl << endl;

    // Test Case 4 (edge: single character, same)
    cout << "Input: s = \"a\", t = \"a\"" << endl;
    cout << "Output: " << obj.isAnagram("a", "a") << endl;
    cout << "Expected: true" << endl << endl;

    // Test Case 5 (edge: different lengths, one is a prefix of the other)
    cout << "Input: s = \"ab\", t = \"abc\"" << endl;
    cout << "Output: " << obj.isAnagram("ab", "abc") << endl;
    cout << "Expected: false" << endl << endl;

    // Test Case 6 (edge: same length, same letters, different counts)
    cout << "Input: s = \"aab\", t = \"abb\"" << endl;
    cout << "Output: " << obj.isAnagram("aab", "abb") << endl;
    cout << "Expected: false" << endl << endl;

    // Test Case 7 (edge: same length, shares some letters only)
    cout << "Input: s = \"rat\", t = \"car\"" << endl;
    cout << "Output: " << obj.isAnagram("rat", "car") << endl;
    cout << "Expected: false" << endl << endl;

    // Test Case 8 (edge: all characters identical)
    cout << "Input: s = \"aaaa\", t = \"aaaa\"" << endl;
    cout << "Output: " << obj.isAnagram("aaaa", "aaaa") << endl;
    cout << "Expected: true" << endl;

    return 0;
}
