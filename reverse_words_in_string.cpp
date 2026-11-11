#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string reverseWords(string s) {
      string reverse;
      int ptr = s.size()-1;

      for(int i = s.size()-1;i >=0;i--)
      {
        if (s[i] == ' ' || i == 0)
        {
          int start = (s[i] == ' ') ? i + 1 : i;
          if(start <= ptr)
          {
            if(!reverse.empty())
            {
              reverse.push_back(' ');
            }
            for(int j = start; j <= ptr; j++)
            {
              reverse.push_back(s[j]);
            }
          }
          ptr = i-1;
        }
      }
      return reverse;
    }
};

int main() {
    Solution obj;

    // Test Case 1
    string input1 = "welcome to the jungle";
    string output1 = obj.reverseWords(input1);
    cout << "Input: \"" << input1 << "\"" << endl;
    cout << "Output: \"" << output1 << "\"" << endl;
    cout << "Expected: \"jungle the to welcome\"" << endl << endl;

    // Test Case 2
    string input2 = " amazing coding skills ";
    string output2 = obj.reverseWords(input2);
    cout << "Input: \"" << input2 << "\"" << endl;
    cout << "Output: \"" << output2 << "\"" << endl;
    cout << "Expected: \"skills coding amazing\"" << endl << endl;

    // Edge Case 1: Single word
    string input3 = "hello";
    string output3 = obj.reverseWords(input3);
    cout << "Input: \"" << input3 << "\"" << endl;
    cout << "Output: \"" << output3 << "\"" << endl;
    cout << "Expected: \"hello\"" << endl << endl;

    // Edge Case 2: Two words
    string input4 = "a b";
    string output4 = obj.reverseWords(input4);
    cout << "Input: \"" << input4 << "\"" << endl;
    cout << "Output: \"" << output4 << "\"" << endl;
    cout << "Expected: \"b a\"" << endl << endl;

    // Edge Case 3: Multiple consecutive spaces
    string input5 = "hello    world";
    string output5 = obj.reverseWords(input5);
    cout << "Input: \"" << input5 << "\"" << endl;
    cout << "Output: \"" << output5 << "\"" << endl;
    cout << "Expected: \"world hello\"" << endl << endl;

    // Edge Case 4: Only spaces
    string input6 = "   ";
    string output6 = obj.reverseWords(input6);
    cout << "Input: \"" << input6 << "\"" << endl;
    cout << "Output: \"" << output6 << "\"" << endl;
    cout << "Expected: \"\"" << endl << endl;

    return 0;
}
