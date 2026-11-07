#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void mergeSort(vector<int> &arr) {
      mergeSortHelper(arr, 0, arr.size() - 1);
    }

  private:
    void mergeSortHelper(vector<int> &arr, int left, int right) {
      if (left >= right) {
        return;  // base case: 1 or 0 elements
      }

      int mid = left + (right - left) / 2;
      mergeSortHelper(arr, left, mid);      // sort left half
      mergeSortHelper(arr, mid + 1, right); // sort right half
      merge(arr, left, mid, right);         // merge them
    }

    void merge(vector<int> &arr, int left, int mid, int right) {
      vector<int> temp(right - left + 1);

      int i = left;      // pointer for left half
      int j = mid + 1;   // pointer for right half
      int k = 0;         // pointer for temp

      // Compare and merge from both halves
      while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
          temp[k++] = arr[i++];
        } else {
          temp[k++] = arr[j++];
        }
      }
      

      // Copy remaining from left half
      while (i <= mid) {
        temp[k++] = arr[i++];
      }

      // Copy remaining from right half
      while (j <= right) {
        temp[k++] = arr[j++];
      }

      // Copy merged elements back to original array
      for (int x = 0; x < temp.size(); x++) {
        arr[left + x] = temp[x];
      }
    }
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> arr1 = {64, 34, 25, 12, 22, 11, 90};
    obj.mergeSort(arr1);
    cout << "Input: [64, 34, 25, 12, 22, 11, 90]" << endl;
    cout << "Output: ";
    for (int x : arr1) cout << x << " ";
    cout << endl;
    cout << "Expected: 11 12 22 25 34 64 90" << endl << endl;

    // Test Case 2
    vector<int> arr2 = {5, 2, 8, 1, 9};
    obj.mergeSort(arr2);
    cout << "Input: [5, 2, 8, 1, 9]" << endl;
    cout << "Output: ";
    for (int x : arr2) cout << x << " ";
    cout << endl;
    cout << "Expected: 1 2 5 8 9" << endl << endl;

    // Test Case 3
    vector<int> arr3 = {1};
    obj.mergeSort(arr3);
    cout << "Input: [1]" << endl;
    cout << "Output: ";
    for (int x : arr3) cout << x << " ";
    cout << endl;
    cout << "Expected: 1" << endl;

    return 0;
}
