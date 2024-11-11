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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if( head == nullptr || k == 0 ) {
            return head;
        }

        // 相当于是删除链表尾部的 k 个节点 然后拼接在链表的头部
        ListNode* dummy_head = new ListNode(-1, head);
        ListNode* pre_p = dummy_head;
        ListNode* p = head;
        ListNode* pre_q = dummy_head;
        ListNode* q = head;

        int count = 0;
        while( count < k && q != nullptr ) {
            // update
            count ++;
            pre_q = pre_q->next;
            q = q->next;
        }

        // k 等于链表长度的情况
        if( q == nullptr && k % count == 0 ) {
            return head;
        }

        // k 大于链表长度的情况
        if( count < k ) {
            k = k % count; // 若 k 大于链表长度 则 k 的有效次数等价于 k % count

            // 重新寻找 q 的正确位置
            pre_q = dummy_head;
            q = head;
            count = 0;
            while( count < k && q != nullptr ) {
                // update
                count ++;
                pre_q = pre_q->next;
                q = q->next;
            }
        }

        while( q != nullptr ) {
            pre_p = pre_p->next;
            p = p->next;

            pre_q = pre_q->next;
            q = q->next;
        }

        // rotate
        pre_q->next = dummy_head->next;
        dummy_head->next = p;
        pre_p->next = nullptr;

        return dummy_head->next;

    }
};
