#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int floorSqrt(int n) {
      int low = 0;
      int high = n;
      int ans = 0;   // best valid candidate found so far

      while (low <= high)
      {
        int mid = low + (high - low) / 2;
        long long value = (long long)mid * mid;

        if (value == n)
        {
          return mid;
        }

        if (value < n)
        {
          ans = mid;       // mid is valid — remember it
          low = mid + 1;   // search right for a possibly bigger valid one
        }
        else
        {
          high = mid - 1;  // mid is too big — search left
        }
      }

      return ans;
    }
};

int main() {
    Solution obj;

    // Test Case 1
    int n1 = 36;
    cout << "Input: n = " << n1 << endl;
    cout << "Output: " << obj.floorSqrt(n1) << endl;
    cout << "Expected: 6" << endl << endl;

    // Test Case 2
    int n2 = 28;
    cout << "Input: n = " << n2 << endl;
    cout << "Output: " << obj.floorSqrt(n2) << endl;
    cout << "Expected: 5" << endl << endl;

    // Test Case 3
    int n3 = 1;
    cout << "Input: n = " << n3 << endl;
    cout << "Output: " << obj.floorSqrt(n3) << endl;
    cout << "Expected: 1" << endl << endl;

    // Test Case 4
    int n4 = 2;
    cout << "Input: n = " << n4 << endl;
    cout << "Output: " << obj.floorSqrt(n4) << endl;
    cout << "Expected: 1" << endl;

    return 0;
}
