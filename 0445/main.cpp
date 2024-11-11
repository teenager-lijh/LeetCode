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

        ListNode* reverse_l1 = reverseList(l1);
        ListNode* reverse_l2 = reverseList(l2);

        ListNode* res = addTwoNums(reverse_l1, reverse_l2);

        res = reverseList(res);

        return res;
    }


    ListNode* reverseList(ListNode* list) {
        ListNode* pre = nullptr;
        ListNode* cur = list;
        ListNode* next = list->next;

        while( cur != nullptr ) {
            cur->next = pre;

            // 更新 index
            pre = cur;
            cur = next;

            if( next != nullptr ) {
                next = next->next;
            }
        }

        return pre;
    }

    ListNode* addTwoNums(ListNode* l1, ListNode* l2) {
        int rest = 0;

        ListNode* l1_cur = l1;
        ListNode* l2_cur = l2;  // res

        while( l2_cur != nullptr ) {
            int v1 = 0;
            int v2 = l2_cur->val;
            
            if( l1_cur != nullptr ) {
                v1 = l1_cur->val;
            }

            int res = v1 + v2 + rest;
            l2_cur->val = res % 10;

            // update rest
            if( res >= 10 ) {
                rest = 1;
            } else {
                rest = 0;
            }

            // update index
            if(l2_cur->next == nullptr && (l1_cur != nullptr && l1_cur->next != nullptr || rest != 0) ) {
                l2_cur->next = new ListNode(0, nullptr);
            }

            if( l1_cur != nullptr ) {
                l1_cur = l1_cur->next;
            }

            l2_cur = l2_cur->next;
        }

        return l2;
    }
};
