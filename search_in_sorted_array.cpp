#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int searchInSortedArray(vector<int> &nums, int target) {
      int left = 0;
      int right = nums.size() - 1;

      while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
          return mid;
        }
        else if (nums[mid] < target) {
          left = mid + 1;
        }
        else {
          right = mid - 1;
        }
      }

      return -1;
    }
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> nums1 = {-1, 0, 3, 5, 9, 12};
    int target1 = 9;
    cout << "Input: nums = [-1, 0, 3, 5, 9, 12], target = " << target1 << endl;
    cout << "Output: " << obj.searchInSortedArray(nums1, target1) << endl;
    cout << "Expected: 4" << endl << endl;

    // Test Case 2
    vector<int> nums2 = {-1, 0, 3, 5, 9, 12};
    int target2 = 2;
    cout << "Input: nums = [-1, 0, 3, 5, 9, 12], target = " << target2 << endl;
    cout << "Output: " << obj.searchInSortedArray(nums2, target2) << endl;
    cout << "Expected: -1" << endl << endl;

    // Test Case 3
    vector<int> nums3 = {-1, 0, 3, 5, 9, 12};
    int target3 = -1;
    cout << "Input: nums = [-1, 0, 3, 5, 9, 12], target = " << target3 << endl;
    cout << "Output: " << obj.searchInSortedArray(nums3, target3) << endl;
    cout << "Expected: 0" << endl;

    return 0;
}
