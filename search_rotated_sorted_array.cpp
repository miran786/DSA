#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int search(vector<int> &nums, int k) {
      int low = 0;
      int high = nums.size()-1;

      while (low <= high)
      {
        int mid = low + (high - low) / 2;

        if (nums[mid] == k)
        {
          return mid;
        }

        // Figure out which half is properly sorted
        if (nums[low] <= nums[mid])
        {
          // Left half [low..mid] is sorted
          if (nums[low] <= k && k < nums[mid])
          {
            high = mid - 1;   // k is within the sorted left half
          }
          else
          {
            low = mid + 1;    // k must be in the right half
          }
        }
        else
        {
          // Right half [mid..high] is sorted
          if (nums[mid] < k && k <= nums[high])
          {
            low = mid + 1;    // k is within the sorted right half
          }
          else
          {
            high = mid - 1;   // k must be in the left half
          }
        }
      }

      return -1;
    }
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    int k1 = 0;
    cout << "Input: nums = [4, 5, 6, 7, 0, 1, 2], k = " << k1 << endl;
    cout << "Output: " << obj.search(nums1, k1) << endl;
    cout << "Expected: 4" << endl << endl;

    // Test Case 2
    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    int k2 = 3;
    cout << "Input: nums = [4, 5, 6, 7, 0, 1, 2], k = " << k2 << endl;
    cout << "Output: " << obj.search(nums2, k2) << endl;
    cout << "Expected: -1" << endl << endl;

    // Test Case 3
    vector<int> nums3 = {5, 6, 0, 1, 2, 3, 4};
    int k3 = 0;
    cout << "Input: nums = [4, 5, 6, 7, 0, 1, 2], k = " << k3 << endl;
    cout << "Output: " << obj.search(nums3, k3) << endl;
    cout << "Expected: 2" << endl;

    return 0;
}
