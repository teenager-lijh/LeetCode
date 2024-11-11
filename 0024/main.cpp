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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy_head = new ListNode(0, head);

        ListNode* pre = dummy_head;
        ListNode* cur = head;
        ListNode* next;

        if( cur != nullptr ) {
            next = head->next;
        } else {
            next = nullptr;
        }
        
        while( cur != nullptr && next != nullptr ) {
            // swap
            cur->next = next->next;
            next->next = cur;
            pre->next = next;

            // update index
            pre = cur;
            cur = cur->next;
            if( cur != nullptr ) {
                next = cur->next;
            } else {
                next = nullptr;
            }
            
        }

        return dummy_head->next;
    }
};
