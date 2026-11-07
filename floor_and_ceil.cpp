#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> getFloorAndCeil(vector<int> &nums, int x) {
      
      int low = 0;
      int high = nums.size()-1;
      while(low<=high)
      {
        int mid = low + (high - low) / 2;
        if(nums[mid]<=x)
        {
          low = mid +1;
        }
        else
        {
          high = mid-1;
        }

      }
      int floorindex = high;
      low = 0;
      high = nums.size()-1;
      while(low<=high)
      {
        int mid = low + (high - low) / 2;
        if(nums[mid]>=x)
        {
          high = mid-1;
        }
        else
        {
          low = mid +1;
        }

      }
      int celiindex =low;

      int floor = (floorindex >= 0) ? nums[floorindex] : -1;
      int ceil = (celiindex < nums.size()) ? nums[celiindex] : -1;

      return {floor, ceil};
    }
};
    

int main() {
    Solution obj;

    // Test Case 1
    vector<int> nums1 = {3, 4, 4, 7, 8, 10};
    int x1 = 5;
    vector<int> result1 = obj.getFloorAndCeil(nums1, x1);
    cout << "Input: nums = [3, 4, 4, 7, 8, 10], x = " << x1 << endl;
    cout << "Output: " << result1[0] << " " << result1[1] << endl;
    cout << "Expected: 4 7" << endl << endl;

    // Test Case 2
    vector<int> nums2 = {3, 4, 4, 7, 8, 10};
    int x2 = 8;
    vector<int> result2 = obj.getFloorAndCeil(nums2, x2);
    cout << "Input: nums = [3, 4, 4, 7, 8, 10], x = " << x2 << endl;
    cout << "Output: " << result2[0] << " " << result2[1] << endl;
    cout << "Expected: 8 8" << endl << endl;

    // Test Case 3
    vector<int> nums3 = {3, 4, 4, 7, 8, 10};
    int x3 = 1;
    vector<int> result3 = obj.getFloorAndCeil(nums3, x3);
    cout << "Input: nums = [3, 4, 4, 7, 8, 10], x = " << x3 << endl;
    cout << "Output: " << result3[0] << " " << result3[1] << endl;
    cout << "Expected: -1 3" << endl;

    return 0;
}
