#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string longestPalindrome(string s) {
      //cout << "start0";
      string ans = s.substr(0, 1);
      
      if (s.size()==1)
      {
        ans = s[0];
        return ans;
      }
      for(int i = 0 ; i < s.size()-1;i++)
      {
        string forward;
        string reverse;
        //cout<<"start 1";
        for(int j = i+1 ; j < s.size(); j++)
        {
          forward.clear();
          reverse.clear();
          for(int k = i; k<= j; k++)
          {
            forward.push_back(s[k]) ;
          }
          for(int l = j; l>=i; l--)
          {
            reverse.push_back(s[l]);
          }
          if(forward == reverse && forward.size() > ans.size())
          {
            ans = forward;
          }
        }
        
      }
      return ans;
    }
};

int main() {
    Solution obj;

    // Test Case 1 (problem example 1)
    string s1 = "babad";
    cout << "Input: " << s1 << endl;
    cout << "Output: " << obj.longestPalindrome(s1) << endl;
    cout << "Expected: bab (or aba)" << endl << endl;

    // Test Case 2 (problem example 2)
    string s2 = "cbbd";
    cout << "Input: " << s2 << endl;
    cout << "Output: " << obj.longestPalindrome(s2) << endl;
    cout << "Expected: bb" << endl << endl;

    // Test Case 3 (edge: single character)
    string s3 = "a";
    cout << "Input: " << s3 << endl;
    cout << "Output: " << obj.longestPalindrome(s3) << endl;
    cout << "Expected: a" << endl << endl;

    // Test Case 4 (edge: all same characters)
    string s4 = "aaaa";
    cout << "Input: " << s4 << endl;
    cout << "Output: " << obj.longestPalindrome(s4) << endl;
    cout << "Expected: aaaa" << endl << endl;

    // Test Case 5 (edge: whole string is a palindrome, odd length)
    string s5 = "racecar";
    cout << "Input: " << s5 << endl;
    cout << "Output: " << obj.longestPalindrome(s5) << endl;
    cout << "Expected: racecar" << endl << endl;

    // Test Case 6 (edge: no palindrome longer than 1, any single char is valid)
    string s6 = "abc";
    cout << "Input: " << s6 << endl;
    cout << "Output: " << obj.longestPalindrome(s6) << endl;
    cout << "Expected: a (or b or c)" << endl << endl;

    // Test Case 7 (edge: even-length palindrome at the very end)
    string s7 = "xyzabba";
    cout << "Input: " << s7 << endl;
    cout << "Output: " << obj.longestPalindrome(s7) << endl;
    cout << "Expected: abba" << endl << endl;

    // Test Case 8 (edge: palindrome at the very start)
    string s8 = "abbaxyz";
    cout << "Input: " << s8 << endl;
    cout << "Output: " << obj.longestPalindrome(s8) << endl;
    cout << "Expected: abba" << endl << endl;

    // Test Case 9 (edge: palindrome in the middle, even length)
    string s9 = "forgeeksskeegfor";
    cout << "Input: " << s9 << endl;
    cout << "Output: " << obj.longestPalindrome(s9) << endl;
    cout << "Expected: geeksskeeg" << endl << endl;

    return 0;
}
