#include <bits/stdc++.h>
using namespace std;
//A prime number (or a prime) is a natural number greater than 1 that is not a product of two smaller natural numbers. 
class Solution {
  public:
    bool isPrime(int n) {                                             
      // Numbers <= 1 are not prime
      if (n <= 1) return false;

      // 2 is the only even prime
      if (n == 2) return true;

      // All other even numbers are not prime
      if (n % 2 == 0) return false;

      // Check odd divisors from 3 to sqrt(n)
      for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
      }

      return true;
    }
};

int main() {
    Solution obj;

    // Test Case 1
    int num1 = 7;
    cout << "Input: n = " << num1 << endl;
    cout << "Output: " << (obj.isPrime(num1) ? "true" : "false") << endl;
    cout << "Expected: true" << endl << endl;

    // Test Case 2
    int num2 = 10;
    cout << "Input: n = " << num2 << endl;
    cout << "Output: " << (obj.isPrime(num2) ? "true" : "false") << endl;
    cout << "Expected: false" << endl << endl;

    // Test Case 3
    int num3 = 2;
    cout << "Input: n = " << num3 << endl;
    cout << "Output: " << (obj.isPrime(num3) ? "true" : "false") << endl;
    cout << "Expected: true" << endl << endl;

    // Test Case 4
    int num4 = 1;
    cout << "Input: n = " << num4 << endl;
    cout << "Output: " << (obj.isPrime(num4) ? "true" : "false") << endl;
    cout << "Expected: false" << endl;

    return 0;
}
