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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        //first give work to recursion to get reversed list from head->next to end
        ListNode* anslist = reverseList(head->next);
        //now connect head at last of anslist tail
        head->next->next=head;//because anslist k last vali node me second node hogi given list ki
        head->next=NULL;
        return anslist;
    }
};