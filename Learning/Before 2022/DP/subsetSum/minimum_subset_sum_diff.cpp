#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int minSubDiff(int n, int arr[])
{
	ll sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];

	int upperLimit = sum / 2;
	bool dp[n + 1][upperLimit + 1];

	for (int i = 0; i <= upperLimit; i++)
	{
		dp[0][i] = false;
	}

	for (int i = 0; i <= n; i++)
	{
		dp[i][0] = true;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= upperLimit; j++)
		{
			if (j >= arr[i - 1])
			{
				dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
			}
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	vector<int> res;

	for (int i = 0; i <= upperLimit; i++)
	{
		if (dp[n][i])
		{
			res.push_back(i);
		}
	}

	for (size_t i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;
	// looping to find the minimum difference
	int minDiff = INT_MAX;

	for (size_t i = 0; i < res.size(); i++)
	{
		if (minDiff > sum - (2 * res[i]))
			minDiff = sum - (2 * res[i]);
	}
	return minDiff;
}

int main()
{
	int tt;
	cin >> tt;
	while (tt--)
	{
		int n;
		cin >> n;

		int arr[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		cout << minSubDiff(n, arr) << endl;
	}
}