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

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL ) return head;

        if (head->val != head->next->val) 
        {
            head->next = deleteDuplicates(head->next); /* 如果头结点和后边的节点不相等, 则头结点是需要的, 保留头结点, 
                                                        后边的所有节点的处理由递归解决. 要处理的数的规模由len变为len-1 */
            return head;
        }

        int curVal = head->val;
        while (head != NULL && head->val == curVal)  /* 如果头结点和后边的节点相等  */
        {
            ListNode *toDel = head;
            head = head->next;
            delete toDel;                           // 释放内存
        }
        return deleteDuplicates(head);
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