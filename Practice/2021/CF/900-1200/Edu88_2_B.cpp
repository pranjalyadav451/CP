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

ll solve(vector<string> &arr, int n, int m, int x, int y)
{
	ll ans = 0 ;

	bool onlyX = false;

	if (x * 2 <= y)
		onlyX = true;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (j < m - 1 and arr[i][j] == arr[i][j + 1] and arr[i][j] == '.')
			{
				if (onlyX) ans += 2 * x;
				else ans += y;
				j++;
			}
			else if (arr[i][j] == '.')
				ans += x;
		}
	}

	return ans;
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
		int n, m, x, y;
		cin >> n >> m >> x >> y;
		vector<string> cover(n);
		for (int i = 0; i < n; i++)
			cin >> cover[i];

		cout << solve(cover, n, m, x, y) << endl;
	}
}