#include <iostream>
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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        
        ListNode *nextp = head->next;
        head->next = NULL;
        ListNode *newHead = reverseList(nextp);
        nextp->next = head;  /* 把head看作prev结点，f(n) = f(n-1) -> head -> NULL, n是结点序号，与当前指针cur一一对应 */
        return newHead;        
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

    ListNode *res = sol.reverseList(head);
    ListNode *p = res;
    while (p != NULL)
    {
        cout << p -> val << endl;
        p = p -> next;
    }

    return 0;
}