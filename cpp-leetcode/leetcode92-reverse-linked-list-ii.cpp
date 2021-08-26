#include<iostream>
#include<algorithm>
#include<vector>
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        auto fakeNode = new ListNode(-1);
        fakeNode->next = head;
        auto a = fakeNode;
        for (int i = 0; i < left - 1; i++)
            a = a->next;
        auto b = a->next, c = b->next;
        for (int i = 0; i < right - left; i++)
        {
            auto d = c->next;
            c->next = b;
            b = c;
            c = d;
        }
        a->next->next = c;
        a->next = b;
        auto res = fakeNode->next;
        delete fakeNode;

        return res;
    }
};

// Test
int main()
{
    Solution sol;    // 5->2->3->8->6
    ListNode *head = new ListNode(5);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(8);
    head->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next = nullptr;

    int left = 2, right = 4;
    ListNode *res = sol.reverseBetween(head, left, right); /* 5->8->3->2->6  */
    ListNode *p = res;
    while (p != nullptr)
    {
        cout << p->val << endl;
        p = p->next;
    }

    return 0;
}