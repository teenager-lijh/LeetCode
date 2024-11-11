/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* node1 = node->next;
        ListNode* node2 = node1->next;

        node->val = node1->val;
        node->next = node2;
    }
};
