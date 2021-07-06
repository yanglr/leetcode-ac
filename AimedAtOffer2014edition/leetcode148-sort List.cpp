#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode *pFast, *pSlow;
        pFast=head;
        pSlow=head;
        if(head==NULL || head->next==NULL) return head;
        else {
        while(pFast->next!=NULL && pFast->next->next!=NULL)
        {
            pFast=pFast->next->next;
            pSlow=pSlow->next;
        }
        pFast=pSlow;
        pSlow=pSlow->next;        
        pFast->next=NULL;

        pFast=sortList(head);
        pSlow=sortList(pSlow);
        return merge(pFast,pSlow);
    }
}
    
    ListNode* merge(ListNode* head1, ListNode *head2)
    {  	
        ListNode *res, *p; 
        if(head1==NULL) return head2;
        if(head2==NULL) return head1;
            if(head1->val < head2->val)
                {
                    res=head1;
                    head1=head1->next;
                }
            else {
                    res=head2;
                    head2=head2->next;               
            }
            p=res;
            while(head1!=NULL && head2!=NULL)
            {
                if(head1->val < head2->val)
                {
                    p->next=head1;
                    head1=head1->next;
                }
                else {
                    p->next=head2;
                    head2=head2->next;
                }
            p=p->next;    
            }

         if(head1!=NULL) p->next=head1;
         else if(head2!=NULL) p->next=head2;
         return res; 
    }
};

// 以下为测试部分  
   
int main() 
{ 
    ListNode *pOut; 
    ListNode *head=new ListNode(5); 
    head->next=new ListNode(8); 
    head->next->next=new ListNode(7); 
    head->next->next->next=new ListNode(12); 
    head->next->next->next->next=new ListNode(4);        
    Solution sol; 
     
    pOut=sol.sortList(head); 
     
    while(pOut!=NULL) 
    { 
        cout<<pOut->val<<" "; 
        pOut=pOut->next; 
    } 
    cout<<endl; 
    return 0; 
}