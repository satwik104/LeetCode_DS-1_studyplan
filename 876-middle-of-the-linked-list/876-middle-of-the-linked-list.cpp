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
    ListNode* middleNode(ListNode* head) {
        //approach 1
        /*
        int count = 0;
        ListNode *temp = head;
        while(temp!=NULL)
        {
            temp=temp->next;
            count++;
        }
        temp = head;//putting back temp at head
        int mid = count/2;
       while(mid--)
       {
          temp = temp->next;
       }
       return temp;
        */
        
        //approach 2 Two pointer (slow fast)
        ListNode *slow = head;
        ListNode *fast = head;//2times faster then slow
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};