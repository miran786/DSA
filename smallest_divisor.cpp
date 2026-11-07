#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int smallestDivisor(vector<int> &nums, int limit) {
      int low = 1;
      int high = *max_element(nums.begin(), nums.end());
      int ans = high;

      while (low <= high)
      {
        int mid = low + (high - low) / 2;

        long long sum = 0;   // reset fresh for THIS guess of mid
        for (auto i : nums)
        {
          sum += (i + mid - 1) / mid;   // integer ceiling division
        }

        if (sum <= limit)
        {
          ans = mid;      // mid works — remember it, try a smaller divisor
          high = mid - 1;
        }
        else
        {
          low = mid + 1;  // mid too small — sum too big, need a bigger divisor
        }
      }

      return ans;
    }
    
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> nums1 = {1, 2, 3, 4, 5};
    int limit1 = 8;
    cout << "Input: nums = [1, 2, 3, 4, 5], limit = " << limit1 << endl;
    cout << "Output: " << obj.smallestDivisor(nums1, limit1) << endl;
    cout << "Expected: 3" << endl << endl;

    // Test Case 2
    vector<int> nums2 = {8, 4, 2, 3};
    int limit2 = 10;
    cout << "Input: nums = [8, 4, 2, 3], limit = " << limit2 << endl;
    cout << "Output: " << obj.smallestDivisor(nums2, limit2) << endl;
    cout << "Expected: 2" << endl << endl;

    // Test Case 3 (edge: single element, limit large enough for divisor=1)
    vector<int> nums3 = {1};
    int limit3 = 1;
    cout << "Input: nums = [1], limit = " << limit3 << endl;
    cout << "Output: " << obj.smallestDivisor(nums3, limit3) << endl;
    cout << "Expected: 1" << endl << endl;

    // Test Case 4 (edge: limit as tight as possible, forces divisor = max element)
    vector<int> nums4 = {5};
    int limit4 = 1;
    cout << "Input: nums = [5], limit = " << limit4 << endl;
    cout << "Output: " << obj.smallestDivisor(nums4, limit4) << endl;
    cout << "Expected: 5" << endl;

    return 0;
}
