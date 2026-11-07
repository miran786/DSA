#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findMin(vector<int> &nums) {
      int low = 0;
      int high = nums.size() - 1;

      // The minimum is the only element larger than its right neighbor
      // (or the last element). If mid > high, the minimum is to the right of mid.
      while (low < high)
      {
        int mid = low + (high - low) / 2;

        if (nums[mid] > nums[high])
        {
          low = mid + 1;
        }
        else
        {
          high = mid;
        }
      }

      return nums[low];
    }
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2, 3};
    cout << "Input: nums = [4, 5, 6, 7, 0, 1, 2, 3]" << endl;
    cout << "Output: " << obj.findMin(nums1) << endl;
    cout << "Expected: 0" << endl << endl;

    // Test Case 2
    vector<int> nums2 = {3, 4, 5, 1, 2};
    cout << "Input: nums = [3, 4, 5, 1, 2]" << endl;
    cout << "Output: " << obj.findMin(nums2) << endl;
    cout << "Expected: 1" << endl;

    return 0;
}
