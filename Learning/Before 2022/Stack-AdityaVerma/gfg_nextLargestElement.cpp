// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long
#define vec vector
// Function to return Next larger elements


vector<long long> nextLargerElement(vector<long long> arr, int n)
{
	// Your code here'
	stack<ll>loading;
	vec<ll>res;
	for (int i = arr.size() - 1; i >= 0; --i)
	{

		while (!loading.empty() and loading.top() < arr[i])
		{
			cout << "popping -> loding.top() ->" << loading.top() << endl;
			loading.pop();
		}
		if (loading.empty())
		{
			res.push_back(-1);
		}
		else
		{
			res.push_back(loading.top());
		}
		loading.push(arr[i]);



	}

	reverse(res.begin(), res.end());
	return res;
}

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{

		int n;
		cin >> n;
		vector<long long> arr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];


		vector <long long> res = nextLargerElement(arr, n);
		for (long long i : res) cout << i << " ";
		cout << endl;
	}
	return 0;
}
// } Driver Code Ends