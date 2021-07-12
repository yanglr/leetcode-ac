#include<iostream>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* fakeHead = new ListNode(-1);        //定义输出链表
        ListNode* p = fakeHead;

        int carry = 0; //进位数字
        int x = 0;  //记录l1链表的值
        int y = 0;  //记录12链表的值

        //遍历两个链表
        while(l1 != NULL || l2 != NULL) {
            x  = l1 == NULL ? 0 : l1->val;
            y  = l2 == NULL ? 0 : l2->val;

            int sum = x + y + carry;
            if(sum < 10) {
                p->next = new ListNode(sum);
                carry = 0;
            }else {
                p->next = new ListNode(sum % 10);
                carry = sum / 10;
            }

            if(l1 != NULL)  l1 = l1->next;
            if(l2 != NULL)  l2 = l2->next;
            p = p->next;
        }
        if (carry != 0) p->next = new ListNode(carry);
        return fakeHead->next;
    }
};

int main()
{
    Solution sol;
    ListNode *l1;
    ListNode *l2;
	l1 = new ListNode(7);
	l1->next=new ListNode(1);
	l1->next->next=new ListNode(6);

	l2 = new ListNode(5);
	l2->next=new ListNode(9);
	l2->next->next=new ListNode(2);
        
    auto res = sol.addTwoNumbers(l1, l2);
    cout << res << endl;
    
    return 0;
}