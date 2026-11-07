#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int upperBound(vector<int> &nums, int x) {

      for(int i = 0;i< nums.size(); i++)
      {
        if(nums[i] > x)
        {
          return i;
        }
      }

      return nums.size();

    }
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> nums1 = {1, 2, 2, 3};
    int x1 = 2;
    cout << "Input: nums = [1, 2, 2, 3], x = " << x1 << endl;
    cout << "Output: " << obj.upperBound(nums1, x1) << endl;
    cout << "Expected: 3" << endl << endl;

    // Test Case 2
    vector<int> nums2 = {3, 5, 8, 15, 19};
    int x2 = 9;
    cout << "Input: nums = [3, 5, 8, 15, 19], x = " << x2 << endl;
    cout << "Output: " << obj.upperBound(nums2, x2) << endl;
    cout << "Expected: 3" << endl << endl;

    // Test Case 3
    vector<int> nums3 = {3, 5, 8, 15, 19};
    int x3 = 3;
    cout << "Input: nums = [3, 5, 8, 15, 19], x = " << x3 << endl;
    cout << "Output: " << obj.upperBound(nums3, x3) << endl;
    cout << "Expected: 1" << endl;

    return 0;
}
