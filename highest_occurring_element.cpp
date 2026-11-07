#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int highestOccurringElement(vector<int> &nums) {
      map<int, int> freq;
      int highest =0;
      int highest_element = 0;
      for (auto num : nums)
      {
        freq[num]++;
      }
      
      for (auto entry : freq)
      {
        if(entry.second > highest)
        {
           highest = entry.second;
          highest_element = entry.first; 

        }
      }
      return highest_element;

    }
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> nums1 = {1, 2, 2, 3, 3, 3};
    cout << "Input: [1, 2, 2, 3, 3, 3]" << endl;
    cout << "Output: " << obj.highestOccurringElement(nums1) << endl;
    cout << "Expected: 3" << endl << endl;

    // Test Case 2
    vector<int> nums2 = {4, 4, 5, 5, 6};
    cout << "Input: [4, 4, 5, 5, 6]" << endl;
    cout << "Output: " << obj.highestOccurringElement(nums2) << endl;
    cout << "Expected: 4" << endl << endl;

    // Test Case 3
    vector<int> nums3 = {2, 4, 3, 2, 5, 4};
    cout << "Input: [2, 4, 3, 2, 5, 4]" << endl;
    cout << "Output: " << obj.highestOccurringElement(nums3) << endl;
    cout << "Expected: 2" << endl;

    return 0;
}
