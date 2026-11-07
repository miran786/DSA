#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findPeakElement(vector<int> &arr) {
      int low = 0;
      int high = arr.size() - 1;

      while (low < high)
      {
        int mid = low + (high - low) / 2;

        if (arr[mid] < arr[mid + 1])
        {
          low = mid + 1;   // still climbing — peak is to the right
        }
        else
        {
          high = mid;      // at or past the top — peak is here or to the left
        }
      }

      return low;   // low == high at this point, and it's the peak
    }
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    cout << "Input: arr = [1, 2, 3, 4, 5, 6, 7, 8, 5, 1]" << endl;
    cout << "Output: " << obj.findPeakElement(arr1) << endl;
    cout << "Expected: 7" << endl << endl;

    // Test Case 2
    vector<int> arr2 = {1, 2, 1, 3, 5, 6, 4};
    cout << "Input: arr = [1, 2, 1, 3, 5, 6, 4]" << endl;
    cout << "Output: " << obj.findPeakElement(arr2) << endl;
    cout << "Expected: 1 (index 5 is also valid)" << endl;

    return 0;
}
