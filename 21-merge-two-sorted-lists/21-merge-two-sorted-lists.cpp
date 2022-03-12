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
//Iterative approach
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)
            return list2;
        if(list2==NULL)
            return list1;
        
        ListNode* dummyNode = new ListNode(-1);//we will return its next not this
        ListNode* dummyHead = dummyNode;
        
        while(list1!=NULL && list2!=NULL)
        {
            if(list1->val<=list2->val)
            {
                dummyHead->next=list1;
                list1=list1->next;
            }
            else
            {
                dummyHead->next=list2;
                list2 = list2->next;
            }
            dummyHead=dummyHead->next;
        }
        //now we add the remaining list of list 1 or list2
        if(list1!=NULL)
            dummyHead->next=list1;
        else
            dummyHead->next=list2;
        return dummyNode->next;//because first time the,first element address was in next of dummynode 
    }
};
/*
RECURSIVE
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
  {
		// if list1 happen to be NULL
		// we will simply return list2.
		if(l1 == NULL)
        {
			return l2;
		}
		
		// if list2 happen to be NULL
		// we will simply return list1.
		if(l2 == NULL)
        {
			return l1;
		} 
		
		// if value pointend by l1 pointer is less than equal to value pointed by l2 pointer
		// we wall call recursively l1 -> next and whole l2 list.
		if(l1 -> val <= l2 -> val)
        {
			l1 -> next = mergeTwoLists(l1 -> next, l2);
			return l1;
		}
		// we will call recursive l1 whole list and l2 -> next
		else
        {
			l2 -> next = mergeTwoLists(l1, l2 -> next);
			return l2;            
		}
	}
};	
*/