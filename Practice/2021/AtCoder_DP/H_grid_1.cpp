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
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;

	vector<vector<char>> grid(n + 1, vector<char> (m + 1));

	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		for (int j = 1; j <= m; ++j)
		{
			grid[i][j] = s[j - 1];
		}
	}

	vector<vector<ll>> dp(n + 1, vector<ll> (m + 1));
	dp[n][m] = 1;

	for (int i = n; i >= 1; i--)
	{
		for (int j = m; j >= 1; j--)
		{
			if (i == n and j == m)
				continue;
			if (grid[i][j] == '#')
			{
				dp[i][j] = 0;
				continue;
			}
			dp[i][j] = (((i == n) ? 0 : dp[i + 1][j]) % MOD + ((j == m) ? 0 : dp[i][j + 1] % MOD)) % MOD;
		}
	}
	cout << dp[1][1] << endl;
}