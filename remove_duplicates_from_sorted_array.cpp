#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int k = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[k - 1]) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};

int main() {
    Solution obj;

    auto show = [](const vector<int>& nums, int k) {
        string out = "[";
        for (int i = 0; i < k; i++) {
            out += to_string(nums[i]);
            if (i + 1 < k) out += ", ";
        }
        return out + "]";
    };

    // Test Case 1
    vector<int> nums1 = {0, 0, 3, 3, 5, 6};
    cout << "Input: " << show(nums1, nums1.size()) << endl;
    int k1 = obj.removeDuplicates(nums1);
    cout << "Output: " << k1 << " " << show(nums1, k1) << endl;
    cout << "Expected: 4 [0, 3, 5, 6]" << endl << endl;

    // Test Case 2
    vector<int> nums2 = {-2, 2, 4, 4, 4, 4, 5, 5};
    cout << "Input: " << show(nums2, nums2.size()) << endl;
    int k2 = obj.removeDuplicates(nums2);
    cout << "Output: " << k2 << " " << show(nums2, k2) << endl;
    cout << "Expected: 4 [-2, 2, 4, 5]" << endl << endl;

    // Test Case 3 (edge: empty array)
    vector<int> nums3 = {};
    cout << "Input: " << show(nums3, nums3.size()) << endl;
    int k3 = obj.removeDuplicates(nums3);
    cout << "Output: " << k3 << " " << show(nums3, k3) << endl;
    cout << "Expected: 0 []" << endl << endl;

    // Test Case 4 (edge: single element)
    vector<int> nums4 = {7};
    cout << "Input: " << show(nums4, nums4.size()) << endl;
    int k4 = obj.removeDuplicates(nums4);
    cout << "Output: " << k4 << " " << show(nums4, k4) << endl;
    cout << "Expected: 1 [7]" << endl << endl;

    // Test Case 5 (edge: two equal elements)
    vector<int> nums5 = {4, 4};
    cout << "Input: " << show(nums5, nums5.size()) << endl;
    int k5 = obj.removeDuplicates(nums5);
    cout << "Output: " << k5 << " " << show(nums5, k5) << endl;
    cout << "Expected: 1 [4]" << endl << endl;

    // Test Case 6 (edge: all elements the same)
    vector<int> nums6 = {1, 1, 1, 1, 1};
    cout << "Input: " << show(nums6, nums6.size()) << endl;
    int k6 = obj.removeDuplicates(nums6);
    cout << "Output: " << k6 << " " << show(nums6, k6) << endl;
    cout << "Expected: 1 [1]" << endl << endl;

    // Test Case 7 (edge: no duplicates at all)
    vector<int> nums7 = {1, 2, 3, 4};
    cout << "Input: " << show(nums7, nums7.size()) << endl;
    int k7 = obj.removeDuplicates(nums7);
    cout << "Output: " << k7 << " " << show(nums7, k7) << endl;
    cout << "Expected: 4 [1, 2, 3, 4]" << endl << endl;

    // Test Case 8 (edge: duplicate run reaches the last index)
    vector<int> nums8 = {1, 2, 2};
    cout << "Input: " << show(nums8, nums8.size()) << endl;
    int k8 = obj.removeDuplicates(nums8);
    cout << "Output: " << k8 << " " << show(nums8, k8) << endl;
    cout << "Expected: 2 [1, 2]" << endl << endl;

    // Test Case 9 (edge: duplicate run at the very start, negatives and zero)
    vector<int> nums9 = {-5, -5, 0};
    cout << "Input: " << show(nums9, nums9.size()) << endl;
    int k9 = obj.removeDuplicates(nums9);
    cout << "Output: " << k9 << " " << show(nums9, k9) << endl;
    cout << "Expected: 2 [-5, 0]" << endl << endl;

    return 0;
}
