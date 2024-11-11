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
    ListNode* oddEvenList(ListNode* head) {
        // 根据链表节点的奇数偶数位置 对链表分组 奇数一组 偶数一组 保持原有的相对顺序
        ListNode* lh = nullptr;  // left head
        ListNode* rh = nullptr;  // right head

        ListNode* lc = nullptr;  // left current
        ListNode* rc = nullptr;  // right current

        ListNode* cur = head;  // current
        bool is_left = true;

        while( cur != nullptr ) {
            ListNode* next = cur->next;
            if( is_left ) {
                if( lh == nullptr ) {
                    lh = cur;
                } else {
                    lc->next = cur;
                }
                lc = cur;
                lc->next = nullptr;
            }

            if( !is_left ) {
                if( rh == nullptr ) {
                    rh = cur;
                } else {
                    rc->next = cur;
                }
                rc = cur;
                rc->next = nullptr;
            }
            
            cur = next;
            is_left = !is_left;
        }

        if( lc != nullptr ) {
            lc->next = rh;
        }

        if( lh != nullptr ) {
            return lh;
        }

        return rh;
    }
};
