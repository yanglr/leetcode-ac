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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL)
            return head;
        int len = 1;
        ListNode *tail = head;
        
        /* while循环一次，得到长度len。这里tail是当前结点cur, 当tail的next为 NULL时, tail成为尾结点 */
        while (tail->next)
        {
            tail = tail->next;
            ++len;
        }
        int shift = k % len;
        if (shift == 0)
            return head;        

        ListNode* prev = head;
        /* 再while循环一次, 迭代次数为 len - shift - 1, 结束时得到断开点的prev结点 */
        while (--len > shift)      // 遍历 len - shift - 1 个结点
        {
            prev = prev->next;
        }

        ListNode* newHead = prev->next;
        tail->next = head;
        prev->next = NULL;

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

    int k = 50;
    ListNode *res = sol.rotateRight(head, k);
    ListNode *p = res;
    while (p != NULL)
    {
        cout << p->val << endl;
        p = p->next;
    }

    return 0;
}