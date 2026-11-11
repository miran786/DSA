#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int highestOccurringElement(vector<int> &nums) {
       map<int, int> freq;
      int highest =0;
      int highest_element = 0;
      for (auto num : nums)
      {
        freq[num]++;
      }
      
      for (auto entry : freq)
      {
        if(entry.second > highest)
        {
           highest = entry.second;
          highest_element = entry.first; 

        }
      }
      return highest_element;

    }
};

void run(Solution &obj, vector<int> nums, int expected) {
    cout << "Input: ";
    for (int x : nums) cout << x << " ";
    cout << endl;
    cout << "Output: " << obj.highestOccurringElement(nums) << endl;
    cout << "Expected: " << expected << endl << endl;
}

int main() {
    Solution obj;

    // Test Case 1: clear winner
    run(obj, {1, 2, 2, 3, 3, 3}, 3);

    // Test Case 2: tie, smallest wins 
    run(obj, {1, 2, 2, 3, 3}, 2);

    // Test Case 3: single element
    run(obj, {7}, 7);

    // Test Case 4: all same
    run(obj, {4, 4, 4, 4}, 4);

    // Test Case 5: all distinct (tie across all, smallest wins)
    run(obj, {9, 5, 8, 6}, 5);

    // Test Case 6: negatives, tie
    run(obj, {-1, -1, 2, 2, -3}, -1);

    // Test Case 7: all negative, single winner
    run(obj, {-5, -2, -2, -9}, -2);

    // Test Case 8: tie where the smaller value appears later
    run(obj, {5, 5, 1, 1}, 1);

    // Test Case 9: large values
    run(obj, {1000000000, 1000000000, 1}, 1000000000);

    return 0;
}
