#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int secondMostFrequent(vector<int> &arr) {
      map <int,int> freq;
      int highest_key = 0;
      int highest_value = 0;
      int hight_second_key=0;
      int hight_second_value=0;
      
      for(auto i : arr)
      {
        freq[i]++;
      }

      for(auto j : freq)
      {
        if(j.second > highest_value)
        {
          highest_value = j.second;
          highest_key = j.first;
        }
      }

      for(auto k : freq)
      {
        if(k.second<highest_value)
        {
          hight_second_key=k.first;
          hight_second_value= k.second;
        }
      }

      return hight_second_key;
    }
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> arr1 = {1, 2, 2, 3, 3, 3};
    cout << "Input: arr = [1, 2, 2, 3, 3, 3]" << endl;
    cout << "Output: " << obj.secondMostFrequent(arr1) << endl;
    cout << "Expected: 2" << endl << endl;

    // Test Case 2
    vector<int> arr2 = {4, 4, 5, 5, 6, 7};
    cout << "Input: arr = [4, 4, 5, 5, 6, 7]" << endl;
    cout << "Output: " << obj.secondMostFrequent(arr2) << endl;
    cout << "Expected: 6" << endl << endl;

    // Test Case 3 (edge: single element)
    vector<int> arr3 = {5};
    cout << "Input: arr = [5]" << endl;
    cout << "Output: " << obj.secondMostFrequent(arr3) << endl;
    cout << "Expected: -1" << endl << endl;

    // Test Case 4 (edge: all elements the same)
    vector<int> arr4 = {7, 7, 7};
    cout << "Input: arr = [7, 7, 7]" << endl;
    cout << "Output: " << obj.secondMostFrequent(arr4) << endl;
    cout << "Expected: -1" << endl << endl;

    // Test Case 5 (edge: all distinct, every element has the same frequency)
    vector<int> arr5 = {1, 2, 3, 4};
    cout << "Input: arr = [1, 2, 3, 4]" << endl;
    cout << "Output: " << obj.secondMostFrequent(arr5) << endl;
    cout << "Expected: -1" << endl << endl;

    // Test Case 6 (edge: two distinct elements with different counts)
    vector<int> arr6 = {1, 1, 2};
    cout << "Input: arr = [1, 1, 2]" << endl;
    cout << "Output: " << obj.secondMostFrequent(arr6) << endl;
    cout << "Expected: 2" << endl << endl;

    // Test Case 7 (edge: tie for the top frequency, then a lower one)
    vector<int> arr7 = {2, 2, 1, 1, 3};
    cout << "Input: arr = [2, 2, 1, 1, 3]" << endl;
    cout << "Output: " << obj.secondMostFrequent(arr7) << endl;
    cout << "Expected: 3" << endl << endl;

    // Test Case 8 (edge: tie for second place, smallest wins)
    vector<int> arr8 = {3, 3, 3, 2, 2, 1, 1, 0};
    cout << "Input: arr = [3, 3, 3, 2, 2, 1, 1, 0]" << endl;
    cout << "Output: " << obj.secondMostFrequent(arr8) << endl;
    cout << "Expected: 1" << endl << endl;

    // Test Case 9 (edge: negative values)
    vector<int> arr9 = {-1, -1, -2, -2, -2, -3};
    cout << "Input: arr = [-1, -1, -2, -2, -2, -3]" << endl;
    cout << "Output: " << obj.secondMostFrequent(arr9) << endl;
    cout << "Expected: -1" << endl;

    return 0;
}
