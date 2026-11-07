#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int searchInsert(vector<int> &nums, int target) {
      int low = 0;
      int high = nums.size()-1;
      while(low<=high)
      {
        int mid = low + (high - low) / 2;
        if(target <= nums[mid])
        {
          high = mid - 1;
        }
        else
        {
          low = mid +1;
        }

      }
      return low;
    }

};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> nums1 = {1, 3, 5, 6};
    int target1 = 5;
    cout << "Input: nums = [1, 3, 5, 6], target = " << target1 << endl;
    cout << "Output: " << obj.searchInsert(nums1, target1) << endl;
    cout << "Expected: 2" << endl << endl;

    // Test Case 2
    vector<int> nums2 = {1, 3, 5, 6};
    int target2 = 2;
    cout << "Input: nums = [1, 3, 5, 6], target = " << target2 << endl;
    cout << "Output: " << obj.searchInsert(nums2, target2) << endl;
    cout << "Expected: 1" << endl << endl;

    // Test Case 3
    vector<int> nums3 = {1, 3, 5, 6};
    int target3 = 7;
    cout << "Input: nums = [1, 3, 5, 6], target = " << target3 << endl;
    cout << "Output: " << obj.searchInsert(nums3, target3) << endl;
    cout << "Expected: 4" << endl;

    return 0;
}
