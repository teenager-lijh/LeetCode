#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* dummy_head = new ListNode(-1, head);
        ListNode* pre = dummy_head;
        ListNode* cur = head;

        while( cur != nullptr ) {

            int count = 0;
            ListNode* dh = pre;

            for( count = 0 ; count < k && cur != nullptr ; count++ ) {
                pre = pre->next;
                cur = cur->next;
            }

            if( count == k ) {
                // update pre 这里很重要 !!!
                pre = dh->next;
                // reverse
                reverseList(dh, dh->next, cur);
            }
        }

        return dummy_head->next;
    }

    void reverseList(ListNode* dummy_head, ListNode* head, ListNode* end) {
        ListNode* pre = dummy_head;
        ListNode* cur = head;
        ListNode* next = cur->next;

        while(cur != end) {
            // update direction
            cur->next = pre;

            // update index
            pre = cur;
            cur = next;
            if( next != nullptr ) {
                next = next->next;
            }
        }

        head->next = end;
        dummy_head->next = pre;
    }
};

int main() {

    ListNode* node5 = new ListNode(5, nullptr);
    ListNode* node4 = new ListNode(4, node5);
    ListNode* node3 = new ListNode(3, node4);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* node1 = new ListNode(1, node2);

    Solution solution;

    solution.reverseKGroup(node1, 2);

    cout << "over" << endl;

    return 0;
}
