#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void quickSort(vector<int> &nums) {
      quickSortHelper(nums, 0, nums.size() - 1);
    }

  private:
    void quickSortHelper(vector<int> &nums, int left, int right) {
      if (left >= right) {
        return;  // Base case: 1 or 0 elements
      }

      // Partition and get pivot position
      int pivotIndex = partition(nums, left, right);

      // Recursively sort left and right
      quickSortHelper(nums, left, pivotIndex - 1);
      quickSortHelper(nums, pivotIndex + 1, right);
    }

    int partition(vector<int> &nums, int left, int right) {
      // Choose last element as pivot
      int pivot = nums[right];
      int i = left - 1;

      // Move elements < pivot to left, > pivot to right
      for (int j = left; j < right; j++) {
        if (nums[j] < pivot) {
          i++;
          swap(nums[i], nums[j]);
        }
      }

      // Place pivot in correct position
      swap(nums[i + 1], nums[right]);
      return i + 1;
    }
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> nums1 = {7, 4, 1, 5, 3};
    obj.quickSort(nums1);
    cout << "Input: [7, 4, 1, 5, 3]" << endl;
    cout << "Output: ";
    for (int x : nums1) cout << x << " ";
    cout << endl;
    cout << "Expected: 1 3 4 5 7" << endl << endl;

    // Test Case 2
    vector<int> nums2 = {5, 4, 4, 1, 1};
    obj.quickSort(nums2);
    cout << "Input: [5, 4, 4, 1, 1]" << endl;
    cout << "Output: ";
    for (int x : nums2) cout << x << " ";
    cout << endl;
    cout << "Expected: 1 1 4 4 5" << endl << endl;

    // Test Case 3
    vector<int> nums3 = {1, 2, 3};
    obj.quickSort(nums3);
    cout << "Input: [1, 2, 3]" << endl;
    cout << "Output: ";
    for (int x : nums3) cout << x << " ";
    cout << endl;
    cout << "Expected: 1 2 3" << endl;

    return 0;
}
