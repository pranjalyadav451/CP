// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int sb(int arr[], int n, int x);

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];

		cout<<sb(a,n,x)<<endl;
	}
	return 0;
}// } Driver Code Ends



int sb(int a[], int n, int x)
{
	long long int current=0;
	int start =0;int end=0;
	int small=INT_MAX;
	for( int i =0; i<n;i++)
	{
		if(current+a[i]<a[i])
		{
			current = a[i];
			end=i;
			start=i;
		}
		else
		{
			current += a[i];
			end++;
		}

		while(current>x && start < end)
		{
			current -= a[start];
			start++;
			if(small>end-start+1)
				small = end - start +1;
		}

	}
	return small;
}
