#include<iostream>
#include<algorithm>
using namespace std;
/** Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* fakeNode = new ListNode(INT_MIN); /* 输入的链表中有0、负数之类的，这里用 INT_MAX比较合理 */
        ListNode *p = fakeNode, *q = fakeNode;
        ListNode* cur = head;
        while (cur)
        {
            if (q->val < cur->val)
            {
                q->next = cur;
                q = q->next;
                cur = cur->next;
            }
            else
            {
                q->next = cur->next;
                while (p->next != nullptr && p->next->val < cur->val)
                    p = p->next;  /* 指针p 不断向前, 找需要插入的位置, 找到时停下 */
                cur->next = p->next;
                p->next = cur;
                p = fakeNode;  /* 插入排序: 每来1个新数, 都需要将它与已排序的每一个数都比较一次, 所以需要拉到开头供下次使用 */
                cur = q->next;
            }
        }
        return fakeNode->next;
    }
};

// Test
int main()
{
    Solution sol;

    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(1);
    head->next->next->next->next = NULL;

    auto res = sol.insertionSortList(head);
    ListNode *p = res;
    while (p != NULL)
    {
        cout << p->val << endl;
        p = p->next;
    }

    return 0;
}