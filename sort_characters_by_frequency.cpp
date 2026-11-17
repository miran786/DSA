#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<char> frequencySort(string s) {
        map <char,int> freq;
        string ans;
        for(char i : s)
        {
            freq[i]++;
        }
        
        vector<pair<char,int>> order(freq.begin(), freq.end());

        sort(order.begin(), order.end(), [](const pair<char,int>& a, const pair<char,int>& b) {
            if (a.second != b.second) { return a.second > b.second; }
            return a.first < b.first;
        });

        vector<char> res;
        for(auto j : order)
        {
            res.push_back(j.first);
         
        }
        return res;
    }
};

int main() {
    Solution obj;

    auto show = [](const vector<char>& chars) {
        string out = "[";
        for (size_t i = 0; i < chars.size(); i++) {
            out += "'";
            out += chars[i];
            out += "'";
            if (i + 1 < chars.size()) out += ", ";
        }
        return out + "]";
    };

    // Test Case 1 (problem example 1)
    string s1 = "tree";
    cout << "Input: " << s1 << endl;
    cout << "Output: " << show(obj.frequencySort(s1)) << endl;
    cout << "Expected: ['e', 'r', 't']" << endl << endl;

    // Test Case 2 (problem example 2)
    string s2 = "raaaajj";
    cout << "Input: " << s2 << endl;
    cout << "Output: " << show(obj.frequencySort(s2)) << endl;
    cout << "Expected: ['a', 'j', 'r']" << endl << endl;

    // Test Case 3 (edge: empty string)
    string s3 = "";
    cout << "Input: " << s3 << endl;
    cout << "Output: " << show(obj.frequencySort(s3)) << endl;
    cout << "Expected: []" << endl << endl;

    // Test Case 4 (edge: single character)
    string s4 = "z";
    cout << "Input: " << s4 << endl;
    cout << "Output: " << show(obj.frequencySort(s4)) << endl;
    cout << "Expected: ['z']" << endl << endl;

    // Test Case 5 (edge: all same character)
    string s5 = "bbbb";
    cout << "Input: " << s5 << endl;
    cout << "Output: " << show(obj.frequencySort(s5)) << endl;
    cout << "Expected: ['b']" << endl << endl;

    // Test Case 6 (edge: all characters distinct, alphabetical order)
    string s6 = "dcba";
    cout << "Input: " << s6 << endl;
    cout << "Output: " << show(obj.frequencySort(s6)) << endl;
    cout << "Expected: ['a', 'b', 'c', 'd']" << endl << endl;

    // Test Case 7 (edge: every frequency tied, alphabetical tie-break)
    string s7 = "ccbbaa";
    cout << "Input: " << s7 << endl;
    cout << "Output: " << show(obj.frequencySort(s7)) << endl;
    cout << "Expected: ['a', 'b', 'c']" << endl << endl;

    // Test Case 8 (edge: highest frequency is not the alphabetically first character)
    string s8 = "abbbcc";
    cout << "Input: " << s8 << endl;
    cout << "Output: " << show(obj.frequencySort(s8)) << endl;
    cout << "Expected: ['b', 'c', 'a']" << endl << endl;

    return 0;
}
