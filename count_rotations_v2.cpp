#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countRotations(vector<int> &nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }
};

void printVector(const vector<int> &v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << (i + 1 < v.size() ? ", " : "");
    }
    cout << "]";
}

int main() {
    Solution obj;

    // Test Case 1 (example 1)
    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2, 3};
    cout << "Input: ";
    printVector(nums1);
    cout << endl;
    cout << "Output: " << obj.countRotations(nums1) << endl;
    cout << "Expected: " << 4 << endl << endl;

    // Test Case 2 (example 2)
    vector<int> nums2 = {3, 4, 5, 1, 2};
    cout << "Input: ";
    printVector(nums2);
    cout << endl;
    cout << "Output: " << obj.countRotations(nums2) << endl;
    cout << "Expected: " << 3 << endl << endl;

    // Test Case 3 (Now your turn)
    vector<int> nums3 = {4, 5, 1, 2};
    cout << "Input: ";
    printVector(nums3);
    cout << endl;
    cout << "Output: " << obj.countRotations(nums3) << endl;
    cout << "Expected: " << 2 << endl << endl;

    // Test Case 4 (edge: single element)
    vector<int> nums4 = {5};
    cout << "Input: ";
    printVector(nums4);
    cout << endl;
    cout << "Output: " << obj.countRotations(nums4) << endl;
    cout << "Expected: " << 0 << endl << endl;

    // Test Case 5 (edge: zero rotations, already sorted)
    vector<int> nums5 = {1, 2, 3, 4, 5};
    cout << "Input: ";
    printVector(nums5);
    cout << endl;
    cout << "Output: " << obj.countRotations(nums5) << endl;
    cout << "Expected: " << 0 << endl << endl;

    // Test Case 6 (edge: two elements, one rotation)
    vector<int> nums6 = {2, 1};
    cout << "Input: ";
    printVector(nums6);
    cout << endl;
    cout << "Output: " << obj.countRotations(nums6) << endl;
    cout << "Expected: " << 1 << endl << endl;

    // Test Case 7 (edge: two elements, zero rotations)
    vector<int> nums7 = {1, 2};
    cout << "Input: ";
    printVector(nums7);
    cout << endl;
    cout << "Output: " << obj.countRotations(nums7) << endl;
    cout << "Expected: " << 0 << endl << endl;

    // Test Case 8 (edge: minimum at the last index, n-1 rotations)
    vector<int> nums8 = {2, 3, 4, 5, 1};
    cout << "Input: ";
    printVector(nums8);
    cout << endl;
    cout << "Output: " << obj.countRotations(nums8) << endl;
    cout << "Expected: " << 4 << endl << endl;

    // Test Case 9 (edge: minimum at the second index)
    vector<int> nums9 = {5, 1, 2, 3, 4};
    cout << "Input: ";
    printVector(nums9);
    cout << endl;
    cout << "Output: " << obj.countRotations(nums9) << endl;
    cout << "Expected: " << 1 << endl << endl;

    return 0;
}
