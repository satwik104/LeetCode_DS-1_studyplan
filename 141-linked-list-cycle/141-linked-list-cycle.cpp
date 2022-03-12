/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//HASHMAP APPROACH TC=O(n) SC=O(n) 
/*
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)
            return false;
        ListNode *temp = head;
        unordered_map<ListNode*,bool>map;
        while(temp!=NULL)
        {
            if(map[temp->next])
                return true;
            else
                map[temp]=true;
            temp=temp->next;
        }
        return false;
    }
};*/
//two pointer approach TC=O(n) SC=O(1) 
/***********************Floyd's Cycle Detection Algorithm****************/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)
            return false;
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(slow && fast && fast->next)
        {
            slow=slow->next;
            if(fast->next!=NULL)
                fast=fast->next->next;
            else
                return false;
            if(slow==fast)
                return true;
        }
        return false;
    }
};
/*
  INTUTION...Y AND HOW?
  Actually in when we traverse a list in this way...the fast will be 2 steps more of slow but only till it enters the cycle present in the list end...because after that fast is traversing in the list continuiously....but slow is still not entered in cycle its in the linear list..
  as soon as it enter the list fast will be some step back of slow and at that time there will be definatly a case when slow = fast hence the cycle will be detected
 think this on a long list with small cycle at end
*/