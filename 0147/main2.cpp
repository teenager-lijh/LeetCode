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
    ListNode* insertionSortList(ListNode* head) {
        // 使用交换链表节点的方法
        if( head == nullptr || head->next == nullptr ) {
            return head;
        }

        ListNode* dummy_head = new ListNode(-1, head);

        ListNode* pre = dummy_head;
        ListNode* cur = head;

        while( cur->next != nullptr ) {
            ListNode* pre_min = pre;
            ListNode* min = cur; 

            ListNode* pre_search = pre; 
            ListNode* search = cur;
            
            while( search != nullptr ) {
                if( search->val < min->val ) {
                    // update min
                    pre_min = pre_search;
                    min = search;
                }

                // update pre_search and search
                pre_search = pre_search->next;
                search = search->next;
            }

            // swap node
            swapNode(pre, cur, pre_min, min);

            // update cur pointer
            cur = min;

            // update index
            pre = pre->next;
            cur = cur->next;
        }

        return dummy_head->next;
    }

    void swapNode(ListNode* pre1, ListNode* node1, ListNode* pre2, ListNode* node2) {
        ListNode* next1 = node1->next;
        ListNode* next2 = node2->next;

        pre1->next = node2;

        if( node1->next != node2 ) {
            // important
            // 区分 node1 和 node2 是否相邻的情况
            node2->next = next1;
            pre2->next = node1;
        } else {
            node2->next = node1;
        }

        node1->next = next2;
    }
};    
