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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* cur = head;
        ListNode* pre = nullptr;
        ListNode* next = cur->next;;

        ListNode* l = nullptr;
        ListNode* r = nullptr;

        ListNode* l_node = nullptr;
        ListNode* r_node = nullptr;



        for( int i = 1 ; i <= right ; i++ ) {
            if( i == 1 ) {
                pre = nullptr;
                cur = head;
                next = cur->next;
            } else {
                pre = cur;
                cur = next;
                next = next->next;
            }

            if( i == left ) {
                l = cur;
                l_node = pre;
            }
            if( i == right ) {
                r = cur;
                r_node = next;
            }

            if( i >= left ) {
                cur->next = pre;
            }
        }

        if( l_node != nullptr ) {
            l_node->next = r;
        }
        
        l->next = r_node;

        if( left == 1 ) {
            return r;
        } else {
            return head;
        }
    }
};
