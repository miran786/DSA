#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void insertionSort(vector<int> &arr) {
      
      int n = arr.size();
      for (int i = 1; i < n; i++)
      {
        int key = arr[i];
        int j = i-1;
        while(j>= 0 && arr[j] > key)
        {
          arr[j+1] = arr[j];
          j--;
        }
        arr[j+1] = key;
      }
      
    }
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> arr1 = {64, 34, 25, 12, 22, 11, 90};
    obj.insertionSort(arr1);
    cout << "Input: [64, 34, 25, 12, 22, 11, 90]" << endl;
    cout << "Output: ";
    for (int x : arr1) cout << x << " ";
    cout << endl;
    cout << "Expected: 11 12 22 25 34 64 90" << endl << endl;

    // Test Case 2
    vector<int> arr2 = {5, 2, 8, 1, 9};
    obj.insertionSort(arr2);
    cout << "Input: [5, 2, 8, 1, 9]" << endl;
    cout << "Output: ";
    for (int x : arr2) cout << x << " ";
    cout << endl;
    cout << "Expected: 1 2 5 8 9" << endl << endl;

    // Test Case 3
    vector<int> arr3 = {1};
    obj.insertionSort(arr3);
    cout << "Input: [1]" << endl;
    cout << "Output: ";
    for (int x : arr3) cout << x << " ";
    cout << endl;
    cout << "Expected: 1" << endl;

    return 0;
}
