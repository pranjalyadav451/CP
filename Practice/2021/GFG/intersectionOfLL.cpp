// { Driver Code Starts
#include<iostream>
#include<stdio.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if (size == 0) return NULL;

    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

/* Driver program to test above function*/
int main()
{
    int T, n1, n2, n3;

    cin >> T;
    while (T--)
    {
        cin >> n1 >> n2 >> n3;

        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);

        Node* temp = head1;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL) temp->next = common;

        temp = head2;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL) temp->next = common;

        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

int intersectPoint(Node* head1, Node* head2)
{

    // int len_1 = 1, len_2 = 1;

    // Node *t1 = head1, *t2 = head2;

    // while (t1)
    // {
    //     len_1++;
    //     t1 = t1->next;
    // }
    // while (t2)
    // {
    //     len_2++;
    //     t2 = t2->next;
    // }

    // pair<Node*, int>big, small;

    // big = len_1 > len_2 ? make_pair(head1, len_1) : make_pair(head2, len_2);
    // small = len_1 > len_2 ? make_pair(head2, len_2) : make_pair(head1, len_1);

    // int diff = big.second - small.second;

    // while (diff--)
    //     big.first = big.first->next;

    // while (small.second--)
    // {
    //     if (big.first == small.first)
    //         return big.first->data;

    //     big.first = big.first->next;
    //     small.first = small.first->next;
    // }
    // return -1;

    Node *t1 = head1, *t2 = head2;

    while (t1 and t2 and t1 != t2)
    {
        t1 = t1->next;
        t2 = t2->next;

        if (t1 == t2)
            return t1->data;
        if (t1 == NULL)
            t1 = head2;
        if (t2 == NULL)
            t2 = head1;
    }
    return -1;
}

