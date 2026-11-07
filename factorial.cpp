#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long factorial(int n) {
      if(n <= 0 )
      {
        return 1 ;
      }

      return n * factorial(n-1);
    }
};

int main() {
    Solution obj;

    // Test Case 1
    long long result1 = obj.factorial(2);
    cout << "Input: n = 2" << endl;
    cout << "Output: " << result1 << endl;
    cout << "Expected: 2" << endl;
    cout << "Explanation: 2! = 1 * 2 = 2" << endl << endl;

    // Test Case 2
    long long result2 = obj.factorial(0);
    cout << "Input: n = 0" << endl;
    cout << "Output: " << result2 << endl;
    cout << "Expected: 1" << endl;
    cout << "Explanation: 0! = 1 (by definition)" << endl << endl;

    // Test Case 3
    long long result3 = obj.factorial(3);
    cout << "Input: n = 3" << endl;
    cout << "Output: " << result3 << endl;
    cout << "Expected: 6" << endl;
    cout << "Explanation: 3! = 1 * 2 * 3 = 6" << endl << endl;

    // Test Case 4
    long long result4 = obj.factorial(5);
    cout << "Input: n = 5" << endl;
    cout << "Output: " << result4 << endl;
    cout << "Expected: 120" << endl;
    cout << "Explanation: 5! = 1 * 2 * 3 * 4 * 5 = 120" << endl;

    return 0;
}
