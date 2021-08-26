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

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        auto oddFake = new ListNode(-1);  /* 用于构建奇数位结点形成的链表 */
        auto evenFake = new ListNode(-1); /* 用于构建偶数位结点形成的链表 */
        auto oddP = oddFake;
        auto evenP = evenFake;
        while (head != nullptr)
        {
            oddP->next = head; /* head指针从1号结点出发(每次走两格, 始终指向奇数编号的结点) */
            evenP->next = head->next;
            oddP = oddP->next;
            evenP = evenP->next;
            ListNode* nextP = nullptr;  /* nextP指针用来占位 */
            if (head->next != nullptr)
                nextP = head->next->next;
            head = nextP;   /* head指针: 每次走两格 */
        }
        
        oddP->next = evenFake->next;  /* 把偶数段链表挂接到奇数段链表后面 */
        return oddFake->next;
    }
};

// Test
int main()
{
    Solution sol;    // 2->5->6->4->7
    ListNode *head = new ListNode(2);
    head->next = new ListNode(5);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next = NULL;
    ListNode *res = sol.oddEvenList(head);
    ListNode *p = res;
    while (p != NULL)
    {
        cout << p->val << endl;
        p = p->next;
    }

    return 0;
}