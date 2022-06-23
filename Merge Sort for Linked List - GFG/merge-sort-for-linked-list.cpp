// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* mergelist(Node* head1,Node* head2)
    {
        Node *result=NULL;
        if(head2==NULL)
            return head1;
        if(head1==NULL)
            return head2;
        if(head1->data <= head2->data)
        {
            result = head1;
            result->next=mergelist(head1->next,head2);
        }
        else
        {
            result = head2;
            result->next=mergelist(head1,head2->next);
        }
        return result;   
    }
    
    Node* mergeSort(Node* head) {
        if(head==NULL || head->next==NULL)//this is a base case for our recursive calls
            return head;
        Node *slow=head,*fast=head->next;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        //now we have mid of the list in slow which will be tail of first half
        //and slow->next will be start of second half hence we got two list to apply merge sort
        Node* firstHalfTail = slow;
        Node* secondHalfHead = slow->next;
        firstHalfTail->next = NULL;
        //now make recursive calls to break these lists more
        Node* head1 = mergeSort(head);
        Node* head2 = mergeSort(secondHalfHead);
        //call function to merge sorted list in final sorted for
        Node* ansHead = mergelist(head1,head2);
        return ansHead;
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends