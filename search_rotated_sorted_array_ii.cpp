#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool search(vector<int> &nums, int k) {
      int low = 0;
      int high = nums.size() - 1;

      while (low <= high)
      {
        int mid = low + (high - low) / 2;

        if (nums[mid] == k)
        {
          return true;
        }

        // Duplicates hide which half is sorted: shrink both ends
        if (nums[low] == nums[mid] && nums[mid] == nums[high])
        {
          low++;
          high--;
          continue;
        }

        // Left half [low..mid] is sorted
        if (nums[low] <= nums[mid])
        {
          if (nums[low] <= k && k < nums[mid])
          {
            high = mid - 1;
          }
          else
          {
            low = mid + 1;
          }
        }
        // Right half [mid..high] is sorted
        else
        {
          if (nums[mid] < k && k <= nums[high])
          {
            low = mid + 1;
          }
          else
          {
            high = mid - 1;
          }
        }
      }

      return false;
    }
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> nums1 = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int k1 = 3;
    cout << "Input: nums = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = " << k1 << endl;
    cout << "Output: " << (obj.search(nums1, k1) ? "true" : "false") << endl;
    cout << "Expected: true" << endl << endl;

    // Test Case 2
    vector<int> nums2 = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int k2 = 10;
    cout << "Input: nums = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = " << k2 << endl;
    cout << "Output: " << (obj.search(nums2, k2) ? "true" : "false") << endl;
    cout << "Expected: false" << endl;

    return 0;
}
