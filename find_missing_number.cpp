#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int n = nums.size();
        int expectedSum = n * (n + 1) / 2;
        int actualSum = 0;
        
        for (int num : nums) {
            actualSum += num;
        }
        
        return expectedSum - actualSum;
    }
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> nums1 = {0, 2, 3, 1, 4};
    cout << "Input: [0, 2, 3, 1, 4]" << endl;
    cout << "Output: " << obj.missingNumber(nums1) << endl;
    cout << "Expected: " << 5 << endl << endl;

    // Test Case 2
    vector<int> nums2 = {0, 1, 2, 4, 5, 6};
    cout << "Input: [0, 1, 2, 4, 5, 6]" << endl;
    cout << "Output: " << obj.missingNumber(nums2) << endl;
    cout << "Expected: " << 3 << endl << endl;

    // Test Case 3 (edge: empty array, range is [0, 0])
    vector<int> nums3 = {};
    cout << "Input: []" << endl;
    cout << "Output: " << obj.missingNumber(nums3) << endl;
    cout << "Expected: " << 0 << endl << endl;

    // Test Case 4 (edge: single element, missing the largest)
    vector<int> nums4 = {0};
    cout << "Input: [0]" << endl;
    cout << "Output: " << obj.missingNumber(nums4) << endl;
    cout << "Expected: " << 1 << endl << endl;

    // Test Case 5 (edge: single element, missing the smallest)
    vector<int> nums5 = {1};
    cout << "Input: [1]" << endl;
    cout << "Output: " << obj.missingNumber(nums5) << endl;
    cout << "Expected: " << 0 << endl << endl;

    // Test Case 6 (edge: missing number is n, the last value of the range)
    vector<int> nums6 = {0, 1, 2, 3, 4, 5};
    cout << "Input: [0, 1, 2, 3, 4, 5]" << endl;
    cout << "Output: " << obj.missingNumber(nums6) << endl;
    cout << "Expected: " << 6 << endl << endl;

    // Test Case 7 (edge: missing number is 0, the first value of the range)
    vector<int> nums7 = {1, 2, 3, 4, 5, 6};
    cout << "Input: [1, 2, 3, 4, 5, 6]" << endl;
    cout << "Output: " << obj.missingNumber(nums7) << endl;
    cout << "Expected: " << 0 << endl << endl;

    return 0;
}