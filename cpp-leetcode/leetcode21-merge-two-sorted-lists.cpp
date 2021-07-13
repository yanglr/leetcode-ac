#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        // 头插法: 新建一个虚拟节点
        ListNode *cur = new ListNode(-1);
        ListNode *fakeHead = cur;

        while (l1 != NULL || l2 != NULL)
        {
            if (l1 == NULL)
            {
                cur->next = l2;
                break; // 把剩下一个链表挂接上，中止当前循环
            }
            else if (l2 == NULL)
            {
                cur->next = l1;
                break;
            }

            if (l1->val <= l2->val)
            {
                cur->next = l1;
                cur = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                cur = l2;
                l2 = l2->next;
            }
        }

        return fakeHead->next;
    }
};

// Test
int main()
{
    Solution sol;
    ListNode *l1;
    ListNode *l2;

    l1 = new ListNode(1);
    l1->next = new ListNode(3);
    l1->next->next = new ListNode(6);
    l1->next->next->next = NULL;

    l2 = new ListNode(5);
    l2->next = new ListNode(8);
    l2->next->next = new ListNode(10);
    l2->next->next->next = NULL;
    ListNode *res = sol.mergeTwoLists(l1, l2);

    ListNode *p = res;
    while (p != NULL)
    {
        cout << p->val << endl;
        p = p->next;
    }

    return 0;
}