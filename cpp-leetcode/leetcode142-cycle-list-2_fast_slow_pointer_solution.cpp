#include <iostream>
#include <vector>
#include <algorithm>
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }
        /* 处理上一轮遍历结束时的临界情况 */
        if (fast == NULL || fast->next == NULL)
            return NULL;
        slow = head;
        while (fast != slow)  /* 只要还没相遇就继续循环 */
        {
            slow = slow->next;
            fast = fast->next;  /* 此轮循环每次只走一步 */
        }
        return slow;
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

    ListNode* meet = sol.detectCycle(n1);
    cout << meet->val << endl;

    return 0;
}