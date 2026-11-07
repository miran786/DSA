#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findPages(vector<int> &nums, int m) {
      int low=nums[0];
      int high=0;
      for(auto k : nums)
      {
        high = high + k;
      }
      
      for (int i = low; i <= high; i++)
      {
        int student_count =0;
        int pages=0;
        for (int j = 0; j < nums.size(); j++)
        {
         pages = pages + nums[j];
         if(pages>=i)
         {
          pages = nums[j];
          student_count++;
         }
        }
        if(student_count==m)
        {
          return i;
        }
      }
      
    }
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> nums1 = {12, 34, 67, 90};
    int m1 = 2;
    cout << "Input: nums = [12, 34, 67, 90], m = " << m1 << endl;
    cout << "Output: " << obj.findPages(nums1, m1) << endl;
    cout << "Expected: 113" << endl << endl;

    // Test Case 2
    vector<int> nums2 = {25, 46, 28, 49, 24};
    int m2 = 4;
    cout << "Input: nums = [25, 46, 28, 49, 24], m = " << m2 << endl;
    cout << "Output: " << obj.findPages(nums2, m2) << endl;
    cout << "Expected: 71" << endl << endl;

    // Test Case 3 (Now your turn)
    vector<int> nums3 = {15, 17, 20};
    int m3 = 2;
    cout << "Input: nums = [15, 17, 20], m = " << m3 << endl;
    cout << "Output: " << obj.findPages(nums3, m3) << endl;
    cout << "Expected: 32" << endl << endl;

    // Test Case 4 (edge: more students than books, allocation impossible)
    vector<int> nums4 = {10, 20};
    int m4 = 3;
    cout << "Input: nums = [10, 20], m = " << m4 << endl;
    cout << "Output: " << obj.findPages(nums4, m4) << endl;
    cout << "Expected: -1" << endl << endl;

    // Test Case 5 (edge: students == books, one book each)
    vector<int> nums5 = {10, 20, 30};
    int m5 = 3;
    cout << "Input: nums = [10, 20, 30], m = " << m5 << endl;
    cout << "Output: " << obj.findPages(nums5, m5) << endl;
    cout << "Expected: 30" << endl << endl;

    // Test Case 6 (edge: single student takes every book)
    vector<int> nums6 = {10, 20, 30};
    int m6 = 1;
    cout << "Input: nums = [10, 20, 30], m = " << m6 << endl;
    cout << "Output: " << obj.findPages(nums6, m6) << endl;
    cout << "Expected: 60" << endl << endl;

    // Test Case 7 (edge: one book, one student)
    vector<int> nums7 = {5};
    int m7 = 1;
    cout << "Input: nums = [5], m = " << m7 << endl;
    cout << "Output: " << obj.findPages(nums7, m7) << endl;
    cout << "Expected: 5" << endl << endl;

    // Test Case 8 (edge: all books the same size)
    vector<int> nums8 = {10, 10, 10, 10};
    int m8 = 2;
    cout << "Input: nums = [10, 10, 10, 10], m = " << m8 << endl;
    cout << "Output: " << obj.findPages(nums8, m8) << endl;
    cout << "Expected: 20" << endl << endl;

    // Test Case 9 (edge: one book bigger than all the others combined)
    vector<int> nums9 = {1, 2, 3, 100};
    int m9 = 2;
    cout << "Input: nums = [1, 2, 3, 100], m = " << m9 << endl;
    cout << "Output: " << obj.findPages(nums9, m9) << endl;
    cout << "Expected: 100" << endl << endl;

    // Test Case 10 (edge: smallest case with two books and two students)
    vector<int> nums10 = {7, 3};
    int m10 = 2;
    cout << "Input: nums = [7, 3], m = " << m10 << endl;
    cout << "Output: " << obj.findPages(nums10, m10) << endl;
    cout << "Expected: 7" << endl;

    return 0;
}
