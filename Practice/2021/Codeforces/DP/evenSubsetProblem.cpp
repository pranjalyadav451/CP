#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll int subset(arr, n)
{
	if (n <= 0)
	{
		if (arr[0] % 2 == 1)
			return 1;
		else
			return 0;
	}
	else
	{
		sum = subset(arr, n - 1)subset(arr, n - 1);
	}
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		//input the range of valid indices in the array
		// 0 to n-1
		cout << subset(arr, n - 1) << endl;
	}
}
