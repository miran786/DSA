#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findKthPositive(vector<int> &arr, int k) {
      int low = 0;
      int high = arr.size()-1;

      while (low <= high)
      {
        int mid = low + (high - low)/2;
        int miss_nos = arr[mid] - (mid + 1);

        if(miss_nos < k)
        {
          low = mid +1;
        }
        else
        {
          high = mid -1;
        }
      }

      return low + k;
    }
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> arr1 = {3, 5, 7, 10};
    int k1 = 6;
    cout << "Input: arr = [3, 5, 7, 10], k = " << k1 << endl;
    cout << "Output: " << obj.findKthPositive(arr1, k1) << endl;
    cout << "Expected: 9" << endl << endl;

    // Test Case 2
    vector<int> arr2 = {1, 4, 6, 8, 9};
    int k2 = 3;
    cout << "Input: arr = [1, 4, 6, 8, 9], k = " << k2 << endl;
    cout << "Output: " << obj.findKthPositive(arr2, k2) << endl;
    cout << "Expected: 5" << endl << endl;

    // Test Case 3 (edge: empty array, every positive number is missing)
    vector<int> arr3 = {};
    int k3 = 3;
    cout << "Input: arr = [], k = " << k3 << endl;
    cout << "Output: " << obj.findKthPositive(arr3, k3) << endl;
    cout << "Expected: 3" << endl << endl;

    // Test Case 4 (edge: k is bigger than any gap before the array, answer lands past the array)
    vector<int> arr4 = {2};
    int k4 = 1;
    cout << "Input: arr = [2], k = " << k4 << endl;
    cout << "Output: " << obj.findKthPositive(arr4, k4) << endl;
    cout << "Expected: 1" << endl;

    return 0;
}
