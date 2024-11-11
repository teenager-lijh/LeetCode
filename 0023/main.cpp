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
// 优先队列 + 归并
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy_head = new ListNode(-1, nullptr);
        ListNode* cur = dummy_head;

        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

        for( int i = 0 ; i < lists.size() ; i++ ) {
            if( lists[i] != nullptr ) {
                pq.push(make_pair(lists[i]->val, lists[i]));
            }
        }

        while(!pq.empty()) {
            pair<int, ListNode*> cur_pair = pq.top();
            pq.pop();
            int v = cur_pair.first;
            ListNode* p = cur_pair.second;
            cur->next = new ListNode(v, nullptr);
            cur = cur->next;
            
            if( p->next != nullptr ) {
                pq.push(make_pair(p->next->val, p->next));
            }
        }

        return dummy_head->next;
    }
};
