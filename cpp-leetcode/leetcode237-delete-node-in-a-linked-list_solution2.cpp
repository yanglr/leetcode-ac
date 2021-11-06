#include<vector>
#include<algorithm>
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
    void deleteNode(ListNode* node) {
        *node = *(node->next); // 可以直接使用指针对结构体赋值
    }
};

// Test
int main()
{
    Solution sol;    // 5->2->3->8->6
    ListNode* head = new ListNode(5);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(8);
    head->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next = nullptr;
    
    auto node = head->next->next; // 要删除的node的val为3
    sol.deleteNode(node);

    auto p = head;
    while (p != nullptr)
    {
        cout << p->val << " ";        
        p = p->next;
    }

    return 0;
}