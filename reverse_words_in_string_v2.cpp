#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string reverseWords(string s) {
      string rev;
      
      
       
    }
};

int main() {
    Solution obj;

    // Test Case 1 (problem example 1)
    string s1 = "the sky is blue";
    cout << "Input: " << s1 << endl;
    cout << "Output: " << obj.reverseWords(s1) << endl;
    cout << "Expected: blue is sky the" << endl << endl;

    // Test Case 2 (problem example 2: leading and trailing spaces)
    string s2 = "  hello world  ";
    cout << "Input: " << s2 << endl;
    cout << "Output: " << obj.reverseWords(s2) << endl;
    cout << "Expected: world hello" << endl << endl;

    // Test Case 3 (problem example 3: multiple spaces between words)
    string s3 = "a good   example";
    cout << "Input: " << s3 << endl;
    cout << "Output: " << obj.reverseWords(s3) << endl;
    cout << "Expected: example good a" << endl << endl;

    // Test Case 4 (edge: single word, no spaces)
    string s4 = "hello";
    cout << "Input: " << s4 << endl;
    cout << "Output: " << obj.reverseWords(s4) << endl;
    cout << "Expected: hello" << endl << endl;

    // Test Case 5 (edge: single character)
    string s5 = "a";
    cout << "Input: " << s5 << endl;
    cout << "Output: " << obj.reverseWords(s5) << endl;
    cout << "Expected: a" << endl << endl;

    // Test Case 6 (edge: two words, single space)
    string s6 = "ab cd";
    cout << "Input: " << s6 << endl;
    cout << "Output: " << obj.reverseWords(s6) << endl;
    cout << "Expected: cd ab" << endl << endl;

    // Test Case 7 (edge: many spaces on both ends and between words)
    string s7 = "   one    two   ";
    cout << "Input: " << s7 << endl;
    cout << "Output: " << obj.reverseWords(s7) << endl;
    cout << "Expected: two one" << endl << endl;

    // Test Case 8 (edge: only spaces, no words)
    string s8 = "     ";
    cout << "Input: " << s8 << endl;
    cout << "Output: [" << obj.reverseWords(s8) << "]" << endl;
    cout << "Expected: []" << endl << endl;

    return 0;
}
