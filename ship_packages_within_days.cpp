#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int shipWithinDays(vector<int> &weights, int days) {
      int total_weight = 0;
      int low = 0;
      int high;
      for(auto i : weights)
      {
        total_weight = total_weight + i;
      }
      high = total_weight;

      while (low < high)
      {
        int mid = low + (high - low) / 2;
        int j = 0;

        for (int i = 0; i < days; i++)
        {
          int capacity = 0;
          while (j < weights.size() && capacity + weights[j] <= mid)
          {
            capacity = capacity + weights[j];
            j++;
          }
        }

        if (j >= weights.size())
        {
          high = mid;      // mid works — maybe a smaller capacity also works
        }
        else
        {
          low = mid + 1;   // mid too small — not everything got shipped
        }
      }

      return low;
    }
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> weights1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days1 = 5;
    cout << "Input: weights = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], days = " << days1 << endl;
    cout << "Output: " << obj.shipWithinDays(weights1, days1) << endl;
    cout << "Expected: 15" << endl << endl;

    // Test Case 2
    vector<int> weights2 = {3, 2, 2, 4, 1, 4};
    int days2 = 3;
    cout << "Input: weights = [3, 2, 2, 4, 1, 4], days = " << days2 << endl;
    cout << "Output: " << obj.shipWithinDays(weights2, days2) << endl;
    cout << "Expected: 6" << endl << endl;

    // Test Case 3 (edge: days=1, everything must ship in a single day)
    vector<int> weights3 = {1, 2, 3, 4, 5};
    int days3 = 1;
    cout << "Input: weights = [1, 2, 3, 4, 5], days = " << days3 << endl;
    cout << "Output: " << obj.shipWithinDays(weights3, days3) << endl;
    cout << "Expected: 15" << endl << endl;

    // Test Case 4 (edge: days = n, one package per day, capacity = max weight)
    vector<int> weights4 = {1, 2, 3, 4, 5};
    int days4 = 5;
    cout << "Input: weights = [1, 2, 3, 4, 5], days = " << days4 << endl;
    cout << "Output: " << obj.shipWithinDays(weights4, days4) << endl;
    cout << "Expected: 5" << endl;

    return 0;
}
