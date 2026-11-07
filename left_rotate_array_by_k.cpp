#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void leftRotateByK(vector<int>& nums, int k) {
        vector<int> temp_vec;

        for(int i = 0; i < k; i++)
        {
            temp_vec.push_back(nums[i]);

        }

        

        for (int j = 0; j < nums.size()-k; j++)
        {
            nums[j]=nums[j+k];
        }
        
        

       int count = nums.size()-k;
        for (auto c: temp_vec)
        {
            nums[count] = c;
            count++;    
        }
        
        
          
        
        

    }
};

int main() {
    Solution obj;

    auto show = [](const vector<int>& v) {
        string s = "[";
        for (size_t i = 0; i < v.size(); i++) {
            s += to_string(v[i]);
            if (i + 1 < v.size()) s += ", ";
        }
        return s + "]";
    };

    // Test Case 1 (example 1)
    {
        vector<int> nums = {1, 2, 3, 4, 5, 6};
        int k = 2;
        cout << "Input: nums = " << show(nums) << ", k = " << k << endl;
        obj.leftRotateByK(nums, k);
        cout << "Output: " << show(nums) << endl;
        cout << "Expected: " << show({3, 4, 5, 6, 1, 2}) << endl << endl;
    }

    // Test Case 2 (example 2: k larger than n)
    {
        vector<int> nums = {3, 4, 1, 5, 3, -5};
        int k = 8;
        cout << "Input: nums = " << show(nums) << ", k = " << k << endl;
        obj.leftRotateByK(nums, k);
        cout << "Output: " << show(nums) << endl;
        cout << "Expected: " << show({1, 5, 3, -5, 3, 4}) << endl << endl;
    }

    // Test Case 3 (edge: empty array, k = 0)
    {
        vector<int> nums = {};
        int k = 0;
        cout << "Input: nums = " << show(nums) << ", k = " << k << endl;
        obj.leftRotateByK(nums, k);
        cout << "Output: " << show(nums) << endl;
        cout << "Expected: " << show({}) << endl << endl;
    }

    // Test Case 4 (edge: single element, k > 0)
    {
        vector<int> nums = {7};
        int k = 3;
        cout << "Input: nums = " << show(nums) << ", k = " << k << endl;
        obj.leftRotateByK(nums, k);
        cout << "Output: " << show(nums) << endl;
        cout << "Expected: " << show({7}) << endl << endl;
    }

    // Test Case 5 (edge: k = 0, no rotation)
    {
        vector<int> nums = {1, 2, 3};
        int k = 0;
        cout << "Input: nums = " << show(nums) << ", k = " << k << endl;
        obj.leftRotateByK(nums, k);
        cout << "Output: " << show(nums) << endl;
        cout << "Expected: " << show({1, 2, 3}) << endl << endl;
    }

    // Test Case 6 (edge: k = n, full rotation back to start)
    {
        vector<int> nums = {1, 2, 3};
        int k = 3;
        cout << "Input: nums = " << show(nums) << ", k = " << k << endl;
        obj.leftRotateByK(nums, k);
        cout << "Output: " << show(nums) << endl;
        cout << "Expected: " << show({1, 2, 3}) << endl << endl;
    }

    // Test Case 7 (edge: k = n - 1, last valid point)
    {
        vector<int> nums = {1, 2, 3, 4};
        int k = 3;
        cout << "Input: nums = " << show(nums) << ", k = " << k << endl;
        obj.leftRotateByK(nums, k);
        cout << "Output: " << show(nums) << endl;
        cout << "Expected: " << show({4, 1, 2, 3}) << endl << endl;
    }

    // Test Case 8 (edge: all elements the same)
    {
        vector<int> nums = {2, 2, 2, 2};
        int k = 1;
        cout << "Input: nums = " << show(nums) << ", k = " << k << endl;
        obj.leftRotateByK(nums, k);
        cout << "Output: " << show(nums) << endl;
        cout << "Expected: " << show({2, 2, 2, 2}) << endl << endl;
    }

    // Test Case 9 (edge: k is a multiple of n)
    {
        vector<int> nums = {1, 2, 3, 4};
        int k = 8;
        cout << "Input: nums = " << show(nums) << ", k = " << k << endl;
        obj.leftRotateByK(nums, k);
        cout << "Output: " << show(nums) << endl;
        cout << "Expected: " << show({1, 2, 3, 4}) << endl << endl;
    }

    return 0;
}
