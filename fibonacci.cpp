#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long fibonacci(int n) {
      // Base cases
      if (n == 0) return 0;
      if (n == 1) return 1;

      // Recursive case: sum of two previous Fibonacci numbers
      return fibonacci(n - 2) + fibonacci(n - 1);
    }
};

int main() {
    Solution obj;

    // Test Case 1
    long long result1 = obj.fibonacci(2);
    cout << "Input: n = 2" << endl;
    cout << "Output: " << result1 << endl;
    cout << "Expected: 1" << endl;
    cout << "Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1" << endl << endl;

    // Test Case 2
    long long result2 = obj.fibonacci(3);
    cout << "Input: n = 3" << endl;
    cout << "Output: " << result2 << endl;
    cout << "Expected: 2" << endl;
    cout << "Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2" << endl << endl;

    // Test Case 3
    long long result3 = obj.fibonacci(6);
    cout << "Input: n = 6" << endl;
    cout << "Output: " << result3 << endl;
    cout << "Expected: 8" << endl;
    cout << "Explanation: F(6) = F(5) + F(4) = 5 + 3 = 8" << endl << endl;

    // Test Case 4
    long long result4 = obj.fibonacci(0);
    cout << "Input: n = 0" << endl;
    cout << "Output: " << result4 << endl;
    cout << "Expected: 0" << endl;
    cout << "Explanation: F(0) = 0 (base case)" << endl;

    return 0;
}
