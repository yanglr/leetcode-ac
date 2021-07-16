#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {        
        if (head == NULL || head->next == NULL)
            return head;
            
        ListNode *p = head;

        // 以下循环代码等价于判断当 len < k 时直接返回head
        for (int i = 0; i < k; i++)
        {
            // 剩余结点数量小于k的话，则不需要反转
            if (p == NULL)
                return head;            
            p = p->next;
        }
        // 反转前 k 个元素
        ListNode *newHead = reverse(head, p);
        // 下一轮的开始的地方就是p
        head->next = reverseKGroup(p, k);
        
        return newHead;
    }

    /* 左闭又开区间 */
    ListNode* reverse(ListNode *head, ListNode *tail) {
        ListNode *pre = NULL;
        ListNode *nextP = NULL;
        while (head != tail)
        {
            nextP = head->next;
            head->next = pre;
            pre = head;
            head = nextP;
        }
        return pre;
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
    int k = 2;
    ListNode *res = sol.reverseKGroup(head, k);
    ListNode *p = res;
    while (p != NULL)
    {
        cout << p->val << endl;
        p = p->next;
    }

    return 0;
}