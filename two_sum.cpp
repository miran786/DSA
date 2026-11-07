#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
      vector<int> num;
     
      for (int i = 0; i < nums.size(); i++)
      {
        for (int j = i+1; j < nums.size(); j++)
        {
          if(nums[i]+nums[j]==target)
          {
            num.push_back(i);
            num.push_back(j);
            return num;
          }
        }
        
      }
  
     return num;
      

    }
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> nums1 = {1, 6, 2, 10, 3};
    cout << "Input: nums = [1, 6, 2, 10, 3], target = 7" << endl;
    cout << "Output: [" << obj.twoSum(nums1, 7)[0] << ", " << obj.twoSum(nums1, 7)[1] << "]" << endl;
    cout << "Expected: [0, 1]" << endl << endl;

    // Test Case 2
    vector<int> nums2 = {1, 3, 5, -7, 6, -3};
    cout << "Input: nums = [1, 3, 5, -7, 6, -3], target = 0" << endl;
    cout << "Output: [" << obj.twoSum(nums2, 0)[0] << ", " << obj.twoSum(nums2, 0)[1] << "]" << endl;
    cout << "Expected: [1, 5]" << endl << endl;

    // Test Case 3 (Now your turn)
    vector<int> nums3 = {-6, 7, 1, -7, 6, 2};
    cout << "Input: nums = [-6, 7, 1, -7, 6, 2], target = 3" << endl;
    cout << "Output: [" << obj.twoSum(nums3, 3)[0] << ", " << obj.twoSum(nums3, 3)[1] << "]" << endl;
    cout << "Expected: [2, 5]" << endl << endl;

    // Test Case 4 (edge: duplicate values forming the pair)
    vector<int> nums4 = {3, 3};
    cout << "Input: nums = [3, 3], target = 6" << endl;
    cout << "Output: [" << obj.twoSum(nums4, 6)[0] << ", " << obj.twoSum(nums4, 6)[1] << "]" << endl;
    cout << "Expected: [0, 1]" << endl << endl;

    // Test Case 5 (edge: pair uses the very first and very last index)
    vector<int> nums5 = {1, 4, 6, 9, 2};
    cout << "Input: nums = [1, 4, 6, 9, 2], target = 10" << endl;
    cout << "Output: [" << obj.twoSum(nums5, 10)[0] << ", " << obj.twoSum(nums5, 10)[1] << "]" << endl;
    cout << "Expected: [0, 3]" << endl << endl;

    // Test Case 6 (edge: negative numbers, target 0)
    vector<int> nums6 = {-3, 4, 3, 90};
    cout << "Input: nums = [-3, 4, 3, 90], target = 0" << endl;
    cout << "Output: [" << obj.twoSum(nums6, 0)[0] << ", " << obj.twoSum(nums6, 0)[1] << "]" << endl;
    cout << "Expected: [0, 2]" << endl << endl;

    // Test Case 7 (edge: pair ends at the last index)
    vector<int> nums7 = {1, 2, 3, 8};
    cout << "Input: nums = [1, 2, 3, 8], target = 11" << endl;
    cout << "Output: [" << obj.twoSum(nums7, 11)[0] << ", " << obj.twoSum(nums7, 11)[1] << "]" << endl;
    cout << "Expected: [2, 3]" << endl;

    return 0;
}
