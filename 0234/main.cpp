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
    bool isPalindrome(ListNode* head) {
        // 双指针 链表翻转
        if( head == nullptr || head->next == nullptr ) {
            return true;
        }

        ListNode* new_head_pre = findNewHeadPre(head);
        ListNode* new_head = reverseList(new_head_pre->next);
        new_head_pre->next = nullptr;

        ListNode* cur1 = head;
        ListNode* cur2 = new_head;

        while( cur1 != nullptr && cur2 != nullptr ) {
            if( cur1->val != cur2->val ) {
                return false;
            }
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        
        return true;
    }

    ListNode* findNewHeadPre(ListNode* head) {
        ListNode* dummy = new ListNode(-1, head);

        ListNode* pre_slow = dummy;
        ListNode* slow = head;
        ListNode* fast = head;

        while( fast != nullptr ) {
            pre_slow = slow;
            slow = slow->next;
            fast = fast->next != nullptr ? fast->next->next : nullptr;
        }

        delete dummy;
        return pre_slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* dummy = new ListNode(-1, head);

        ListNode* pre = dummy;
        ListNode* cur = head;

        while( cur != nullptr ) {
            ListNode* next = cur->next;

            cur->next = pre;
            pre = cur;
            cur = next;
        }

        dummy->next->next = nullptr;
        delete dummy;
        
        return pre;
    }
};
