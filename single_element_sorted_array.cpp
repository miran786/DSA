#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int singleNonDuplicate(vector<int> &nums) {
      int low = 0;
      int high = nums.size() - 1;

      while (low < high)
      {
        int mid = low + (high - low) / 2;

        // Force mid to be even, so its expected pair partner is mid+1
        if (mid % 2 == 1)
        {
          mid--;
        }

        if (nums[mid] == nums[mid + 1])
        {
          // Pair is intact — single element is after this pair
          low = mid + 2;
        }
        else
        {
          // Pair is broken — single element is at mid or before
          high = mid;
        }
      }

      return nums[low];
    }
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> nums1 = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    cout << "Input: nums = [1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6]" << endl;
    cout << "Output: " << obj.singleNonDuplicate(nums1) << endl;
    cout << "Expected: 4" << endl << endl;

    // Test Case 2
    vector<int> nums2 = {1, 1, 3, 5, 5};
    cout << "Input: nums = [1, 1, 3, 5, 5]" << endl;
    cout << "Output: " << obj.singleNonDuplicate(nums2) << endl;
    cout << "Expected: 3" << endl;

    return 0;
}
