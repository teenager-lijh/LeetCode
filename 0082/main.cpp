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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy_head = new ListNode(0, head);

        ListNode* pre = dummy_head;
        ListNode* cur = head;

        while( cur != nullptr ) {
            if( cur->next != nullptr && cur->val == cur->next->val ) {
                // delete all val node
                int val = cur->val;
                
                while( cur != nullptr && cur->val == val ) {
                    // delete cur
                    pre->next = cur->next;
                    cur = cur->next;
                }
            } else {
                // go on
                pre = cur;
                cur = cur->next;
            }
        }

        return dummy_head->next;
    }
};
