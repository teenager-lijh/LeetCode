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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy1 = new ListNode(0, list1);
        ListNode* dummy2 = new ListNode(0, list2);

        ListNode* cur1 = list1;
        ListNode* cur2 = list2;

        ListNode* res_dummy = new ListNode(0, nullptr);
        ListNode* res_last = res_dummy;

        while( cur1 != nullptr || cur2 != nullptr ) {
            // both
            if( cur1 != nullptr && cur2 != nullptr ) {
                
                if( cur1->val < cur2->val ) {
                    // delete cur1 and append to res
                    dummy1->next = cur1->next;
                    res_last->next = cur1;
                    cur1->next = nullptr;

                    // update cur1
                    cur1 = dummy1->next;
                } else {
                    // delete cur2 and append to res
                    dummy2->next = cur2->next;
                    res_last->next = cur2;
                    cur2->next = nullptr;

                    // update cur2
                    cur2 = dummy2->next;
                }
            } else if( cur1 != nullptr && cur2 == nullptr ) {
                // delete cur1 and append to res
                dummy1->next = cur1->next;
                res_last->next = cur1;
                cur1->next = nullptr;

                // update cur1
                cur1 = dummy1->next;
            } else {
                // delete cur2 and append to res
                dummy2->next = cur2->next;
                res_last->next = cur2;
                cur2->next = nullptr;

                // update cur2
                cur2 = dummy2->next;
            }
            
            res_last = res_last->next;
        }


        return res_dummy->next;
    }
};
