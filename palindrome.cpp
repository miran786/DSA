#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isPalindrome(string s) {
      int n = s.length();
      string reverse =s;
      for (int i = 0; i < n/2; i++)
      {
        swap(reverse[i],reverse[n-1-i]);

      }
      
      if(reverse==s)
      {
        return true;
      }
      else
      {
        return false;
      }
      
    }
};

int main() {
    Solution obj;

    // Test Case 1
    string s1 = "hannah";
    cout << "Input: " << s1 << endl;
    cout << "Output: " << (obj.isPalindrome(s1) ? "true" : "false") << endl;
    cout << "Expected: true" << endl << endl;

    // Test Case 2
    string s2 = "aabbaA";
    cout << "Input: " << s2 << endl;
    cout << "Output: " << (obj.isPalindrome(s2) ? "true" : "false") << endl;
    cout << "Expected: false" << endl << endl;

    // Test Case 3
    string s3 = "aabbcccdbbaa";
    cout << "Input: " << s3 << endl;
    cout << "Output: " << (obj.isPalindrome(s3) ? "true" : "false") << endl;
    cout << "Expected: true" << endl;

    return 0;
}
