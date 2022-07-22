#include <bits/stdc++.h>
using namespace std;
/** Do This Problem.
*/


typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

ll n;
vector<vector<ll>> grid;

ll in(ll x, ll y)
{
	return (x < n && x >= 0 && y >= 0 && y < n && y <= x);
}

ll dfs(ll x, ll y, ll val, ll cnt)
{
	if (cnt == 0) return 0;

	cnt--;
	grid[x][y] = val;

	if (cnt == 0) return 0;

	if (in(x - 1, y) && !grid[x - 1][y])
		cnt = dfs(x - 1, y, val, cnt);

	if (in(x, y - 1) && !grid[x][y - 1])
		cnt = dfs(x, y - 1, val, cnt);

	if (in(x + 1, y) && !grid[x + 1][y])
		cnt = dfs(x + 1, y, val, cnt);

	if (in(x, y + 1) && !grid[x][y + 1])
		cnt = dfs(x, y + 1, val, cnt);

	return cnt;
}

bool solve()
{
	cin >> n;
	grid.assign(n, vector<ll>(n, 0));

	for (ll i = 0 ; i < n ; ++i)
	{
		cin >> grid[i][i];
	}

	for (ll i = 0 ; i < n ; ++i)
	{
		ll x = dfs(i, i, grid[i][i], grid[i][i]);

		if (x != 0) return false;
	}

	for (ll i = 0 ; i < n ; ++i)
	{
		for (ll j = 0 ; j <= i ; ++j)
		{
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
	return true;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t = 1;

	while (t--)
	{
		if (solve())
		{
			// cout << "YES" << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}

	return 0;
}