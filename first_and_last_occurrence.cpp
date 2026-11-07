#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> searchRange(vector<int> &nums, int target) {
      int low = 0;
      int high = nums.size()-1;
      int firstoccurance_index = -1, last_occurance_index = -1;
      while (low<=high)
      {
        int mid = low +(high-low)/2;

        if(nums[mid] < target)
        {
          low = mid +1;
        }
        else
        {
          high = mid -1;
        }

        if(nums[mid] == target)
        {
          firstoccurance_index = mid;
        }
      }
      
      low = 0;
      high = nums.size()-1;

      while (low<=high)
      {
        int mid = low +(high-low)/2;

        if(nums[mid] > target)
        {
          high = mid - 1;
        }
        else
        {
          low = mid + 1;
        }

        if(nums[mid] == target)
        {
          last_occurance_index = mid;
        }
      }

      return {firstoccurance_index,last_occurance_index};
    }
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> nums1 = {5, 7, 7, 8, 8, 10};
    int target1 = 8;
    vector<int> result1 = obj.searchRange(nums1, target1);
    cout << "Input: nums = [5, 7, 7, 8, 8, 10], target = " << target1 << endl;
    cout << "Output: [" << result1[0] << ", " << result1[1] << "]" << endl;
    cout << "Expected: [3, 4]" << endl << endl;

    // Test Case 2
    vector<int> nums2 = {5, 7, 7, 8, 8, 10};
    int target2 = 6;
    vector<int> result2 = obj.searchRange(nums2, target2);
    cout << "Input: nums = [5, 7, 7, 8, 8, 10], target = " << target2 << endl;
    cout << "Output: [" << result2[0] << ", " << result2[1] << "]" << endl;
    cout << "Expected: [-1, -1]" << endl;

    return 0;
}
