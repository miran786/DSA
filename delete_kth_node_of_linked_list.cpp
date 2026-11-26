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
    ListNode* deleteKthNode(ListNode* head, int k) {
        
        ListNode* curr = head;
        ListNode* prev = head;
        if(k == 1)
        {
            head = curr->next;
            return head;
        }
        int count = 0;
        while (curr != nullptr)
        {   
            count++;
            if(count == k)
            {
                prev->next = curr->next;
                return head;
            }
            prev = curr;
            curr = curr->next;
           
        }
        
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

    // Test Case 1 (Example 1: middle node)
    ListNode* head1 = buildList({3, 4, 5});
    cout << "Input: [3, 4, 5], k = 2" << endl;
    ListNode* output1 = obj.deleteKthNode(head1, 2);
    cout << "Output: "; printList(output1); cout << endl;
    cout << "Expected: [3, 5]" << endl << endl;

    // Test Case 2 (Example 2: k = 1, head is removed)
    ListNode* head2 = buildList({1, 2, 3});
    cout << "Input: [1, 2, 3], k = 1" << endl;
    ListNode* output2 = obj.deleteKthNode(head2, 1);
    cout << "Output: "; printList(output2); cout << endl;
    cout << "Expected: [2, 3]" << endl << endl;

    // Test Case 3 (edge: single node, k = 1, list becomes empty)
    ListNode* head3 = buildList({5});
    cout << "Input: [5], k = 1" << endl;
    ListNode* output3 = obj.deleteKthNode(head3, 1);
    cout << "Output: "; printList(output3); cout << endl;
    cout << "Expected: []" << endl << endl;

    // Test Case 4 (edge: k = last node, tail is removed)
    ListNode* head4 = buildList({1, 2, 3});
    cout << "Input: [1, 2, 3], k = 3" << endl;
    ListNode* output4 = obj.deleteKthNode(head4, 3);
    cout << "Output: "; printList(output4); cout << endl;
    cout << "Expected: [1, 2]" << endl << endl;

    // Test Case 5 (edge: two nodes, k = 2)
    ListNode* head5 = buildList({4, 9});
    cout << "Input: [4, 9], k = 2" << endl;
    ListNode* output5 = obj.deleteKthNode(head5, 2);
    cout << "Output: "; printList(output5); cout << endl;
    cout << "Expected: [4]" << endl << endl;

    // Test Case 6 (edge: all values the same, middle position removed)
    ListNode* head6 = buildList({7, 7, 7});
    cout << "Input: [7, 7, 7], k = 2" << endl;
    ListNode* output6 = obj.deleteKthNode(head6, 2);
    cout << "Output: "; printList(output6); cout << endl;
    cout << "Expected: [7, 7]" << endl << endl;

    return 0;
}
