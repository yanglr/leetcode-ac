#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return NULL;

        ListNode *res;
        auto cmp = [](ListNode *n1, ListNode *n2)
        {
            return n1->val > n2->val;
        };

        /* 使用node的val构造一个小顶堆 */
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> nodesQ(cmp);
        for (auto list : lists)
        {
            if (list != NULL)
            {
                nodesQ.push(list);
            }
        }

        ListNode *fakeHead = new ListNode(-1);  /* 创建虚拟头结点 */
        ListNode *cur = fakeHead;
        while (!nodesQ.empty()) 
        {
            cur->next = nodesQ.top();  /* 取出最小值对应的结点指针，挂接在游标指针上 */
            cur = cur->next;
            nodesQ.pop();

            if (cur->next != NULL)  /* 只要挂接点后面还有结点，则将其压入栈，继续从中拿出最大值，循环往复 */
            {
                nodesQ.push(cur->next);
            }
        }

        return fakeHead->next;
    }
};

// Test
int main()
{   
    Solution sol;
    // l1 = {1,2,4}, l2 = {1,3,4}
    ListNode *l1 = new ListNode(1);
    l1 -> next = new ListNode(2);
    l1 -> next -> next = new ListNode(4);
    ListNode *l2 = new ListNode(1);
    l1 -> next = new ListNode(3);
    l1 -> next -> next = new ListNode(4);
    vector<ListNode*> vec;
    vec.push_back(l1);
    vec.push_back(l2);
    ListNode* res = sol.mergeKLists(vec);

    ListNode *p = res;
    while (p != NULL)
    {
        cout << p->val << endl;
        p = p->next;
    }    

    return 0;
}