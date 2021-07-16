#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 迭代地删除开头的结点 
        while (head != NULL && head->val == val) { /* 注意这里用while, 而不是if */
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }

        // 删除非开头的结点
        ListNode* p = head;
        while (p != NULL && p->next!= NULL) {
            if ((p->next)->val == val) {       // 此时 p 就是pre结点
                ListNode* tmp = p->next;
                p->next = p->next->next;
                delete tmp; 
            } else {
                p = p->next;
            }
        }
        return head;
    }
};

// Test
int main()
{
    Solution sol;

    ListNode *head = new ListNode(7);
    head->next = new ListNode(7);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(7);
    head->next->next->next->next = NULL;
    int target = 7;

    ListNode *res = sol.removeElements(head, target);
    ListNode *p = res;
    while (p != NULL)
    {
        cout << p->val << endl;
        p = p->next;
    }

    return 0;
}