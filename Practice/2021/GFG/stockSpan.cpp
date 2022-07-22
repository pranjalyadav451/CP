#include<bits/stdc++.h>
using namespace std;

vector <int> calculateSpan(int price[], int n)
{
	stack<int> s;
	vector<int>res;
	for (int i = 0; i < n; i++)
	{
		while (!s.empty() and price[s.top()] <=  price[i])
		{
			s.pop();
		}
		if (s.empty())
			res.push_back(i + 1);
		else
			res.push_back(i - s.top());
		s.push(i);
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
		int i, a[n];
		for (i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		vector <int> s = calculateSpan(a, n);

		for (i = 0; i < n; i++)
		{
			cout << s[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
// } Driver Code Ends