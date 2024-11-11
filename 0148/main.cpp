#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // 基于链表的自底向上的归并排序
        ListNode* dummy_head = new ListNode(-1, head);

        int size = 0;
        for( ListNode* cur = head ; cur != nullptr ; cur = cur->next ) {
            size ++;
        }

        if( size < 2 ) {
            return head;
        }

        for(int sz = 1 ; sz < size ; sz += sz ) {


            ListNode* pre_search = dummy_head;
            ListNode* search = dummy_head->next;

            while( search != nullptr ) {
                ListNode* pre1 = pre_search;
                ListNode* cur1 = search;

                ListNode* cur2 = nullptr;
                ListNode* end2 = nullptr;

                // 跳过前半部分 找到 cur2
                int sz1 = 0;
                for( ; sz1 < sz && search != nullptr  ; sz1++ ) {
                    pre_search = pre_search->next;
                    search = search->next;
                }

                if( sz1 >= sz ) {
                    cur2 = search;
                }

                // 跳过后半部分
                int sz2 = 0;
                for( ; sz2 < sz && search != nullptr ; sz2++ ) {
                    pre_search = pre_search->next;
                    search = search->next;
                }

                if( sz2 >= sz ) {
                    end2 = search;
                } else {
                    end2 = nullptr;
                }

                // 经过 merge 之后 pre_search 就发生变化了 but search 没有变化
                pre_search = mergeList(pre1, cur1, cur2, end2, sz1, sz2);
                cout << "test" << endl;
            }
        }

        return dummy_head->next;
    }


    ListNode* mergeList(ListNode* pre1, ListNode* cur1, ListNode* cur2, ListNode* end2, int sz1, int sz2) {
        ListNode* head = new ListNode(-1, nullptr);
        ListNode* cur = head;

        while( sz1 > 0 || sz2 > 0 ) {
            if( sz1 > 0 && sz2 > 0 && cur1->val < cur2->val ) {
                cur->next = cur1;
                cur = cur1;
                cur1 = cur1->next;
                cur->next = nullptr;
                sz1 --;
            } else if( sz1 > 0 && sz2 > 0 && cur1->val > cur2->val ) {
                cur->next = cur2;
                cur = cur2;
                cur2 = cur2->next;
                sz2 --;
            } else if( sz1 > 0 && sz2 <= 0 ) {
                // 只剩下 cur1 了
                cur->next = cur1;
                cur = cur1;
                cur1 = cur1->next;
                cur->next = nullptr;
                sz1 --;
            } else {
                // 只剩下 cur2 了
                cur->next = cur2;
                cur = cur2;
                cur2 = cur2->next;
                sz2 --;
            }
        }

        pre1->next = head->next;
        cur->next = end2;

        // return pre_search
        return cur;
    }
};

int main() {

    ListNode* node4 = new ListNode(3, nullptr);
    ListNode* node3 = new ListNode(1, node4);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* node1 = new ListNode(4, node2);



    Solution solution;

    solution.sortList(node1);

    cout << "over" << endl;

    return 0;
}