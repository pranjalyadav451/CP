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

// we have to get the highest score possible and we can choose any 'i'(0<=i<n) to begin with
const int N = 2e5 + 5;

ll dp[N];

ll solve(vector<ll> &arr, int n)
{
	ll mx = -1;
	for (int i = n - 1; i >= 0; i--)
	{
		dp[i] = arr[i];
		if (i + arr[i] < n)
			dp[i] += dp[i + arr[i]];
		mx = max(mx, dp[i]);
	}
	return mx;
}

ll __mx = 0;

ll solve_rec(vector<ll>& arr , int n, int i = 0)
{
	if (i >= n)
		return 0;
	if (dp[i] != -1)
		return dp[i];
	ll move = solve_rec(arr, n, i + arr[i]) + arr[i];
	ll moving_next = solve_rec(arr, n, i + 1);

	__mx = max({__mx, move, moving_next});
	return dp[i] = move;
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

		memset(dp, -1, sizeof(dp));
		__mx = -1;

		solve_rec(arr, n);
		cout << __mx;
		cout << endl;
	}
}
