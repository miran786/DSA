#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void printNTo1(int n) {
      if(n<=0)
      {
        return;
      }
      cout<<n<<endl;
      printNTo1(n-1);
      
    }
};

int main() {
    Solution obj;

    // Test Case 1
    cout << "Input: n = 5" << endl;
    cout << "Output:" << endl;
    obj.printNTo1(5);
    cout << "Expected: 5 4 3 2 1 (each on separate line)" << endl << endl;

    // Test Case 2
    cout << "Input: n = 1" << endl;
    cout << "Output:" << endl;
    obj.printNTo1(1);
    cout << "Expected: 1" << endl << endl;

    // Test Case 3
    cout << "Input: n = 3" << endl;
    cout << "Output:" << endl;
    obj.printNTo1(3);
    cout << "Expected: 3 2 1 (each on separate line)" << endl;

    return 0;
}
