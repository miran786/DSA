#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void bubbleSort(vector<int> &arr) {
      int n = arr.size();
      for (int i = 0; i < n; i++)
      {
        bool swapped = false;        // track if any swap happened this pass
        for (int j = 0; j < n-i-1; j++)
        {
          if(arr[j]>arr[j+1]) {
            swap(arr[j],arr[j+1]);
            swapped = true;          // mark that we swapped
          }
        }
        if (!swapped) break;         // no swaps = array is sorted, exit early
      }
      

    }
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> arr1 = {64, 34, 25, 12, 22, 11, 90};
    obj.bubbleSort(arr1);
    cout << "Input: [64, 34, 25, 12, 22, 11, 90]" << endl;
    cout << "Output: ";
    for (int x : arr1) cout << x << " ";
    cout << endl;
    cout << "Expected: 11 12 22 25 34 64 90" << endl << endl;

    // Test Case 2
    vector<int> arr2 = {5, 2, 8, 1, 9};
    obj.bubbleSort(arr2);
    cout << "Input: [5, 2, 8, 1, 9]" << endl;
    cout << "Output: ";
    for (int x : arr2) cout << x << " ";
    cout << endl;
    cout << "Expected: 1 2 5 8 9" << endl << endl;

    // Test Case 3
    vector<int> arr3 = {1};
    obj.bubbleSort(arr3);
    cout << "Input: [1]" << endl;
    cout << "Output: ";
    for (int x : arr3) cout << x << " ";
    cout << endl;
    cout << "Expected: 1" << endl;

    return 0;
}
