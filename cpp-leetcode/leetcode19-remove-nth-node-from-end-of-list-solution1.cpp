#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* p = head;

        while(p != NULL)
        {
            p = p -> next;
            len++;
        }

        if (n == len)
        {
            ListNode* newHead = head -> next;
            delete head;  // 释放被删除节点占用的内存
            return newHead;
        }
        
        p = head;
        for (int i = 1; i < len - n; i++)  /* 注意 for能跑的区间长度是 len - n - 1, 到要删除的节点的前一个就停下来 */
        {
            p = p -> next;
        }
        
        ListNode* toDel = p -> next;
        p->next = p->next->next;
        delete toDel;  // 释放被删除节点占用的内存

        return head;
    }
};

// Test
int main() 
{
    Solution sol;
    ListNode *l1;

    l1 = new ListNode(1);
    l1->next = new ListNode(2);
    int k = 2;

    ListNode* p = sol.removeNthFromEnd(l1, k);

    while (p != NULL)
    {
        cout << p -> val << endl;
        p = p -> next;
    }
    
    return 0;
}