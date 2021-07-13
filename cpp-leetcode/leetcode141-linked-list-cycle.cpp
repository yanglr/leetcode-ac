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
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != NULL && fast->next != NULL)  /* 排除: 当原链表没有节点和只有一个节点时，是无法构成环的 */
        {
            slow = slow->next;
            fast = fast -> next -> next;  // 此处也明显需要 fast->next != NULL
            if(slow == fast)
                return true;
        }
        return false;
    }
};

// Test
int main()
{
    Solution sol;
    ListNode *n1 = new ListNode(3);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(0);
    ListNode *n4 = new ListNode(-4);
    n1->next = n2;
    n2->next = n1;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2; 

    bool hasCycle = sol.hasCycle(n1);
    cout << (hasCycle == true ? "true" : "false") << endl;
}