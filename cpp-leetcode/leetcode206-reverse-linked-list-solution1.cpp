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
        if (head == NULL)
            return NULL;
        ListNode *cur = head;
        ListNode *prev = NULL;

        while (cur != NULL)
        {
            ListNode *nextp = cur->next; // 用指针nextp占位，确保下一次可以取到
            cur->next = prev;
            prev = cur;  /* 为下一轮操作做准备，同时在cur移走之前指向过去 */
            cur = nextp; /* 移到原链表的下一个结点，为下一轮操作做准备。*/
        }

        return prev;
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