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
    ListNode *swapPairs(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *fakeHead = new ListNode(-1);
        fakeHead->next = head;
        ListNode *cur = fakeHead;
        while (cur->next != NULL && cur->next->next != NULL)
        {
            ListNode *swap1 = cur->next;      /* ①与②号结点交换 */
            ListNode *swap2 = cur->next->next;
            cur->next = swap2;
            swap1->next = swap2->next;        /*交换后①号结点的next指针指向③号结点*/
            swap2->next = swap1;
            cur = swap1;
        }
        return fakeHead->next;
    }
};

// Test
int main()
{
    Solution sol;

    ListNode *head = new ListNode(5);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = NULL;

    ListNode *res = sol.swapPairs(head);
    ListNode *p = res;
    while (p != NULL)
    {
        cout << p->val << endl;
        p = p->next;
    }

    return 0;
}