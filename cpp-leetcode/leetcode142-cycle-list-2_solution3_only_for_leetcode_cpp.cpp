#include <iostream>
#include <set>
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
        while(head) {
            if(!less<ListNode *>()(head, head->next)) {
                return head->next;
            }
            head = head->next;
        }
        return NULL;
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