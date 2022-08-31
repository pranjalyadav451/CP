#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices) 
{
// i have to copy and paste the solution here.
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int>v(n);
		for(int i = 0;i<n;i++)
			cin>>v[i];
		cout<<maxProfit(v);
	}
}
