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
    void reorderList(ListNode* head) {
        auto fakeNode = new ListNode(-1);        
        vector<ListNode*> arr = getNewArr(head);
        fakeNode->next = arr[0];
        for (int i = 0; i < arr.size() - 1; i++)
            arr[i]->next = arr[i+1];
        arr.back()->next = nullptr;
        head = fakeNode->next;
    }
    vector<ListNode*> getNewArr(ListNode* head)
    {
        vector<ListNode*> oriArr;
        vector<ListNode*> newArr;
        auto p = head;
        while (p)
        {
            oriArr.push_back(p);
            p = p->next;
        }
        int count = oriArr.size();
        for (int i = 0; i <= oriArr.size()/2 + 1; i++)
        {
            if (count >= 2)
            {
                newArr.push_back(oriArr[i]);
                newArr.push_back(oriArr[oriArr.size() - 1 - i]);
                count -= 2;
            }            
        }
        if (count == 1)
            newArr.push_back(oriArr[oriArr.size()/2]);
        return newArr;
    }
};

// Test
int main()
{
    Solution sol;

    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = NULL;

    sol.reorderList(head);
    ListNode* p = head;
    while (p != NULL)
    {
        cout << p->val << endl;
        p = p->next;
    }

    return 0;
}