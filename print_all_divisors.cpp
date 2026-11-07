#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> printAllDivisors(int n) {
      vector<int> result;
      for (int i = 1; i <= n; i++)
      {
          if( n%i ==0)
          {
            result.push_back(i);
          }


      }
      return result;
    }
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> result1 = obj.printAllDivisors(12);
    cout << "Input: n = 12" << endl;
    cout << "Output: ";
    for (int x : result1) cout << x << " ";
    cout << endl;
    cout << "Expected: 1 2 3 4 6 12" << endl << endl;

    // Test Case 2
    vector<int> result2 = obj.printAllDivisors(10);
    cout << "Input: n = 10" << endl;
    cout << "Output: ";
    for (int x : result2) cout << x << " ";
    cout << endl;
    cout << "Expected: 1 2 5 10" << endl << endl;

    // Test Case 3
    vector<int> result3 = obj.printAllDivisors(1);
    cout << "Input: n = 1" << endl;
    cout << "Output: ";
    for (int x : result3) cout << x << " ";
    cout << endl;
    cout << "Expected: 1" << endl;

    return 0;
}
