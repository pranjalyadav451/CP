#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree(int inorder[], int preorder[], int n);

void printPostOrder(Node *root)
{
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int inorder[n], preorder[n];
        for (int i = 0; i < n; i++)
            cin >> inorder[i];
        for (int i = 0; i < n; i++)
            cin >> preorder[i];

        Node *root = buildTree(inorder, preorder, n);
        printPostOrder(root);
        cout << endl;
    }
}
// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
unordered_map<int, int> m;
int __i;
Node *solve(int pre[], int in[], int start, int end)
{
    if (start > end)
        return NULL;
    Node *res = new Node(pre[__i++]);

    if (start == end)
        return res;

    int mid = m[res->data];

    res->left = solve(pre, in, start, mid - 1);
    res->right = solve(pre, in, mid + 1, end);
    return res;
}

Node *buildTree(int in[], int pre[], int n)
{
    __i = 0;
    m.clear();
    for (int i = 0; i < n; i++)
        m[in[i]] = i;
    Node *root = solve(pre, in, 0, n - 1);
    return root;
}