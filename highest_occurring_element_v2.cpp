#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int highestOccurringElement(vector<int> &nums) {
      map <int,int> freq;
      int highest_key = 0;
      int highest_value = 0;
      
      for(auto i : nums)
      {
        freq[i]++;
      }

      for(auto j : freq)
      {
        if(j.second > highest_value)
        {
          highest_value = j.second;
          highest_key = j.first;
        }
      }
      return highest_key;
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
    cout << "Expected: 2" << endl << endl;

    // Test Case 4 (edge: single element)
    vector<int> nums4 = {7};
    cout << "Input: [7]" << endl;
    cout << "Output: " << obj.highestOccurringElement(nums4) << endl;
    cout << "Expected: 7" << endl << endl;

    // Test Case 5 (edge: all elements the same)
    vector<int> nums5 = {9, 9, 9, 9};
    cout << "Input: [9, 9, 9, 9]" << endl;
    cout << "Output: " << obj.highestOccurringElement(nums5) << endl;
    cout << "Expected: 9" << endl << endl;

    // Test Case 6 (edge: all distinct, every count is 1)
    vector<int> nums6 = {8, 3, 6, 1, 5};
    cout << "Input: [8, 3, 6, 1, 5]" << endl;
    cout << "Output: " << obj.highestOccurringElement(nums6) << endl;
    cout << "Expected: 1" << endl << endl;

    // Test Case 7 (edge: tie where the smaller value appears later in the array)
    vector<int> nums7 = {5, 5, 3, 3};
    cout << "Input: [5, 5, 3, 3]" << endl;
    cout << "Output: " << obj.highestOccurringElement(nums7) << endl;
    cout << "Expected: 3" << endl << endl;

    // Test Case 8 (edge: negatives and a tie)
    vector<int> nums8 = {-2, -2, 0, 0, 4};
    cout << "Input: [-2, -2, 0, 0, 4]" << endl;
    cout << "Output: " << obj.highestOccurringElement(nums8) << endl;
    cout << "Expected: -2" << endl << endl;

    // Test Case 9 (edge: winner has the largest value and the highest count)
    vector<int> nums9 = {1, 1, 100000, 100000, 100000};
    cout << "Input: [1, 1, 100000, 100000, 100000]" << endl;
    cout << "Output: " << obj.highestOccurringElement(nums9) << endl;
    cout << "Expected: 100000" << endl;

    return 0;
}
