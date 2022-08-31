// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

vector<int> bottomView(Node *root);

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main()
{
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s, ch;
        getline(cin, s);
        Node *root = buildTree(s);

        vector<int> res = bottomView(root);
        for (int i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}

/*
    This is a problem related to a given tree's node's horizontal and vertical distance from root.
    We know to measure the vertical distance from root.(depth)
    Have to figure out how to find the horizontal distance from root.
*/

vector<int> bottomView(Node *root)
{
    if (root == NULL)
        return {};

    queue<Node *> line;
    Node *temp = root;
    map<int, Node *> hToNode;
    map<Node *, int> nodeToH;

    hToNode[0] = root;
    nodeToH[root] = 0;
    line.push(root);
    int hd = 0;

    while (line.empty() == false)
    {
        temp = line.front();
        line.pop();

        hd = nodeToH[temp];
        if (temp->left)
        {
            line.push(temp->left);
            hToNode[hd - 1] = temp->left;
            nodeToH[temp->left] = hd - 1;
        }

        if (temp->right)
        {
            line.push(temp->right);
            hToNode[hd + 1] = temp->right;
            nodeToH[temp->right] = hd + 1;
        }
    }

    vector<int> res;
    for (auto i = hToNode.begin(); i != hToNode.end(); i++)
    {
        res.push_back(i->second->data);
    }
    return res;
}
