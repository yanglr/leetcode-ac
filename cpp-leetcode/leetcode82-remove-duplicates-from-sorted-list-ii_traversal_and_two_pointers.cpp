#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/* Time: O(n); Space: O(1) */
class Solution { 
public: 
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL ) 
            return head;
        
        ListNode *fakeNode = new ListNode(-1);
        fakeNode->next = head;
        ListNode *pre = fakeNode;
        ListNode *cur = head;
        while (cur != NULL)
        {
            // 出现了相等的情况, pre->next 直接指向 cur->next, 删除所有重复数字
            if (cur->next != NULL && cur->val == cur->next->val)
            {
                int curVal = cur->val;
                while (cur != NULL && cur->val == curVal)
                {
                    ListNode *toDel = cur;
                    cur = cur->next;
                    pre->next = cur;
                    delete toDel; /* 释放内存 */
                }
            }
            else  /*  没有出现相等的情况时, 正常遍历即可, pre 移到 cur 的地方 */
            {
                pre = cur;
                cur = cur->next;
            }
        }
        return fakeNode->next;
    }
};

// Test
int main()
{
    Solution sol;
    ListNode *head = new ListNode(2);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = NULL;

    auto res = sol.deleteDuplicates(head);    
    ListNode *p = res;
    while (p != NULL)
    {
        cout << p->val << endl;
        p = p->next;
    }
    return 0;
}