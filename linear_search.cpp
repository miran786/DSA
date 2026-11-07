#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int linearSearch(vector<int> &nums, int target) {
      for(int i=0 ; i < nums.size(); i++)
      {
        if(nums[i] == target)
        {
          return i;
        }
      }
      return -1;
    }
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> nums1 = {2, 3, 4, 5, 3};
    int target1 = 3;
    cout << "Input: nums = [2, 3, 4, 5, 3], target = " << target1 << endl;
    cout << "Output: " << obj.linearSearch(nums1, target1) << endl;
    cout << "Expected: 1" << endl << endl;

    // Test Case 2
    vector<int> nums2 = {2, -4, 4, 0, 10};
    int target2 = 6;
    cout << "Input: nums = [2, -4, 4, 0, 10], target = " << target2 << endl;
    cout << "Output: " << obj.linearSearch(nums2, target2) << endl;
    cout << "Expected: -1" << endl << endl;

    // Test Case 3 (edge: empty array)
    vector<int> nums3 = {};
    int target3 = 5;
    cout << "Input: nums = [], target = " << target3 << endl;
    cout << "Output: " << obj.linearSearch(nums3, target3) << endl;
    cout << "Expected: -1" << endl << endl;

    // Test Case 4 (edge: single element, found)
    vector<int> nums4 = {7};
    int target4 = 7;
    cout << "Input: nums = [7], target = " << target4 << endl;
    cout << "Output: " << obj.linearSearch(nums4, target4) << endl;
    cout << "Expected: 0" << endl << endl;

    // Test Case 5 (edge: single element, not found)
    vector<int> nums5 = {7};
    int target5 = 8;
    cout << "Input: nums = [7], target = " << target5 << endl;
    cout << "Output: " << obj.linearSearch(nums5, target5) << endl;
    cout << "Expected: -1" << endl << endl;

    // Test Case 6 (edge: target at the very first index)
    vector<int> nums6 = {9, 1, 2, 3};
    int target6 = 9;
    cout << "Input: nums = [9, 1, 2, 3], target = " << target6 << endl;
    cout << "Output: " << obj.linearSearch(nums6, target6) << endl;
    cout << "Expected: 0" << endl << endl;

    // Test Case 7 (edge: target at the very last index)
    vector<int> nums7 = {1, 2, 3, 9};
    int target7 = 9;
    cout << "Input: nums = [1, 2, 3, 9], target = " << target7 << endl;
    cout << "Output: " << obj.linearSearch(nums7, target7) << endl;
    cout << "Expected: 3" << endl << endl;

    // Test Case 8 (edge: all elements equal the target)
    vector<int> nums8 = {4, 4, 4, 4};
    int target8 = 4;
    cout << "Input: nums = [4, 4, 4, 4], target = " << target8 << endl;
    cout << "Output: " << obj.linearSearch(nums8, target8) << endl;
    cout << "Expected: 0" << endl << endl;

    // Test Case 9 (edge: negative target, repeated)
    vector<int> nums9 = {5, -3, 8, -3};
    int target9 = -3;
    cout << "Input: nums = [5, -3, 8, -3], target = " << target9 << endl;
    cout << "Output: " << obj.linearSearch(nums9, target9) << endl;
    cout << "Expected: 1" << endl;

    return 0;
}
