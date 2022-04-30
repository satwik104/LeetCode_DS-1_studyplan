/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* s,ListNode* e)
    {
        ListNode* p=NULL,*c=s,*n=s->next;
        while(p!=e)
        {
            c->next=p;
            p=c;
            c=n;
            if(n!=NULL) n=n->next;
        }
        return p;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        //Approach 1 (recursive)
        /*****************************
        if(head==NULL||head->next==NULL||k==1) return head;
        ListNode* s = head,*e=head;
        int i=k-1;
        while(i--)
        {
            e=e->next;
            if(e==NULL) return head;//if number of nodes remaining is less then k then we                                       //can end the code.
        }
        ListNode *nexthead = reverseKGroup(e->next,k);
        reverse(s,e);
        s->next=nexthead;
        return e;
        *************************************/
        
        //Approach 2 (iterative)
        if(head==NULL||head->next==NULL||k==1) return head;
        ListNode *dummy=new ListNode(-1);
        dummy->next = head;
        ListNode*beforestart = dummy,*e=head;//we make before start so that we dont loose                                                //dummy
        int count=0;
        while(e!=NULL)
        {
            count++;
            if(count%k == 0)//means one grp is in our hand so perform the reversal
            {
                ListNode *s = beforestart->next,*temp=e->next;
                reverse(s,e);
                beforestart->next = e;
                s->next = temp;
                beforestart = s;
                e=temp;
            }
            else e=e->next;
        }
        return dummy->next;
    }
};