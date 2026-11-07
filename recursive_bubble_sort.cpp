#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void recursiveBubbleSort(vector<int> &nums)
{
bubbleSort(nums,nums.size());

}
public:
void bubbleSort(vector<int> nums,int n)
{
if(n <= 1)
{
  return;//base case 
}

for (int i = 0; i < n-1; i++)
{
  if(nums[i]>nums[i+1])
  {
    swap(nums[i],nums[i+1]);
  }
}

bubbleSort(nums,n-1);

}
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> nums1 = {7, 4, 1, 5, 3};
    obj.recursiveBubbleSort(nums1);
    cout << "Input: [7, 4, 1, 5, 3]" << endl;
    cout << "Output: ";
    for (int x : nums1) cout << x << " ";
    cout << endl;
    cout << "Expected: 1 3 4 5 7" << endl << endl;

    // Test Case 2
    vector<int> nums2 = {5, 4, 4, 1, 1};
    obj.recursiveBubbleSort(nums2);
    cout << "Input: [5, 4, 4, 1, 1]" << endl;
    cout << "Output: ";
    for (int x : nums2) cout << x << " ";
    cout << endl;
    cout << "Expected: 1 1 4 4 5" << endl << endl;

    // Test Case 3
    vector<int> nums3 = {1, 2, 3};
    obj.recursiveBubbleSort(nums3);
    cout << "Input: [1, 2, 3]" << endl;
    cout << "Output: ";
    for (int x : nums3) cout << x << " ";
    cout << endl;
    cout << "Expected: 1 2 3" << endl;

    return 0;
}
