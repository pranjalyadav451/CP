// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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

/* Function to mergesort the linked list
   It should return head of the modified list  */
Node* merge(Node* l1,Node*l2)
{
    Node go(0);
    Node*back = &go;
    while(l1!=NULL && l2!=NULL)
  {
        if(l1->data<l2->data)
        {
            back->next = l1;
            back = back->next;
            l1=l1->next;
        }
        else
        {
            back->next = l2;
            back = back->next;
            l2=l2->next;
        }
    }
    if(l1==NULL)
        back->next = l2;
    else
        back->next = l1;
    
    return go.next;
}
Node* mergeSort(Node* head) 
{
    
    if(head == NULL || head->next ==NULL)
        return head;
    
    Node *newHead = head;
    Node * fast = newHead->next;
    newHead -> next =NULL;
    Node* super = NULL;
    
    while(fast!=NULL)
    {
        super = fast->next;
        fast->next = NULL;
        newHead = merge(fast,newHead);    
        fast = super;
    }
    return newHead;
    // your code here
}


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
        a = mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends