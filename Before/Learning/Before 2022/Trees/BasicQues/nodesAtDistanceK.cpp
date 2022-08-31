// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
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

		// Get the current Node's value from the string
		string currVal = ip[i];

		// If the left child is not null
		if (currVal != "N")
		{

			// Create the left child for the current Node
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

			// Create the right child for the current Node
			currNode->right = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->right);
		}
		i++;
	}

	return root;
}

// } Driver Code Ends
/* A binary Tree Node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:
	vector<Node *> path;
	vector<int> ans;

public:
	void atLevelK(Node *root, int k)
	{
		if (root == NULL or k < 0)
			return;

		if (k == 0)
			ans.push_back(root->data);
		atLevelK(root->left, k - 1);
		atLevelK(root->right, k - 1);
	}

	bool findPath(Node *root, int target)
	{
		if (root == NULL)
			return false;

		if (root->data == target)
		{
			path.push_back(root);
			return true;
		}

		bool left = findPath(root->left, target);
		bool right = findPath(root->right, target);
		if (left or right)
		{
			path.push_back(root);
			return true;
		}
		return false;
	}
	vector<int> KDistanceNodes(Node *root, int target, int k)
	{
		// cout << "----------------------------" << endl;
		path.clear();
		ans.clear();
		findPath(root, target);
		int n = path.size();

		std::vector<int> res;

		Node *prev = path[0];


		int startInd = n - k >= 0 ? n - k : 0;



		for (int i = 0; i < n and k >= 0; i++)
		{
			if (prev == path[i])
				atLevelK(path[i], k);
			else
			{
				if (k == 0)
					ans.push_back(path[i]->data);

				else if (path[i]->left == prev)
				{
					atLevelK(path[i]->right, k - 1);
				}
				else if (path[i]->right == prev)
				{
					atLevelK(path[i]->left, k - 1);
				}
			}
			res.insert(res.begin(), ans.begin(), ans.end());
			ans.clear();
			prev = path[i];
			k--;
		}

		// cout << "-----------------------" << endl;
		return res;
	}
};

int main()
{
	int t;
	cin >> t;
	getchar();

	Solution x = Solution();

	while (t--)
	{
		string s;
		getline(cin, s);
		Node *head = buildTree(s);

		int target, k;
		cin >> target >> k;
		getchar();

		vector<int> res = x.KDistanceNodes(head, target, k);

		for (int i = 0; i < res.size(); i++)
			cout << res[i] << " ";
		cout << endl;
	}
	return 0;
}
