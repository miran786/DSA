#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canplace(vector<int> &nums, int k, int dist)
    {
      int cows = 1;
      int last = nums[0];
      for(int i = 1; i < nums.size(); i++)
      {
        if(nums[i] - last >= dist)
        {
          cows++;
          last = nums[i];
        }
      }
      return cows >= k;
    }
    int aggressiveCows(vector<int> &nums, int k) {
      sort(nums.begin(),nums.end());
      int low = 1;
      int high = nums.back() - nums[0];
      int ans = 0;

      while (low<=high)
      {
        int mid = low + (high - low) /2 ;
        if (canplace(nums, k, mid))
        {
          ans = mid;
          low = mid +1;
        }
        else 
        {
          high = mid -1;
        }
      }
      return ans;
    }
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> nums1 = {0, 3, 4, 7, 10, 9};
    int k1 = 4;
    cout << "Input: nums = [0, 3, 4, 7, 10, 9], k = " << k1 << endl;
    cout << "Output: " << obj.aggressiveCows(nums1, k1) << endl;
    cout << "Expected: 3" << endl << endl;

    // Test Case 2
    vector<int> nums2 = {4, 2, 1, 3, 6};
    int k2 = 2;
    cout << "Input: nums = [4, 2, 1, 3, 6], k = " << k2 << endl;
    cout << "Output: " << obj.aggressiveCows(nums2, k2) << endl;
    cout << "Expected: 5" << endl << endl;

    // Test Case 3 (edge: smallest input, n = 2, k = 2)
    vector<int> nums3 = {5, 100};
    int k3 = 2;
    cout << "Input: nums = [5, 100], k = " << k3 << endl;
    cout << "Output: " << obj.aggressiveCows(nums3, k3) << endl;
    cout << "Expected: 95" << endl << endl;

    // Test Case 4 (edge: k = n, every stall gets a cow)
    vector<int> nums4 = {20, 5, 11, 1};
    int k4 = 4;
    cout << "Input: nums = [20, 5, 11, 1], k = " << k4 << endl;
    cout << "Output: " << obj.aggressiveCows(nums4, k4) << endl;
    cout << "Expected: 4" << endl << endl;

    // Test Case 5 (edge: input already sorted)
    vector<int> nums5 = {1, 2, 4, 8, 9};
    int k5 = 3;
    cout << "Input: nums = [1, 2, 4, 8, 9], k = " << k5 << endl;
    cout << "Output: " << obj.aggressiveCows(nums5, k5) << endl;
    cout << "Expected: 3" << endl << endl;

    // Test Case 6 (edge: evenly spaced stalls, fewer cows than stalls)
    vector<int> nums6 = {0, 10, 20, 30, 40};
    int k6 = 3;
    cout << "Input: nums = [0, 10, 20, 30, 40], k = " << k6 << endl;
    cout << "Output: " << obj.aggressiveCows(nums6, k6) << endl;
    cout << "Expected: 20" << endl << endl;

    // Test Case 7 (edge: large positions, up to 10^9)
    vector<int> nums7 = {0, 1000000000, 500000000};
    int k7 = 3;
    cout << "Input: nums = [0, 1000000000, 500000000], k = " << k7 << endl;
    cout << "Output: " << obj.aggressiveCows(nums7, k7) << endl;
    cout << "Expected: 500000000" << endl << endl;

    // Test Case 8 (Now your turn)
    vector<int> nums8 = {10, 1, 2, 7, 5};
    int k8 = 3;
    cout << "Input: nums = [10, 1, 2, 7, 5], k = " << k8 << endl;
    cout << "Output: " << obj.aggressiveCows(nums8, k8) << endl;
    cout << "Expected: 4" << endl;

    return 0;
}
