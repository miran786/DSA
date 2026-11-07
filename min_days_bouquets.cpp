#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minDays(vector<int> &nums, int m, int k) {
      long long n = nums.size();

      // Not enough flowers to ever make m bouquets of k each
      if ((long long)m * k > n)
      {
        return -1;
      }

      int low = *min_element(nums.begin(), nums.end());
      int high = *max_element(nums.begin(), nums.end());
      int ans = -1;

      while (low <= high)
      {
        int mid = low + (high - low) / 2;   // candidate day

        if (canMake(nums, mid, m, k))
        {
          ans = mid;        // mid works — remember it, try an earlier day
          high = mid - 1;
        }
        else
        {
          low = mid + 1;    // mid too early — need more time
        }
      }

      return ans;
    }

  private:
    // How many bouquets can be made if today is `day`?
    bool canMake(vector<int> &nums, int day, int m, int k)
    {
      int bouquets = 0;
      int streak = 0;

      for (int i = 0; i < nums.size(); i++)
      {
        if (nums[i] <= day)
        {
          streak++;
          if (streak == k)
          {
            bouquets++;
            streak = 0;   // start a fresh group of adjacent flowers
          }
        }
        else
        {
          streak = 0;      // this flower hasn't bloomed — breaks adjacency
        }
      }

      return bouquets >= m;
    }
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> nums1 = {7, 7, 7, 7, 13, 11, 12, 7};
    int m1 = 2, k1 = 3;
    cout << "Input: nums = [7, 7, 7, 7, 13, 11, 12, 7], m = " << m1 << ", k = " << k1 << endl;
    cout << "Output: " << obj.minDays(nums1, m1, k1) << endl;
    cout << "Expected: 12" << endl << endl;

    // Test Case 2
    vector<int> nums2 = {1, 10, 3, 10, 2};
    int m2 = 3, k2 = 2;
    cout << "Input: nums = [1, 10, 3, 10, 2], m = " << m2 << ", k = " << k2 << endl;
    cout << "Output: " << obj.minDays(nums2, m2, k2) << endl;
    cout << "Expected: -1" << endl << endl;

    // Test Case 3 (edge: k=1, every bloomed flower is its own bouquet)
    vector<int> nums3 = {1, 2, 3};
    int m3 = 3, k3 = 1;
    cout << "Input: nums = [1, 2, 3], m = " << m3 << ", k = " << k3 << endl;
    cout << "Output: " << obj.minDays(nums3, m3, k3) << endl;
    cout << "Expected: 3" << endl << endl;

    // Test Case 4 (edge: not enough flowers at all, m*k > n)
    vector<int> nums4 = {1, 2};
    int m4 = 2, k4 = 2;
    cout << "Input: nums = [1, 2], m = " << m4 << ", k = " << k4 << endl;
    cout << "Output: " << obj.minDays(nums4, m4, k4) << endl;
    cout << "Expected: -1" << endl;

    return 0;
}
