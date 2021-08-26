#include<iostream>
#include<algorithm>
#include<vector>
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* h1 = new ListNode(0); // 虚拟结点h1 (fakeHead1)
        ListNode* h2 = new ListNode(0);
        ListNode* p = h1;
        ListNode* q = h2;
        while (head != nullptr) /* 把head 用作 cur */
        {
            if (head->val < x)
            {
                p->next = head;
                p = p->next;
            }
            else {
                q->next = head;
                q = q->next;
            }
            head = head->next;
        }        
        p->next = h2->next;
        q->next = nullptr;   /* 防止成环, 尾部需要置NULL, 且置NULL操作必须在两链表挂接之后 */

        return h1->next;
    }
};

// Test
int main()
{
    Solution sol;
    ListNode *head = new ListNode(1);  /* {1,4,3,2,5,2} */
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next = nullptr;    
    int x = 3;
    auto res = sol.partition(head, x);
    ListNode *p = res;
    while (p != nullptr)
    {
        cout << p->val << " ";
        p = p->next;
    }  

    return 0;
}