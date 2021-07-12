#include <iostream>

using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* fakeNode = new ListNode(-1);
        ListNode* p = fakeNode;

        int carrry = 0;
        while(l1 || l2)
        {
            int val1 = (l1 != NULL) ? l1 -> val : 0;
            int val2 = (l2 != NULL) ? l2 -> val : 0;
            int sum = val1 + val2 + carrry;
            carrry = sum / 10;  // 拿掉这个sum(二位数)的末尾数字, 得到当前位的进位值
            p -> next = new ListNode(sum % 10);
            p = p -> next;
            if(l1) l1 = l1 -> next;
            if(l2) l2 = l2 -> next;
        }
        if (carrry == 1)
            p -> next = new ListNode(1);

        return fakeNode -> next;
    }
};

// Test
int main()
{
    Solution sol;
    ListNode *l1;
    ListNode *l2;

    l1 = new ListNode(7);
    l1->next = new ListNode(1);
    l1->next->next = new ListNode(6);

    l2 = new ListNode(5);
    l2->next = new ListNode(9);
    l2->next->next = new ListNode(2);

    ListNode *resHead = sol.addTwoNumbers(l1, l2);

    while (resHead != NULL)
    {
        cout << resHead->val << endl;
        resHead = resHead -> next;
    } 

    return 0;
}