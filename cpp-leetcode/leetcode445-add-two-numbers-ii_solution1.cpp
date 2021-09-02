#include <algorithm>
#include <vector>
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
    ListNode* addTwoNumbers(ListNode* h1, ListNode* h2) {
        // 题意: 两个非空链表, 故不需要判断NULL。且链表不能reverse
        string numStr1 = "", numStr2 = "";
        vector<int> resVals;
        int len1 = getLen(h1, numStr1);
        int len2 = getLen(h2, numStr2);         
        // 更新resVals
        auto sumStr = addStrings(numStr1, numStr2);
        for (auto &ch : sumStr)
            resVals.push_back(ch - '0');
                              
        ListNode* fakeHead = new ListNode(-1);
        ListNode* p = fakeHead;
        fakeHead->next = new ListNode(resVals.front());
        for (int i = 0; i < resVals.size(); i++)
        {
            p->next = new ListNode(resVals[i]);
            p = p->next;
        }
        p->next = nullptr;
        
        return fakeHead->next;
    }
    int getLen(ListNode* head, string& numStr)
    {
        int count = 0;
        ListNode* p = head;
        while (p != nullptr)
        {
            count++;
            numStr.push_back(p->val + '0');
            p = p->next;            
        }
        return count;
    }        
    string addStrings(string num1, string num2)
    {
        string result;

        int carry = 0;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        // 双指针: 两字符串尾部对齐, 从低位向高位扫描, "越界"就置为0, 使其不影响计算
        while (i >= 0 || j >= 0 || carry > 0) {
            int v1 = i >= 0 ? num1[i] - '0' : 0;
            int v2 = j >= 0 ? num2[j] - '0' : 0;
            int sum = v1 + v2 + carry;
            result.push_back(sum % 10 + '0'); /* 把当前位加到结果数组中, 并更新进位值为下一轮循环做准备 */
            carry = sum >= 10 ? 1 : 0; // 或写成 sum / 10

            i--;
            j--;
        }        
        reverse(result.begin(), result.end()); /* 由于一开始低位放在数组的前面, 所以需要反转1次 */
        return result;
    }
};

// Test
int main()
{
    Solution sol;
    ListNode *l1;
    ListNode *l2;

    l1 = new ListNode(7);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    l1->next->next->next = new ListNode(3);
    l1->next->next->next->next = NULL;

    l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    l2->next->next->next = NULL;
    ListNode *res = sol.addTwoNumbers(l1, l2);

    ListNode *p = res;
    while (p != NULL)
    {
        cout << p->val << endl;
        p = p->next;
    }

    return 0;
}