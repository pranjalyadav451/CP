#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node *right;
	Node *left;
	Node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};

Node *build_tree()
{
	int d;
	cin >> d;

	if (d == -1)
		return NULL;
	else
	{
		Node *root = new Node(d);
		root->left = build_tree();
		root->right = build_tree();
		return root;
	}

}

void print_pre(Node *root)
{
	if (root == NULL)
		return;

	cout << root->data << " ";
	print_pre(root->left);
	print_pre(root->right);
}

int height(Node *root)
{
	if (root == NULL)
		return 0;

	int ls = height(root->left);
	int rs = height(root->right);
	return max(ls, rs) + 1;
}

void print_kth_level(Node *root, int k)
{
	if (root == NULL)
		return;

	if (k == 1)
	{
		cout << root->data << " ";
		return;
	}

	print_kth_level(root->left, k - 1);
	print_kth_level(root->right, k - 1);
}

void print_all_levels(Node *root, int height)
{
	for (int i = 1; i <= height; i++)
	{
		print_kth_level(root, i);
		cout << endl;
	}
}

int main()
{
	Node *root = build_tree();

	cout << "Pre order Traversal -: " << endl;
	print_pre(root);
	cout << "\n\n";
	cout << "Height : " << height(root) << endl;

	print_all_levels(root, height(root));
	return 0;
}
