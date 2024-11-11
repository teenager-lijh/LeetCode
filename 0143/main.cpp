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
    void reorderList(ListNode* head) {
        // 使用两倍速的双指针

        if( head->next == nullptr ) {
            return;
        }

        ListNode* dummy_head = new ListNode(-1, head);

        ListNode* pre_slow = dummy_head;
        ListNode* slow = head;
        ListNode* fast = head;

        while( fast != nullptr ) {
            pre_slow = pre_slow->next;
            slow = slow->next;
            if( fast->next != nullptr ) {
                fast = fast->next->next;
            } else {
                fast = nullptr;
            }
        }

        pre_slow->next = nullptr;

        dummy_head->next = nullptr;
        ListNode* res = dummy_head;
        ListNode* cur1 = head;
        ListNode* cur2 = reverseList(slow);

        while( cur1 != nullptr || cur2 != nullptr ) {
            if( cur1 != nullptr && cur2 != nullptr ) {
                ListNode* next1 = cur1->next;
                ListNode* next2 = cur2->next;

                res->next = cur1;
                cur1->next = cur2;
                cur2->next = nullptr;
                res = cur2;

                cur1 = next1;
                cur2 = next2;
            } else if( cur1 != nullptr ) {
                ListNode* next1 = cur1->next;

                res->next = cur1;
                res = cur1;
                res->next = nullptr;

                cur1 = next1;
            } else {
                // cur2 != nullptr
                ListNode* next2 = cur2->next;

                res->next = cur2;
                res = cur2;
                res->next = nullptr;

                cur2 = next2;
            }
        }

        *head = *(dummy_head->next);
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* dummy_head = new ListNode(-1, head);
        ListNode* pre = dummy_head;
        ListNode* cur = head;

        while( cur != nullptr ) {
            ListNode* next = cur->next;

            // update index
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        head->next = nullptr;
        return pre;
    }
};
