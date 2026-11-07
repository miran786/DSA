#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void moveZerosToEnd(vector<int>& nums) {
        int ptr=0;

        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != 0)
            {
                nums[ptr] = nums[i];
                if(ptr!=i)
                {
                    nums[i]=0;
                }
                
                ptr++;
            }
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
        vector<int> nums = {0, 1, 4, 0, 5, 2};
        cout << "Input: nums = " << show(nums) << endl;
        obj.moveZerosToEnd(nums);
        cout << "Output: " << show(nums) << endl;
        cout << "Expected: " << show({1, 4, 5, 2, 0, 0}) << endl << endl;
    }

    // Test Case 2 (example 2)
    {
        vector<int> nums = {0, 0, 0, 1, 3, -2};
        cout << "Input: nums = " << show(nums) << endl;
        obj.moveZerosToEnd(nums);
        cout << "Output: " << show(nums) << endl;
        cout << "Expected: " << show({1, 3, -2, 0, 0, 0}) << endl << endl;
    }

    // Test Case 3 (edge: empty array)
    {
        vector<int> nums = {};
        cout << "Input: nums = " << show(nums) << endl;
        obj.moveZerosToEnd(nums);
        cout << "Output: " << show(nums) << endl;
        cout << "Expected: " << show({}) << endl << endl;
    }

    // Test Case 4 (edge: single zero)
    {
        vector<int> nums = {0};
        cout << "Input: nums = " << show(nums) << endl;
        obj.moveZerosToEnd(nums);
        cout << "Output: " << show(nums) << endl;
        cout << "Expected: " << show({0}) << endl << endl;
    }

    // Test Case 5 (edge: single non-zero)
    {
        vector<int> nums = {5};
        cout << "Input: nums = " << show(nums) << endl;
        obj.moveZerosToEnd(nums);
        cout << "Output: " << show(nums) << endl;
        cout << "Expected: " << show({5}) << endl << endl;
    }

    // Test Case 6 (edge: no zeros)
    {
        vector<int> nums = {3, 1, 2};
        cout << "Input: nums = " << show(nums) << endl;
        obj.moveZerosToEnd(nums);
        cout << "Output: " << show(nums) << endl;
        cout << "Expected: " << show({3, 1, 2}) << endl << endl;
    }

    // Test Case 7 (edge: all zeros)
    {
        vector<int> nums = {0, 0, 0, 0};
        cout << "Input: nums = " << show(nums) << endl;
        obj.moveZerosToEnd(nums);
        cout << "Output: " << show(nums) << endl;
        cout << "Expected: " << show({0, 0, 0, 0}) << endl << endl;
    }

    // Test Case 8 (edge: zeros already at the end)
    {
        vector<int> nums = {1, 2, 0, 0};
        cout << "Input: nums = " << show(nums) << endl;
        obj.moveZerosToEnd(nums);
        cout << "Output: " << show(nums) << endl;
        cout << "Expected: " << show({1, 2, 0, 0}) << endl << endl;
    }

    // Test Case 9 (edge: zero only at the very front)
    {
        vector<int> nums = {0, -1, 2, -3};
        cout << "Input: nums = " << show(nums) << endl;
        obj.moveZerosToEnd(nums);
        cout << "Output: " << show(nums) << endl;
        cout << "Expected: " << show({-1, 2, -3, 0}) << endl << endl;
    }

    return 0;
}
