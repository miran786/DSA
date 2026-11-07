#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void selectionSort(vector<int> &arr) {
        
        int n = arr.size();

        for(int i = 0; i < n-1;i++)
        {int min_index=i;
            for (int j = i+1; j < n; j++)
            {
                if(arr[min_index]>arr[j])
                {
                    min_index = j;
                }
            }
            swap(arr[min_index],arr[i]);
        }

    }
};

void printArr(const vector<int> &arr) {
    for (int x : arr) cout << x << " ";
    cout << endl;
}

int main() {
    Solution obj;

    // Test Case 1
    vector<int> arr1 = {64, 34, 25, 12, 22, 11, 90};
    cout << "Input: [64, 34, 25, 12, 22, 11, 90]" << endl;
    obj.selectionSort(arr1);
    cout << "Output: "; printArr(arr1);
    cout << "Expected: 11 12 22 25 34 64 90" << endl << endl;

    // Test Case 2
    vector<int> arr2 = {5, 2, 8, 1, 9};
    cout << "Input: [5, 2, 8, 1, 9]" << endl;
    obj.selectionSort(arr2);
    cout << "Output: "; printArr(arr2);
    cout << "Expected: 1 2 5 8 9" << endl << endl;

    // Test Case 3 (edge: single element)
    vector<int> arr3 = {1};
    cout << "Input: [1]" << endl;
    obj.selectionSort(arr3);
    cout << "Output: "; printArr(arr3);
    cout << "Expected: 1" << endl << endl;

    // Test Case 4 (edge: empty array)
    vector<int> arr4 = {};
    cout << "Input: []" << endl;
    obj.selectionSort(arr4);
    cout << "Output: "; printArr(arr4);
    cout << "Expected: " << endl << endl;

    // Test Case 5 (edge: already sorted)
    vector<int> arr5 = {1, 2, 3, 4, 5};
    cout << "Input: [1, 2, 3, 4, 5]" << endl;
    obj.selectionSort(arr5);
    cout << "Output: "; printArr(arr5);
    cout << "Expected: 1 2 3 4 5" << endl << endl;

    // Test Case 6 (edge: reverse sorted)
    vector<int> arr6 = {9, 7, 5, 3, 1};
    cout << "Input: [9, 7, 5, 3, 1]" << endl;
    obj.selectionSort(arr6);
    cout << "Output: "; printArr(arr6);
    cout << "Expected: 1 3 5 7 9" << endl << endl;

    // Test Case 7 (edge: duplicates and negatives)
    vector<int> arr7 = {3, -1, 3, 0, -1, 2};
    cout << "Input: [3, -1, 3, 0, -1, 2]" << endl;
    obj.selectionSort(arr7);
    cout << "Output: "; printArr(arr7);
    cout << "Expected: -1 -1 0 2 3 3" << endl << endl;

    // Test Case 8 (edge: two elements, out of order)
    vector<int> arr8 = {2, 1};
    cout << "Input: [2, 1]" << endl;
    obj.selectionSort(arr8);
    cout << "Output: "; printArr(arr8);
    cout << "Expected: 1 2" << endl;

    return 0;
}
