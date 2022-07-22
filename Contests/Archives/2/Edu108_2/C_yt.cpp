#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }
int __fastio = fastio();

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second
#define sz(x) (int((x).size()))
#define rep(i, a, b) for (int(i) = (a); i <= (b); (i)++)
#define rrep(i, a, b) for (int(i) = (a); i >= (b); (i)--)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

int main()
{
	int tt;
	cin >> tt;
	// cout << tt << endl;
	while (tt--)
	{
		ll n;
		cin >> n;
		vector<ll> v[n + 1];
		ll arr[n];

		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		ll temp = 0;

		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			v[arr[i]].push_back(temp);
		}

		for (int i = 1; i <= n; i++)
		{
			sort(v[i].rbegin(), v[i].rend());
			// reverse(v[i].begin(), v[i].end());
		}

		ll ans[n + 1];
		for (int i = 0; i <= n; i++)
			ans[i] = 0;

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j < v[i].size(); j++)
			{
				v[i][j] += v[i][j - 1];
			}

			for (int j = 1; j <= v[i].size(); j++)
			{
				temp = v[i].size() % j;
				ans[j] += v[i][v[i].size() - temp - 1];
			}
		}


		for (int i = 1; i <= n; i++)
			cout << ans[i] << " ";
		cout << endl;

	}
}