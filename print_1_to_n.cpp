#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  int i =0;
    void print1ToN(int n) {
      if(n<=0)
      {
        return;
      }
      print1ToN(n-1);
      cout<<n<<endl;
    }
};

int main() {
    Solution obj;

    // Test Case 1
    cout << "Input: n = 5" << endl;
    cout << "Output:" << endl;
    obj.print1ToN(5);
    cout << "Expected: 1 2 3 4 5 (each on separate line)" << endl << endl;

    // Test Case 2
    cout << "Input: n = 1" << endl;
    cout << "Output:" << endl;
    obj.print1ToN(1);
    cout << "Expected: 1" << endl << endl;

    // Test Case 3
    cout << "Input: n = 3" << endl;
    cout << "Output:" << endl;
    obj.print1ToN(3);
    cout << "Expected: 1 2 3 (each on separate line)" << endl;

    return 0;
}
