#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int secondLargestElement(vector<int> &nums) {
        long long largest = LLONG_MIN;
        long long second = LLONG_MIN;
        for (int x : nums) {
            if (x > largest) {
                second = largest;
                largest = x;
            } else if (x < largest && x > second) {
                second = x;
            }
        }
        return second == LLONG_MIN ? -1 : second;
    }
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> nums1 = {8, 8, 7, 6, 5};
    cout << "Input: nums = [8, 8, 7, 6, 5]" << endl;
    cout << "Output: " << obj.secondLargestElement(nums1) << endl;
    cout << "Expected: 7" << endl << endl;

    // Test Case 2
    vector<int> nums2 = {10, 10, 10, 10, 10};
    cout << "Input: nums = [10, 10, 10, 10, 10]" << endl;
    cout << "Output: " << obj.secondLargestElement(nums2) << endl;
    cout << "Expected: -1" << endl << endl;

    // Test Case 3 (edge: single element)
    vector<int> nums3 = {5};
    cout << "Input: nums = [5]" << endl;
    cout << "Output: " << obj.secondLargestElement(nums3) << endl;
    cout << "Expected: -1" << endl << endl;

    // Test Case 4 (edge: two distinct elements)
    vector<int> nums4 = {3, 9};
    cout << "Input: nums = [3, 9]" << endl;
    cout << "Output: " << obj.secondLargestElement(nums4) << endl;
    cout << "Expected: 3" << endl << endl;

    // Test Case 5 (edge: two equal elements)
    vector<int> nums5 = {4, 4};
    cout << "Input: nums = [4, 4]" << endl;
    cout << "Output: " << obj.secondLargestElement(nums5) << endl;
    cout << "Expected: -1" << endl << endl;

    // Test Case 6 (edge: all negative)
    vector<int> nums6 = {-5, -2, -9};
    cout << "Input: nums = [-5, -2, -9]" << endl;
    cout << "Output: " << obj.secondLargestElement(nums6) << endl;
    cout << "Expected: -5" << endl << endl;

    // Test Case 7 (edge: largest at the very last index)
    vector<int> nums7 = {1, 2, 3, 9};
    cout << "Input: nums = [1, 2, 3, 9]" << endl;
    cout << "Output: " << obj.secondLargestElement(nums7) << endl;
    cout << "Expected: 3" << endl << endl;

    // Test Case 8 (edge: largest at the very first index, descending)
    vector<int> nums8 = {9, 8, 7};
    cout << "Input: nums = [9, 8, 7]" << endl;
    cout << "Output: " << obj.secondLargestElement(nums8) << endl;
    cout << "Expected: 8" << endl << endl;

    // Test Case 9 (edge: duplicates of both the largest and the second largest)
    vector<int> nums9 = {5, 5, 3, 3};
    cout << "Input: nums = [5, 5, 3, 3]" << endl;
    cout << "Output: " << obj.secondLargestElement(nums9) << endl;
    cout << "Expected: 3" << endl << endl;

    // Test Case 10 (edge: the second largest is the smallest possible int)
    vector<int> nums10 = {INT_MAX, INT_MIN};
    cout << "Input: nums = [2147483647, -2147483648]" << endl;
    cout << "Output: " << obj.secondLargestElement(nums10) << endl;
    cout << "Expected: -2147483648" << endl;

    return 0;
}
