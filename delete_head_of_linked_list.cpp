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
    ListNode* deleteHead(ListNode* &head) {
        if (head == nullptr) return head;
        head = head->next;
        return head;
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
    ListNode* head1 = buildList({1, 2, 3});
    cout << "Input: [1, 2, 3]" << endl;
    ListNode* output1 = obj.deleteHead(head1);
    cout << "Output: "; printList(output1); cout << endl;
    cout << "Expected: [2, 3]" << endl << endl;

    // Test Case 2 (Example 2: single node, list becomes empty)
    ListNode* head2 = buildList({1});
    cout << "Input: [1]" << endl;
    ListNode* output2 = obj.deleteHead(head2);
    cout << "Output: "; printList(output2); cout << endl;
    cout << "Expected: []" << endl << endl;

    // Test Case 3 (edge: empty list, head is nullptr)
    ListNode* head3 = buildList({});
    cout << "Input: []" << endl;
    ListNode* output3 = obj.deleteHead(head3);
    cout << "Output: "; printList(output3); cout << endl;
    cout << "Expected: []" << endl << endl;

    // Test Case 4 (edge: two nodes)
    ListNode* head4 = buildList({4, 9});
    cout << "Input: [4, 9]" << endl;
    ListNode* output4 = obj.deleteHead(head4);
    cout << "Output: "; printList(output4); cout << endl;
    cout << "Expected: [9]" << endl << endl;

    // Test Case 5 (edge: all values the same)
    ListNode* head5 = buildList({7, 7, 7});
    cout << "Input: [7, 7, 7]" << endl;
    ListNode* output5 = obj.deleteHead(head5);
    cout << "Output: "; printList(output5); cout << endl;
    cout << "Expected: [7, 7]" << endl << endl;

    return 0;
}
