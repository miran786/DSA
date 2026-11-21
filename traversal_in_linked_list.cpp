#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

class Solution {
  public:
    vector<int> traverseLinkedList(Node* head) {
        vector<int> result;
        Node *curr = head;

        while (curr !=nullptr)
        {
            result.push_back(curr->data);
            curr = curr-> next;
        }
        return result;
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

void printVector(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i + 1 < v.size()) cout << ", ";
    }
    cout << "]";
}

int main() {
    Solution obj;

    // Test Case 1 (Example 1)
    vector<int> input1 = {5, 4, 3, 1, 0};
    vector<int> output1 = obj.traverseLinkedList(buildList(input1));
    cout << "Input: "; printVector(input1); cout << endl;
    cout << "Output: "; printVector(output1); cout << endl;
    cout << "Expected: [5, 4, 3, 1, 0]" << endl << endl;

    // Test Case 2 (Example 2)
    vector<int> input2 = {1};
    vector<int> output2 = obj.traverseLinkedList(buildList(input2));
    cout << "Input: "; printVector(input2); cout << endl;
    cout << "Output: "; printVector(output2); cout << endl;
    cout << "Expected: [1]" << endl << endl;

    // Test Case 3 (edge: empty list, head is nullptr)
    vector<int> input3 = {};
    vector<int> output3 = obj.traverseLinkedList(buildList(input3));
    cout << "Input: "; printVector(input3); cout << endl;
    cout << "Output: "; printVector(output3); cout << endl;
    cout << "Expected: []" << endl << endl;

    // Test Case 4 (edge: two nodes)
    vector<int> input4 = {2, 9};
    vector<int> output4 = obj.traverseLinkedList(buildList(input4));
    cout << "Input: "; printVector(input4); cout << endl;
    cout << "Output: "; printVector(output4); cout << endl;
    cout << "Expected: [2, 9]" << endl << endl;

    // Test Case 5 (edge: all values the same)
    vector<int> input5 = {7, 7, 7, 7};
    vector<int> output5 = obj.traverseLinkedList(buildList(input5));
    cout << "Input: "; printVector(input5); cout << endl;
    cout << "Output: "; printVector(output5); cout << endl;
    cout << "Expected: [7, 7, 7, 7]" << endl << endl;

    // Test Case 6 (edge: negatives and zero)
    vector<int> input6 = {-1, 0, -3};
    vector<int> output6 = obj.traverseLinkedList(buildList(input6));
    cout << "Input: "; printVector(input6); cout << endl;
    cout << "Output: "; printVector(output6); cout << endl;
    cout << "Expected: [-1, 0, -3]" << endl << endl;

    return 0;
}
