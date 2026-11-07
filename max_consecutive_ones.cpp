#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_consecutive = 0;
        int count = 0;
        for(auto i : nums)
        {
            if(i == 1)
            {
                count++;
            }
            else
            {
                count = 0;
            }
            if(max_consecutive < count)
            {
                max_consecutive = count;
            }
        }
        return max_consecutive;
    }
};

void printVec(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << (i + 1 < v.size() ? ", " : "");
    }
    cout << "]";
}

int main() {
    Solution obj;

    // Test Case 1 (Example 1)
    vector<int> nums1 = {1, 1, 0, 0, 1, 1, 1, 0};
    int res1 = obj.findMaxConsecutiveOnes(nums1);
    cout << "Input: "; printVec(nums1); cout << endl;
    cout << "Output: " << res1 << endl;
    cout << "Expected: 3" << endl << endl;

    // Test Case 2 (Example 2)
    vector<int> nums2 = {0, 0, 0, 0, 0, 0, 0, 0};
    int res2 = obj.findMaxConsecutiveOnes(nums2);
    cout << "Input: "; printVec(nums2); cout << endl;
    cout << "Output: " << res2 << endl;
    cout << "Expected: 0" << endl << endl;

    // Test Case 3 (edge: single 1)
    vector<int> nums3 = {1};
    int res3 = obj.findMaxConsecutiveOnes(nums3);
    cout << "Input: "; printVec(nums3); cout << endl;
    cout << "Output: " << res3 << endl;
    cout << "Expected: 1" << endl << endl;

    // Test Case 4 (edge: single 0)
    vector<int> nums4 = {0};
    int res4 = obj.findMaxConsecutiveOnes(nums4);
    cout << "Input: "; printVec(nums4); cout << endl;
    cout << "Output: " << res4 << endl;
    cout << "Expected: 0" << endl << endl;

    // Test Case 5 (edge: all ones)
    vector<int> nums5 = {1, 1, 1, 1};
    int res5 = obj.findMaxConsecutiveOnes(nums5);
    cout << "Input: "; printVec(nums5); cout << endl;
    cout << "Output: " << res5 << endl;
    cout << "Expected: 4" << endl << endl;

    // Test Case 6 (edge: run of ones at the very end)
    vector<int> nums6 = {0, 1, 0, 1, 1};
    int res6 = obj.findMaxConsecutiveOnes(nums6);
    cout << "Input: "; printVec(nums6); cout << endl;
    cout << "Output: " << res6 << endl;
    cout << "Expected: 2" << endl << endl;

    // Test Case 7 (edge: run of ones at the very start, longest)
    vector<int> nums7 = {1, 1, 1, 0, 1};
    int res7 = obj.findMaxConsecutiveOnes(nums7);
    cout << "Input: "; printVec(nums7); cout << endl;
    cout << "Output: " << res7 << endl;
    cout << "Expected: 3" << endl << endl;

    // Test Case 8 (edge: alternating, no run longer than 1)
    vector<int> nums8 = {1, 0, 1, 0, 1, 0};
    int res8 = obj.findMaxConsecutiveOnes(nums8);
    cout << "Input: "; printVec(nums8); cout << endl;
    cout << "Output: " << res8 << endl;
    cout << "Expected: 1" << endl << endl;

    // Test Case 9 (edge: empty array)
    vector<int> nums9 = {};
    int res9 = obj.findMaxConsecutiveOnes(nums9);
    cout << "Input: "; printVec(nums9); cout << endl;
    cout << "Output: " << res9 << endl;
    cout << "Expected: 0" << endl << endl;

    return 0;
}
