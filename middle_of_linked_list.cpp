#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

class Solution {
  public:
    Node* middleNode(Node* head) {
        vector<int> arr;
        Node *curr = head;
        Node *ans= head;
        int count = 0;
        while( curr != nullptr)
        {
            arr.push_back(curr->data);
            curr = curr -> next;
            count++;
        }
        
        int n = arr.size();
        int middle_element_index = (n/2)-1;
      
    
        for (int i = 0; i <= middle_element_index; i++)
        {
            ans=ans->next;
        }
        
        

        return ans;
    }
};

Node* buildList(const vector<int>& vals) {
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int v : vals) {
        Node* node = new Node(v);
        if (!head) head = node;
        else tail->next = node;
        tail = node;
    }
    return head;
}

// Prints the list starting at `node` to the end, e.g. [3, 4, 5]
void printFrom(Node* node) {
    cout << "[";
    bool first = true;
    for (Node* cur = node; cur != nullptr; cur = cur->next) {
        if (!first) cout << ", ";
        cout << cur->data;
        first = false;
    }
    cout << "]";
}

int main() {
    Solution obj;

    // Test Case 1 (Example 1: odd length, middle is 3)
    vector<int> input1 = {1, 2, 3, 4, 5};
    Node* output1 = obj.middleNode(buildList(input1));
    cout << "Input: [1, 2, 3, 4, 5]" << endl;
    cout << "Output: "; printFrom(output1); cout << endl;
    cout << "Expected: [3, 4, 5]" << endl << endl;

    // Test Case 2 (Example 2: even length, return the second middle)
    vector<int> input2 = {1, 2, 3, 4, 5, 6};
    Node* output2 = obj.middleNode(buildList(input2));
    cout << "Input: [1, 2, 3, 4, 5, 6]" << endl;
    cout << "Output: "; printFrom(output2); cout << endl;
    cout << "Expected: [4, 5, 6]" << endl << endl;

    // Test Case 3 (edge: single node)
    vector<int> input3 = {42};
    Node* output3 = obj.middleNode(buildList(input3));
    cout << "Input: [42]" << endl;
    cout << "Output: "; printFrom(output3); cout << endl;
    cout << "Expected: [42]" << endl << endl;

    // Test Case 4 (edge: two nodes, second one is the middle)
    vector<int> input4 = {8, 9};
    Node* output4 = obj.middleNode(buildList(input4));
    cout << "Input: [8, 9]" << endl;
    cout << "Output: "; printFrom(output4); cout << endl;
    cout << "Expected: [9]" << endl << endl;

    // Test Case 5 (edge: three nodes, exact middle)
    vector<int> input5 = {10, 20, 30};
    Node* output5 = obj.middleNode(buildList(input5));
    cout << "Input: [10, 20, 30]" << endl;
    cout << "Output: "; printFrom(output5); cout << endl;
    cout << "Expected: [20, 30]" << endl << endl;

    // Test Case 6 (edge: four nodes, even length, second middle is 3)
    vector<int> input6 = {1, 2, 3, 4};
    Node* output6 = obj.middleNode(buildList(input6));
    cout << "Input: [1, 2, 3, 4]" << endl;
    cout << "Output: "; printFrom(output6); cout << endl;
    cout << "Expected: [3, 4]" << endl << endl;

    return 0;
}
