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
        ListNode *fast = head;
        ListNode *slow = head;
        
        // 让fast指针先走n步
        for (int i = 0; i < n; i++)
        {
            fast = fast -> next;

            if (fast == NULL)  /* 此时刚好到tail节点, 需要删掉的恰好是head节点 */
            {
                ListNode *newHead = head -> next;
                delete head;
                return newHead;
            }            
        }

        while (fast -> next != NULL)
        {
            fast = fast -> next;
            slow = slow -> next;
        }
        
        ListNode *toDel = slow -> next;
        slow -> next = slow -> next -> next;
        delete toDel;

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
    l1->next = new ListNode(5);
    l1->next = new ListNode(8);
    int k = 2;

    ListNode* p = sol.removeNthFromEnd(l1, k);

    while (p != NULL)
    {
        cout << p -> val << endl;
        p = p -> next;
    }
    
    return 0;
}