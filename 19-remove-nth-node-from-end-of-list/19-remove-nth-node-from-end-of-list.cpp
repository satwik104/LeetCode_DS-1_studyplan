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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //Bruteforce using 2 loops
        /*
        if(head==NULL) return NULL;
        if(head->next==NULL && n==1) return NULL;
        ListNode* temp=head;
        int len=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            len++;
        }
        //check if first noe is to be deleted
        if(len==n)
        {
            ListNode* trash = head;
            ListNode* newhead = head->next;
            delete trash;
            return newhead;
        }
        temp=head;
        int target = 1;
        while(temp!=NULL && target!=len-n)
        {
            temp=temp->next;
            target++;
        }
        //now temp is on the node just before the node tobe deleted 
        ListNode* trash = temp->next;
        temp->next = temp->next->next;
        delete trash;
        return head;
        */
        //two pointer approach
        if(head==NULL) return NULL;
        if(head->next==NULL && n==1) return NULL;
        ListNode* dummy = new ListNode();
        dummy->next=head;
        ListNode* fast=dummy;
        ListNode* slow=dummy;
        
        for(int i=0;i<n;i++)
            fast=fast->next;
        while(fast->next!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
        //now slow is just befor the node to be deleted
        slow->next = slow->next->next;
        return dummy->next; //in this way our edge case of deleting head is also covered
    }
};