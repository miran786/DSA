#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestConsecutive(vector<int> &nums) {

    }
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    cout << "Input: nums = [100, 4, 200, 1, 3, 2]" << endl;
    cout << "Output: " << obj.longestConsecutive(nums1) << endl;
    cout << "Expected: 4" << endl << endl;

    // Test Case 2
    vector<int> nums2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << "Input: nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]" << endl;
    cout << "Output: " << obj.longestConsecutive(nums2) << endl;
    cout << "Expected: 9" << endl << endl;

    // Test Case 3
    vector<int> nums3 = {1, 0, 1, 2};
    cout << "Input: nums = [1, 0, 1, 2]" << endl;
    cout << "Output: " << obj.longestConsecutive(nums3) << endl;
    cout << "Expected: 3" << endl << endl;

    // Test Case 4 (edge: empty array)
    vector<int> nums4 = {};
    cout << "Input: nums = []" << endl;
    cout << "Output: " << obj.longestConsecutive(nums4) << endl;
    cout << "Expected: 0" << endl << endl;

    // Test Case 5 (edge: single element)
    vector<int> nums5 = {5};
    cout << "Input: nums = [5]" << endl;
    cout << "Output: " << obj.longestConsecutive(nums5) << endl;
    cout << "Expected: 1" << endl << endl;

    // Test Case 6 (edge: all duplicates)
    vector<int> nums6 = {7, 7, 7};
    cout << "Input: nums = [7, 7, 7]" << endl;
    cout << "Output: " << obj.longestConsecutive(nums6) << endl;
    cout << "Expected: 1" << endl << endl;

    // Test Case 7 (edge: no two values are consecutive)
    vector<int> nums7 = {10, 30, 50};
    cout << "Input: nums = [10, 30, 50]" << endl;
    cout << "Output: " << obj.longestConsecutive(nums7) << endl;
    cout << "Expected: 1" << endl << endl;

    // Test Case 8 (edge: negatives crossing zero)
    vector<int> nums8 = {-2, -1, 0, 1};
    cout << "Input: nums = [-2, -1, 0, 1]" << endl;
    cout << "Output: " << obj.longestConsecutive(nums8) << endl;
    cout << "Expected: 4" << endl << endl;

    // Test Case 9 (edge: longest run in the middle, not at the start or end)
    vector<int> nums9 = {5, 6, 100, 101, 102, 50};
    cout << "Input: nums = [5, 6, 100, 101, 102, 50]" << endl;
    cout << "Output: " << obj.longestConsecutive(nums9) << endl;
    cout << "Expected: 3" << endl;

    return 0;
}
