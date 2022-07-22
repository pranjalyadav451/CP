#include<bits/stdc++.h>
using namespace std;
void print(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << endl;
	}
}
int toReach(int n, int k)
{
	int nWays[n + 1];
	nWays[0] = 1;
	nWays[1] = 1;
	// int numSteps = 0;
	// int sum = 0;
	// I have to also incorporate the
	// k variable in this
	// Why are we not doing +1 in the second loop because
	// we are required to find the number of ways and this
	// is like the permutation of n objects when one is fixed
	//at its place

	for (int i = 2; i <= n; ++i)
	{
		nWays[i] = 0;
		for (int j = k; j >= 1; j--)
		{
			if (i - j >= 0)
				nWays[i] += nWays[i - j] ;
		}
	}
	// print(nWays, n + 1);
	return nWays[n];
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		cout << toReach(n, k) << endl;
	}
}
