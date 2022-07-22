#include <bits/stdc++.h>
#define ll long long
#define vec vector
#define MOD 1000000007
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

using namespace std;

/*
	DP GIVES TLE.
*/

// const int N = 1e5 + 5;

// ll dp[N][5];

// // how should I keep track of the length of the subsequence
// ll mx = INT64_MIN;

// ll solve(vector<ll> &arr, int n, int len, bool positive = true)
// {
// 	if (dp[n][len] != -1)
// 		return dp[n][len];
// 	if (len == n)
// 	{
// 		ll pro = 1;
// 		for (int i = 0; i < n; i++)
// 		{
// 			pro *= arr[i];
// 		}
// 		return dp[n][len] = pro;
// 	}

// 	if (len == 1)
// 	{
// 		ll ans = positive ? INT64_MIN : INT64_MAX;

// 		for (int i = 0; i < n; i++)
// 		{
// 			if (positive)
// 				ans = max(ans, arr[i]);
// 			else
// 				ans = min(ans, arr[i]);
// 		}
// 		return dp[n][len] = ans;
// 	}

// 	ll exc;
// 	if (dp[n - 1][len] == -1)
// 	{
// 		exc = solve(arr, n - 1, len, positive);
// 		dp[n - 1][len] = exc;
// 	}
// 	else
// 		exc = dp[n - 1][len];

// 	ll inc = 0;
// 	if (dp[n - 1][len - 1] != -1)
// 	{
// 		inc = dp[n - 1][len - 1];
// 	}
// 	else
// 	{
// 		if (arr[n - 1] < 0)
// 			dp[n - 1][len - 1] = inc = solve(arr, n - 1, len - 1, !positive) * arr[n - 1];
// 		else
// 			dp[n - 1][len - 1] = inc = solve(arr, n - 1, len - 1, positive) * arr[n - 1];
// 	}




// 	return dp[n][len] = positive ? max(inc, exc) : min(inc, exc);
// }

ll solve(vector<ll> &arr, int n)
{
	sort(arr.begin(), arr.end());
	ll x = arr[0] * arr[1] * arr[2] * arr[3] * arr[n - 1];
	ll y = arr[0] * arr[1] * arr[n - 3] * arr[n - 2] * arr[n - 1];
	ll z = arr[n - 5] * arr[n - 4] * arr[n - 3] * arr[n - 2] * arr[n - 1];
	return max({x, y, z});
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int tt;
	cin >> tt;
	while (tt--)
	{
		int n;
		cin >> n;
		vector<ll> arr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		// memset(dp, -1, sizeof(dp));
		cout << solve(arr, n) << endl;
	}
}

// a subsequence of length 5 having the maximum sum