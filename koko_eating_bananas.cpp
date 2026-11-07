#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minEatingSpeed(vector<int> &nums, int h) {
      for (int j = 1; j <= 100; j++)
      {
        long long total_hr = 0;

        for (int i = 0; i < nums.size(); i++)
        {
          // integer ceiling division: (a + b - 1) / b
          total_hr += (nums[i] + j - 1) / j;
        }

        if (total_hr <= h)
        {
          return j;   // first (smallest) speed that fits within h hours
        }
      }

      return -1;
    }
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> nums1 = {7, 15, 6, 3};
    int h1 = 8;
    cout << "Input: nums = [7, 15, 6, 3], h = " << h1 << endl;
    cout << "Output: " << obj.minEatingSpeed(nums1, h1) << endl;
    cout << "Expected: 5" << endl << endl;

    // Test Case 2
    vector<int> nums2 = {25, 12, 8, 14, 19};
    int h2 = 5;
    cout << "Input: nums = [25, 12, 8, 14, 19], h = " << h2 << endl;
    cout << "Output: " << obj.minEatingSpeed(nums2, h2) << endl;
    cout << "Expected: 25" << endl << endl;

    // Test Case 3 (edge: single pile, must finish in exactly 1 hour)
    vector<int> nums3 = {3};
    int h3 = 1;
    cout << "Input: nums = [3], h = " << h3 << endl;
    cout << "Output: " << obj.minEatingSpeed(nums3, h3) << endl;
    cout << "Expected: 3" << endl << endl;

    // Test Case 4 (edge: h equals pile size exactly, slowest rate of 1 works)
    vector<int> nums4 = {5};
    int h4 = 5;
    cout << "Input: nums = [5], h = " << h4 << endl;
    cout << "Output: " << obj.minEatingSpeed(nums4, h4) << endl;
    cout << "Expected: 1" << endl;

    return 0;
}
