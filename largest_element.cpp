#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int largestElement(vector<int> &nums) {
      int largest_element = INT_MIN;
      for(auto i : nums)
      {
        if(i > largest_element)
        {
          largest_element = i;
        }
      }
      return largest_element;
    }
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> nums1 = {3, 3, 6, 1};
    cout << "Input: nums = [3, 3, 6, 1]" << endl;
    cout << "Output: " << obj.largestElement(nums1) << endl;
    cout << "Expected: 6" << endl << endl;

    // Test Case 2
    vector<int> nums2 = {3, 3, 0, 99, -40};
    cout << "Input: nums = [3, 3, 0, 99, -40]" << endl;
    cout << "Output: " << obj.largestElement(nums2) << endl;
    cout << "Expected: 99" << endl << endl;

    // Test Case 3 (edge: single element)
    vector<int> nums3 = {5};
    cout << "Input: nums = [5]" << endl;
    cout << "Output: " << obj.largestElement(nums3) << endl;
    cout << "Expected: 5" << endl << endl;

    // Test Case 4 (edge: all negative)
    vector<int> nums4 = {-8, -3, -10};
    cout << "Input: nums = [-8, -3, -10]" << endl;
    cout << "Output: " << obj.largestElement(nums4) << endl;
    cout << "Expected: -3" << endl << endl;

    // Test Case 5 (edge: all elements the same)
    vector<int> nums5 = {4, 4, 4, 4};
    cout << "Input: nums = [4, 4, 4, 4]" << endl;
    cout << "Output: " << obj.largestElement(nums5) << endl;
    cout << "Expected: 4" << endl << endl;

    // Test Case 6 (edge: largest at the very first index)
    vector<int> nums6 = {9, 1, 2, 3};
    cout << "Input: nums = [9, 1, 2, 3]" << endl;
    cout << "Output: " << obj.largestElement(nums6) << endl;
    cout << "Expected: 9" << endl << endl;

    // Test Case 7 (edge: largest at the very last index)
    vector<int> nums7 = {1, 2, 3, 9};
    cout << "Input: nums = [1, 2, 3, 9]" << endl;
    cout << "Output: " << obj.largestElement(nums7) << endl;
    cout << "Expected: 9" << endl << endl;

    // Test Case 8 (edge: all zeros)
    vector<int> nums8 = {0, 0, 0};
    cout << "Input: nums = [0, 0, 0]" << endl;
    cout << "Output: " << obj.largestElement(nums8) << endl;
    cout << "Expected: 0" << endl << endl;

    // Test Case 9 (edge: smallest possible int is the only element)
    vector<int> nums9 = {INT_MIN};
    cout << "Input: nums = [-2147483648]" << endl;
    cout << "Output: " << obj.largestElement(nums9) << endl;
    cout << "Expected: -2147483648" << endl << endl;

    // Test Case 10 (edge: extreme values on both ends)
    vector<int> nums10 = {INT_MIN, 0, INT_MAX};
    cout << "Input: nums = [-2147483648, 0, 2147483647]" << endl;
    cout << "Output: " << obj.largestElement(nums10) << endl;
    cout << "Expected: 2147483647" << endl;

    return 0;
}
