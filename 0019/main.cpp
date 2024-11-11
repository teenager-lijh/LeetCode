/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy_head = new ListNode(-1, head);
        ListNode* pre = dummy_head;
        ListNode* p = head;
        ListNode* q = head;

        int count = 0;
        for( ; count < n && q != nullptr ; q = q->next, count++ ) {}

        if( count != n ) {
            return nullptr;
        }

        // search
        while( q != nullptr ) {
            pre = pre->next;
            p = p->next;
            q = q->next;
        }

        // delete
        pre->next = p->next;

        return dummy_head->next;
    }
};
