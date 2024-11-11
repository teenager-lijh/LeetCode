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
    ListNode* deleteDuplicates(ListNode* head) {
        // 使用有序的查找表对链表去重并排序
        set<int> record;

        ListNode* cur = head;

        while(cur != nullptr) {
            record.insert(cur->val);
            cur = cur->next;
        }
        
        ListNode* pre = nullptr;
        cur = head;
        for(set<int>::iterator iter = record.begin() ; iter != record.end() ; iter++) {
            cur->val = *iter;
            pre = cur;

            if(cur != nullptr)
                cur = cur->next;
        }

        if(pre != nullptr)
            pre->next = nullptr;

        return head;
    }
};
