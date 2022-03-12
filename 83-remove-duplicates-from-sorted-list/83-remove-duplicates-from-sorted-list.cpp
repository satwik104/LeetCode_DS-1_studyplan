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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
       
        //calling recursion for remaining list
        head->next = deleteDuplicates(head->next);
         //doing work for head 
        if(head->val==head->next->val)
            return head->next;
        else
            return head;
    }
};
//list is sorted means duplicate of any no. can only be just after that