#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int getLen(ListNode *head)
    {
        int count = 0;
        ListNode *p = head;
        while (p != NULL)
        {
            count++;
            p = p->next;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {

        if (headA == NULL || headB == NULL)
            return NULL;
        int len1 = getLen(headA);
        int len2 = getLen(headB);

        if (len1 >= len2)
        {
            int gap = len1 - len2;
            while (gap--)
                headA = headA->next;
        }
        else
        {
            int gap = len2 - len1;
            while (gap--)
                headB = headB->next;
        }
        // 遍历headA 和 headB，遇到相同则直接返回
        while (headA != NULL) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};

// 以下为测试部分
int main()
{
    ListNode *pA = new ListNode(1);
    ListNode *p1 = new ListNode(2);
    ListNode *p2 = new ListNode(3);
    ListNode *pB = new ListNode(4);
    ListNode *p3 = new ListNode(5);
    ListNode *p4 = new ListNode(6);
    ListNode *p5 = new ListNode(7);
    pA->next = p1;
    p1->next = p2;
    p2->next = p4;
    pB->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = NULL;
    Solution sol;
    ListNode *pOut = sol.getIntersectionNode(pA, pB);
    cout << pOut->val << endl;
    return 0;
}