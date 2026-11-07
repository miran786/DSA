#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void recursiveInsertionSort(vector<int> &nums) {
      insertionSort(nums, nums.size());
    }

  private:
    void insertionSort(vector<int> &nums, int n) {
      // Base case: 1 or 0 elements are already sorted
      if (n <= 1) return;

      // Recursively sort first n-1 elements
      insertionSort(nums, n - 1);

      // Insert the nth element into its correct position
      insertElement(nums, n - 2, nums[n - 1]);
    }

    // Recursively insert element at correct position
    void insertElement(vector<int> &nums, int sorted_end, int element) {
      // Base case: found correct position or reached start
      if (sorted_end >= 0 && nums[sorted_end] > element) {
        // Shift element right and continue searching
        nums[sorted_end + 1] = nums[sorted_end];
        insertElement(nums, sorted_end - 1, element);
      } else {
        // Found correct position, insert element
        nums[sorted_end + 1] = element;
      }
    }
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> nums1 = {7, 4, 1, 5, 3};
    obj.recursiveInsertionSort(nums1);
    cout << "Input: [7, 4, 1, 5, 3]" << endl;
    cout << "Output: ";
    for (int x : nums1) cout << x << " ";
    cout << endl;
    cout << "Expected: 1 3 4 5 7" << endl << endl;

    // Test Case 2
    vector<int> nums2 = {5, 4, 4, 1, 1};
    obj.recursiveInsertionSort(nums2);
    cout << "Input: [5, 4, 4, 1, 1]" << endl;
    cout << "Output: ";
    for (int x : nums2) cout << x << " ";
    cout << endl;
    cout << "Expected: 1 1 4 4 5" << endl << endl;

    // Test Case 3
    vector<int> nums3 = {1, 2, 3};
    obj.recursiveInsertionSort(nums3);
    cout << "Input: [1, 2, 3]" << endl;
    cout << "Output: ";
    for (int x : nums3) cout << x << " ";
    cout << endl;
    cout << "Expected: 1 2 3" << endl;

    return 0;
}
