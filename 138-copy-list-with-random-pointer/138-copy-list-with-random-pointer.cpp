/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    //FIRST APPROACH SC: O(n)
    /*
    Node* copyRandomList(Node* head) {
        
        map<Node*,Node*> m;
        Node* temp = head;
        while(temp!=NULL)
        {
            Node* copy = new Node(temp->val);
            m[temp] = copy;
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL)
        {
            m[temp]->next = m[temp->next];
            m[temp]->random = m[temp->random];
            temp=temp->next;
        }
        return m[head];
    }
    */
    //SECOND APPROACH SC: O(1)
    Node* copyRandomList(Node* head) {
        //step 1- make copy of each node
        Node* itr = head;
        Node* front = head;
        while(itr!=NULL)
        {
            Node* copy = new Node(itr->val);
            front=itr->next;
            itr->next=copy;
            copy->next=front;
            itr=front;
        }
        //step-2 assign random pointers for copy
        itr = head;
        while(itr!=NULL)
        {
            if(itr->random!=NULL)
            {
               itr->next->random = itr->random->next;        
            }
            itr=itr->next->next;
        }
        //step 3- restore orignal list and extract copy list hence breaking the bonds
        itr=head;
        Node* dummy = new Node(0);
        Node* copy = dummy;
        while(itr!=NULL)
        {
            front = itr->next->next;
            copy->next=itr->next;
            itr->next = front;
            copy = copy->next;
            itr=itr->next;
        }
        return dummy->next;
    }
};