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
        // 使用交换元素的方法 不拆分链表

        if( head == nullptr ) {
            return head;
        }

        ListNode* cur = head;

        while( cur->next != nullptr ) {
            // 如果只剩下一个元素没有排序 那就不用排了
            ListNode* min = cur->next;
            ListNode* search = cur;
            while( search != nullptr ) {
                if( search->val < min->val ) {
                    min = search;
                }
                search = search->next;
            }

            // swap value
            swap(cur->val, min->val);

            // update cur
            cur = cur->next;
        }

        return head;
    }
};
