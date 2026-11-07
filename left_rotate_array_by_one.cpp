#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void leftRotateByOne(vector<int>& nums) {
        
        if(nums.size()>1)
        {
            int temp = nums[0];
        for (int i = 0; i < nums.size()-1 ; i++)
        {
            nums[i] = nums[i+1];
        }
        nums[nums.size()-1]=temp;
        }
        

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
    vector<int> nums1 = {1, 2, 3, 4, 5};
    obj.leftRotateByOne(nums1);
    cout << "Input: [1, 2, 3, 4, 5]" << endl;
    cout << "Output: "; printVec(nums1); cout << endl;
    cout << "Expected: [2, 3, 4, 5, 1]" << endl << endl;

    // Test Case 2 (Example 2)
    vector<int> nums2 = {-1, 0, 3, 6};
    obj.leftRotateByOne(nums2);
    cout << "Input: [-1, 0, 3, 6]" << endl;
    cout << "Output: "; printVec(nums2); cout << endl;
    cout << "Expected: [0, 3, 6, -1]" << endl << endl;

    // Test Case 3 (edge: single element, nothing to move)
    vector<int> nums3 = {5};
    obj.leftRotateByOne(nums3);
    cout << "Input: [5]" << endl;
    cout << "Output: "; printVec(nums3); cout << endl;
    cout << "Expected: [5]" << endl << endl;

    // Test Case 4 (edge: two elements, smallest swap case)
    vector<int> nums4 = {1, 2};
    obj.leftRotateByOne(nums4);
    cout << "Input: [1, 2]" << endl;
    cout << "Output: "; printVec(nums4); cout << endl;
    cout << "Expected: [2, 1]" << endl << endl;

    // Test Case 5 (edge: all same values)
    vector<int> nums5 = {7, 7, 7};
    obj.leftRotateByOne(nums5);
    cout << "Input: [7, 7, 7]" << endl;
    cout << "Output: "; printVec(nums5); cout << endl;
    cout << "Expected: [7, 7, 7]" << endl << endl;

    // Test Case 6 (edge: negative values only, first element moves to end)
    vector<int> nums6 = {-5, -4, -3};
    obj.leftRotateByOne(nums6);
    cout << "Input: [-5, -4, -3]" << endl;
    cout << "Output: "; printVec(nums6); cout << endl;
    cout << "Expected: [-4, -3, -5]" << endl << endl;

    // Test Case 7 (edge: empty array, must not crash)
    vector<int> nums7 = {};
    obj.leftRotateByOne(nums7);
    cout << "Input: []" << endl;
    cout << "Output: "; printVec(nums7); cout << endl;
    cout << "Expected: []" << endl << endl;

    return 0;
}
