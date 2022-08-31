#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

Node *buildTree(string str)
{
    // Corner cases
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        string currVal = ip[i];

        if (currVal != "N")
        {

            currNode->left = newNode(stoi(currVal));

            queue.push(currNode->left);
        }

        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        if (currVal != "N")
        {

            currNode->right = newNode(stoi(currVal));

            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

vector<int> postOrder(struct Node *root);
int main()
{
    int t;
    cin >> t;
    getchar();
    while (t--)
    {
        string inp;
        getline(cin, inp);
        struct Node *root = buildTree(inp);

        vector<int> res = postOrder(root);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}

vector<int> postOrder(Node *root)
{
    std::vector<int> res;
    stack<Node *> s;
    stack<Node *> rev;
    stack<Node *> t;

    Node *temp = root;

    while (not s.empty() or temp != NULL)
    {
        if (temp != NULL)
        {

            s.push(temp);
            rev.push(temp);
            temp = temp->right;
        }
        else
        {
            temp = s.top();
            s.pop();
            temp = temp->left;
        }
    }

    while (rev.empty() == false)
    {
        res.push_back(rev.top()->data);
        rev.pop();
    }
    return res;
}
