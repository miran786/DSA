#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countOccurrences(vector<int> &arr, int target) {
      int low = 0;
      int high = arr.size()-1;
      int firstoccurance_index = -1, last_occurance_index = -1;
      while (low<=high)
      {
        int mid = low +(high-low)/2;

        if(arr[mid] < target)
        {
          low = mid +1;
        }
        else
        {
          high = mid -1;
        }

        if(arr[mid] == target)
        {
          firstoccurance_index = mid;
        }
      }

    
      
      low = 0;
      high = arr.size()-1;

      while (low<=high)
      {
        int mid = low +(high-low)/2;

        if(arr[mid] > target)
        {
          high = mid - 1;
        }
        else
        {
          low = mid + 1;
        }

        if(arr[mid] == target)
        {
          last_occurance_index = mid;
        }
      }
  
      if(firstoccurance_index == -1)
      {
        return 0;
      }
      int count = last_occurance_index-firstoccurance_index+1;

      return count;
  
    }
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> arr1 = {0, 0, 1, 1, 1, 2, 3};
    int target1 = 1;
    cout << "Input: arr = [0, 0, 1, 1, 1, 2, 3], target = " << target1 << endl;
    cout << "Output: " << obj.countOccurrences(arr1, target1) << endl;
    cout << "Expected: 3" << endl << endl;

    // Test Case 2
    vector<int> arr2 = {5, 5, 5, 5, 5, 5};
    int target2 = 5;
    cout << "Input: arr = [5, 5, 5, 5, 5, 5], target = " << target2 << endl;
    cout << "Output: " << obj.countOccurrences(arr2, target2) << endl;
    cout << "Expected: 6" << endl << endl;

    // Test Case 3
    vector<int> arr3 = {0, 0, 1, 1, 1, 2, 3};
    int target3 = 4;
    cout << "Input: arr = [0, 0, 1, 1, 1, 2, 3], target = " << target3 << endl;
    cout << "Output: " << obj.countOccurrences(arr3, target3) << endl;
    cout << "Expected: 0" << endl;

    return 0;
}
