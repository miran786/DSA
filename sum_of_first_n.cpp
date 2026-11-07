#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int sumOfFirstN(int n) {
      if (n <= 0) {
        return 0;  // Base case
      }
      return n + sumOfFirstN(n - 1);  
    }
};

int main() {
    Solution obj;

    // Test Case 1
    int result1 = obj.sumOfFirstN(4);
    cout << "Input: n = 4" << endl;
    cout << "Output: " << result1 << endl;
    cout << "Expected: 10" << endl;
    cout << "Explanation: 1 + 2 + 3 + 4 = 10" << endl << endl;

    // Test Case 2
    int result2 = obj.sumOfFirstN(2);
    cout << "Input: n = 2" << endl;
    cout << "Output: " << result2 << endl;
    cout << "Expected: 3" << endl;
    cout << "Explanation: 1 + 2 = 3" << endl << endl;

    // Test Case 3
    int result3 = obj.sumOfFirstN(5);
    cout << "Input: n = 5" << endl;
    cout << "Output: " << result3 << endl;
    cout << "Expected: 15" << endl;
    cout << "Explanation: 1 + 2 + 3 + 4 + 5 = 15" << endl;

    return 0;
}
