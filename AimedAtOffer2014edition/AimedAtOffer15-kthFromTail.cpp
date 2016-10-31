#include<iostream>

using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution{
public:
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
	{
    	if(pListHead==NULL || k==0) return NULL;
    	
    	ListNode *pAhead,*pBehind;
		pAhead=pListHead;
		pBehind=NULL;
		for(unsigned int idx=0; idx<k-1;idx++)
		{
			if(pAhead->next==NULL) return NULL;
			else pAhead=pAhead->next;			
		}
		pBehind=pListHead;
		while(pAhead->next != NULL)
		{
			pAhead=pAhead->next;
			pBehind=pBehind->next;						
		} 
    	return pBehind;	
    }   
};

// 以下为测试部分

int main()
{
	ListNode *p_head,*kthNode;
	Solution sol;

	p_head=new ListNode(5);
	p_head->next=new ListNode(2);
	p_head->next->next=new ListNode(3);
	p_head->next->next->next=new ListNode(8);
	// p_head=NULL;
			 
	kthNode=sol.FindKthToTail(p_head,2);
	
	if(kthNode!=NULL) cout<<"The value of kth Node is: "<<kthNode->val<<endl;
	else cout<<"The Node does not exist."<<endl;
	return 0;
}