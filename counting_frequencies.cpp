#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<pair<int, int>> countFrequencies(vector<int> &nums) {
        map<int, int> freq;

        // Count frequencies
        for (auto num : nums) {
            freq[num]++;
        }

        // Build result vector of pairs
        vector<pair<int, int>> result;
        for (auto entry : freq) {
            result.push_back({entry.first, entry.second});
        }

        return result;
    }
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> nums1 = {1, 2, 2, 1, 3};
    vector<pair<int, int>> result1 = obj.countFrequencies(nums1);
    cout << "Input: [1, 2, 2, 1, 3]" << endl;
    cout << "Output: ";
    for (auto p : result1) {
        cout << "[" << p.first << ", " << p.second << "] ";
    }
    cout << endl;
    cout << "Expected: [1, 2] [2, 2] [3, 1] (order may vary)" << endl << endl;

    // Test Case 2
    vector<int> nums2 = {5, 5, 5, 5};
    vector<pair<int, int>> result2 = obj.countFrequencies(nums2);
    cout << "Input: [5, 5, 5, 5]" << endl;
    cout << "Output: ";
    for (auto p : result2) {
        cout << "[" << p.first << ", " << p.second << "] ";
    }
    cout << endl;
    cout << "Expected: [5, 4]" << endl << endl;

    // Test Case 3
    vector<int> nums3 = {7};
    vector<pair<int, int>> result3 = obj.countFrequencies(nums3);
    cout << "Input: [7]" << endl;
    cout << "Output: ";
    for (auto p : result3) {
        cout << "[" << p.first << ", " << p.second << "] ";
    }
    cout << endl;
    cout << "Expected: [7, 1]" << endl;

    return 0;
}
