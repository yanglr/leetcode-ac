#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // 头插法: 新建一个虚拟节点
        ListNode *head = new ListNode(-1);
        ListNode *fakeHead = head;

        while (l1 != nullptr || l2 != nullptr)
        {
            if (l1 == nullptr)
            {
                head->next = l2;
                break;           // 把剩下一个链表挂接上，中止当前循环
            } else if (l2 == nullptr)
            {
                head->next = l1;
                break;
            }

            if ( l1 -> val <= l2 -> val)
            {
                head->next = l1;
            }
            else
            {
                head->next = l2 -> next;
            }
            
            
        }
        
    }
};

// Test
int main()
{
	ListNode *p_head, *newhead, *track;
	Solution sol;

	p_head=new ListNode(5);
	p_head->next=new ListNode(2);
	p_head->next->next=new ListNode(3);
	p_head->next->next->next=new ListNode(8);
	
			 
	return 0;
}
