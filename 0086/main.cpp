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
    ListNode* partition(ListNode* head, int x) {
        // 分裂链表
        // 让比 x 小的放在左边
        // 大于或等于 x 的按照原链表中的相对位置放在右边
        ListNode* less_than = nullptr;
        ListNode* less_than_cur = nullptr;

        ListNode* greater_than = nullptr;
        ListNode* greater_than_cur = nullptr;

        ListNode* cur = head;

        while( cur != nullptr ) {
            int val = cur->val;
            ListNode* next = cur->next;

            if( val < x ) {
                if( less_than == nullptr ) {
                    less_than = cur;
                } else {
                    less_than_cur->next = cur;
                }
                less_than_cur = cur;
            }

            if( val >= x ) {
                if( greater_than == nullptr ) {
                    greater_than = cur;
                } else {
                    greater_than_cur->next = cur;
                }
                greater_than_cur = cur;
            }
            
            cur->next = nullptr;
            cur = next;
        }

        if( less_than_cur != nullptr && greater_than != nullptr ) {
            less_than_cur->next = greater_than;
            return less_than;
        }

        if( less_than != nullptr ) {
            return less_than;
        }
        
        return greater_than;
    }
};
