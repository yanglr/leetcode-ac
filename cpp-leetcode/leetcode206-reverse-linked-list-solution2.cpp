#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *cur = head;
        ListNode *newHead = NULL;
        if (cur == NULL)
            return head;

        while (cur != NULL)
        {
            ListNode *pre = cur;
            cur = cur->next;
            pre->next = newHead;
            newHead = pre; /* 由于此处不是用newHead的next指针进行挂接，故直接return newHead即可。 */
        }

        return newHead;
    }
};

// Test
int main()
{
    Solution sol;

    ListNode *head = new ListNode(5);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(8);
    head->next->next->next->next = NULL;

    ListNode *res = sol.reverseList(head);
    ListNode *p = res;
    while (p != NULL)
    {
        cout << p->val << endl;
        p = p->next;
    }

    return 0;
}