// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;

	Node(int x) {
		data = x;
		next = NULL;
	}
};

void printList(Node* node)
{
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
	cout << "\n";
}

class Solution
{
public:
	Node* pairWiseSwap(struct Node* head)
	{


		// if the list is empty or contains only one element.
		if (head == NULL or head->next == NULL)
			return head;


		/*
			dum -> to traverse the list
			prev -> to adjust the swapped nodes with the previous list
			temp -> intermediate variable only used for swapping
			tempHead -> to just store

		*/
		Node *dum = head;
		Node *prev = NULL;
		Node *temp = head;

		// the head of the new list
		head = head->next;

		while (dum != NULL and dum->next != NULL)
		{

			temp = dum->next;

			dum->next = dum->next->next;
			temp->next = dum;

			if (prev != NULL)
				prev->next = temp;

			prev = dum;

			dum = dum->next;


		}



		return head;
	}
};

// { Driver Code Starts.


int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int data;
		cin >> data;
		struct Node *head = new Node(data);
		struct Node *tail = head;
		map<Node*, int> mp;
		mp[head] = head->data;
		for (int i = 0; i < n - 1; ++i)
		{
			cin >> data;
			tail->next = new Node(data);
			tail = tail->next;
			mp[tail] = tail->data;
		}
		struct Node *failure = new Node(-1);
		Solution ob;
		head = ob.pairWiseSwap(head);
		int flag = 0;
		struct Node *temp = head;
		while (temp) {
			if (mp[temp] != temp->data) {
				flag = 1;
				break;
			}
			temp = temp->next;
		}
		if (flag)
			printList(failure);
		else
			printList(head);
	}
	return 0;
}
// } Driver Code Ends