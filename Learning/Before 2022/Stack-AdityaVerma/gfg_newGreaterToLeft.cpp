// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long
#define vec vector
// Function to return Next larger elements


vector<long long> nextLargerToLeft(vector<long long> arr, int n)
{
	stack<ll>load;
	vec<ll>res;
	for (int i = 0; i < arr.size(); i++)
	{
		while (!load.empty() and load.top() < arr[i])
		{
			load.pop();
		}
		if (load.empty())
		{
			res.push_back(-1);
		}
		else
		{
			res.push_back(load.top());
		}
		load.push(arr[i]);
	}
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


		vector <long long> res = nextLargerToLeft(arr, n);
		for (long long i : res) cout << i << " ";
		cout << endl;
	}
	return 0;
}
// } Driver Code Ends