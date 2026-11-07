#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int lowerBound(vector<int> &nums, int x) {
      int low= 0;
      int high = nums.size()-1;

      while(low<=high)
      {
        int mid = low + (high - low) /2 ;

        if(nums[mid] < x)
        {
          low = mid +1 ;
        }
        else
        {
          high = mid-1;
        }

        return low;
      }


      

    }
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> nums1 = {1, 2, 2, 3};
    int x1 = 2;
    cout << "Input: nums = [1, 2, 2, 3], x = " << x1 << endl;
    cout << "Output: " << obj.lowerBound(nums1, x1) << endl;
    cout << "Expected: 1" << endl << endl;

    // Test Case 2
    vector<int> nums2 = {3, 5, 8, 15, 19};
    int x2 = 9;
    cout << "Input: nums = [3, 5, 8, 15, 19], x = " << x2 << endl;
    cout << "Output: " << obj.lowerBound(nums2, x2) << endl;
    cout << "Expected: 3" << endl << endl;

    // Test Case 3
    vector<int> nums3 = {1, 2, 2, 3};
    int x3 = 0;
    cout << "Input: nums = [1, 2, 2, 3], x = " << x3 << endl;
    cout << "Output: " << obj.lowerBound(nums3, x3) << endl;
    cout << "Expected: 0" << endl;

    return 0;
}
