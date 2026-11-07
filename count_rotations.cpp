#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countRotations(vector<int> &nums) {
      int low = 0;
      int high = nums.size()-1;
      while(low < high)
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

      return low;


    }
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2, 3};
    cout << "Input: nums = [4, 5, 6, 7, 0, 1, 2, 3]" << endl;
    cout << "Output: " << obj.countRotations(nums1) << endl;
    cout << "Expected: 4" << endl << endl;

    // Test Case 2
    vector<int> nums2 = {3, 4, 5, 1, 2};
    cout << "Input: nums = [3, 4, 5, 1, 2]" << endl;
    cout << "Output: " << obj.countRotations(nums2) << endl;
    cout << "Expected: 3" << endl;

    return 0;
}
