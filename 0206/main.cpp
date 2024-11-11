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
    ListNode* reverseList(ListNode* head) {
        // 反转链表
        
        if( head == nullptr ) {
            return nullptr;
        }

        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* next = cur->next;

        while( cur != nullptr ) {
            cur->next = pre;

            pre = cur;
            cur = next;
            if(next != nullptr) {
                next = next->next;
            }
        }

        return pre;
    }
};
