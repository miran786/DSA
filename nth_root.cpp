#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int NthRoot(int n, int m) {
      int low = 0 ;
      int high = m;
      while(low <= high)
    {
      int mid = low + (high - low) /2 ;
      int value = pow(mid,n);

      if(value == m)
      {
        return mid;
      }


      if(value > m)
      {
        high = mid-1;
      }
      else
      {
        low = mid +1;
      }
      

    }
     
  
  
    return -1;
  }
};

int main() {
    Solution obj;

    // Test Case 1
    cout << "Input: N = 3, M = 27" << endl;
    cout << "Output: " << obj.NthRoot(3, 27) << endl;
    cout << "Expected: 3" << endl << endl;

    // Test Case 2
    cout << "Input: N = 4, M = 69" << endl;
    cout << "Output: " << obj.NthRoot(4, 69) << endl;
    cout << "Expected: -1" << endl << endl;

    // Test Case 3 (edge: N = 1, root of anything is itself)
    cout << "Input: N = 1, M = 5" << endl;
    cout << "Output: " << obj.NthRoot(1, 5) << endl;
    cout << "Expected: 5" << endl << endl;

    // Test Case 4 (edge: M = 1, root of 1 is always 1)
    cout << "Input: N = 2, M = 1" << endl;
    cout << "Output: " << obj.NthRoot(2, 1) << endl;
    cout << "Expected: 1" << endl;

    return 0;
}
