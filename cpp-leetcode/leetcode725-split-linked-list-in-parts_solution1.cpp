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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res;
        int len = 0;
        ListNode* p = head;
        while (p)
        {
            p = p->next;
            len++;
        }
        int div, rem, i, j;
        div = len / k; // 平均长度 div = totalLen/k
        rem = len % k; /* 计算余数, 前一部分(前totalLen%k个)长度为div + 1, 后一部分为div */
        for (i = 0; i < k; i++)
        {
            ListNode* fakeHead = new ListNode(0); // 新建一个虚拟头结点
            p = fakeHead;
            for (j = 0; j < div; j++)
            {   // 向每一部分添加div个结点
                ListNode* node = new ListNode(head->val);
                p->next = node;
                p = p->next;
                if (head) head = head->next;
            }
            if (rem > 0 && head)  // 向前一部分(前totalLen%k个)分别追加1个结点
            { 
                ListNode* node = new ListNode(head->val);
                p->next = node;
                if (head) head = head->next;
                rem--;
            }
            res.push_back(fakeHead->next);
        }

        return res;
    }
};

// Test
int main()
{
    Solution sol;
    ListNode* head = new ListNode(1);  /* {1,4,3,2,5} */
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = nullptr;      
    int k = 3;
    auto res = sol.splitListToParts(head, k);
    for (auto& list : res)
    {
        ListNode* p = list;
        while (p != nullptr)
        {
            cout << p->val << " ";
            p = p->next;
        }
        cout << "\n";  
    }
    
    return 0;
}