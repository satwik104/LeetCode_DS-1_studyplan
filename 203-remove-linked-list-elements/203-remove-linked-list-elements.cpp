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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
        {
            if(head->val==val)
                return NULL;
            else
                return head;
        }
        // This is for the case when a linked list is like this: 
		// 1->1->2->null , val = 1
		// 1->1->1->null , val = 1
        while(head!=NULL && head->val==val)
            head = head->next;
        
        //we will work on list from head->next to end of list
        //with help of temp,we are doing this to save head if it is not equal to val 
        //we will handle it afterward
        ListNode* temp = head;
        while(temp!=NULL && temp->next!=NULL)
        {
            if(temp->next->val==val)
                temp->next=temp->next->next;
            else
                temp = temp->next;
        }
        //now we handel the case of head
        if(head!=NULL  && head->val==val)
            head=head->next;//because we dont want this head
        return head;
        
    }
};