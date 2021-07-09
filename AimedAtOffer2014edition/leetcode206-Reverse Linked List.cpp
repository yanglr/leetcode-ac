#include <iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *p;
        ListNode *newhead=NULL;
        p=head;
        
        if(head==NULL || head->next==NULL)  return head;
        
        while(p!=NULL)
        {
            ListNode *temp=p;
            p=p->next;
            
            temp->next=newhead;           
            newhead=temp;                  
        }
       return newhead;        
    }
};

int main()
{
	ListNode *p_head, *newhead, *track;
	Solution sol;

	p_head=new ListNode(5);
	p_head->next=new ListNode(2);
	p_head->next->next=new ListNode(3);
	p_head->next->next->next=new ListNode(8);
	// p_head=NULL;
			 
	newhead=sol.reverseList(p_head);	
	track=newhead;

	while(track != NULL) 
	{
		cout<<"The value of related Node is: "<<track->val<<endl;
		track=track->next;
	}
	return 0;
}