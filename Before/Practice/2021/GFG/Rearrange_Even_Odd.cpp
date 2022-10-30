// { Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Node structure

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution
{
public:
    void rearrangeEvenOdd(Node *head)
    {
        Node *temp, *even = head->next, *dum = head;

        while (dum->next != NULL) {
            temp = dum ->next;
            dum->next = temp->next;
            dum = temp;
        }
        dum = head;
        while (dum->next != nullptr) {
            dum = dum->next;
        }
        dum ->next = even;
    }
};


// { Driver Code Starts.

/* Driver program to test above function*/
int main()
{
    int T, i, n, l;

    cin >> T;

    while (T--)
    {
        struct Node *head = NULL;
        struct Node *temp = head;
        cin >> n;
        for (i = 1; i <= n; i++)
        {
            cin >> l;

            if (head == NULL)
            {
                head = temp = new Node(l);

            }
            else
            {   temp->next = new Node(l);
                temp = temp->next;
            }
        }
        Solution ob;
        ob.rearrangeEvenOdd(head);
        while (head != NULL)
        {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
    return 0;
}
// } Driver Code Ends