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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 对链表存储的整型实现加法运算
        int rest = 0;
        ListNode* prev = nullptr;
        ListNode* l1_cur = l1;
        ListNode* res_cur = l2;

        while( res_cur != nullptr ) {
            int l1_val = 0;
            if( l1_cur != nullptr ) {
                l1_val = l1_cur->val;
            }

            int res = l1_val + res_cur->val + rest;
            if( res >= 10 ) {
                rest = 1;
            } else {
                rest = 0;
            }

            res_cur->val = res % 10;

            if( res_cur->next == nullptr && (l1_cur != nullptr && l1_cur->next != nullptr || rest != 0) ) {
                res_cur->next = new ListNode(0, nullptr);
            }

            // 更新 cur
            if( l1_cur != nullptr ) {
                l1_cur = l1_cur->next;
            }

            res_cur = res_cur->next;

        }

        return l2;
    }
};
