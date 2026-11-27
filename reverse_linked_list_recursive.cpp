#include <bits/stdc++.h>
using namespace std;

class ListNode {
  public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};

class Solution {
  public:
    ListNode* reverseList(ListNode* head) {
    
    }
};

ListNode* buildList(const vector<int>& vals) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int v : vals) {
        ListNode* node = new ListNode(v);
        if (!head) head = node;
        else tail->next = node;
        tail = node;
    }
    return head;
}

void printList(ListNode* node) {
    cout << "[";
    bool first = true;
    for (ListNode* cur = node; cur != nullptr; cur = cur->next) {
        if (!first) cout << ", ";
        cout << cur->data;
        first = false;
    }
    cout << "]";
}

int main() {
    Solution obj;

    // Test Case 1 (Example 1)
    ListNode* head1 = buildList({1, 2, 3, 4, 5});
    cout << "Input: [1, 2, 3, 4, 5]" << endl;
    ListNode* output1 = obj.reverseList(head1);
    cout << "Output: "; printList(output1); cout << endl;
    cout << "Expected: [5, 4, 3, 2, 1]" << endl << endl;

    // Test Case 2 (Example 2)
    ListNode* head2 = buildList({1, 2});
    cout << "Input: [1, 2]" << endl;
    ListNode* output2 = obj.reverseList(head2);
    cout << "Output: "; printList(output2); cout << endl;
    cout << "Expected: [2, 1]" << endl << endl;

    // Test Case 3 (Example 3: empty list)
    ListNode* head3 = buildList({});
    cout << "Input: []" << endl;
    ListNode* output3 = obj.reverseList(head3);
    cout << "Output: "; printList(output3); cout << endl;
    cout << "Expected: []" << endl << endl;

    // Test Case 4 (edge: single node, base case)
    ListNode* head4 = buildList({7});
    cout << "Input: [7]" << endl;
    ListNode* output4 = obj.reverseList(head4);
    cout << "Output: "; printList(output4); cout << endl;
    cout << "Expected: [7]" << endl << endl;

    // Test Case 5 (edge: all values the same)
    ListNode* head5 = buildList({3, 3, 3});
    cout << "Input: [3, 3, 3]" << endl;
    ListNode* output5 = obj.reverseList(head5);
    cout << "Output: "; printList(output5); cout << endl;
    cout << "Expected: [3, 3, 3]" << endl << endl;

    // Test Case 6 (edge: negatives and the value bounds)
    ListNode* head6 = buildList({-5000, 0, 5000});
    cout << "Input: [-5000, 0, 5000]" << endl;
    ListNode* output6 = obj.reverseList(head6);
    cout << "Output: "; printList(output6); cout << endl;
    cout << "Expected: [5000, 0, -5000]" << endl << endl;

    return 0;
}
