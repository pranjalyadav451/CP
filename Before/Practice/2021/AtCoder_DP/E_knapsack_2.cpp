#include <bits/stdc++.h>
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

const ll inf = 1e18;
using namespace std;

const int max__val = 1e5 + 1;

ll dp1[max__val];
ll dp2[max__val];

void reset(ll arr1[], ll arr2[], ll size)
{
	for (int i = 0; i < size; i++)
	{
		arr1[i] = arr2[i];
		arr2[i] = inf;
	}
}

void print(ll arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

ll solve(std::vector<pair<ll, ll>> items, int N, int W)
{

	for (int i = 0; i < max__val; i++)
	{
		dp2[i] = inf;
		dp1[i] = inf;
	}

	dp1[0] = 0;
	dp1[items[0].second] = items[0].first;

	ll V = N * 1000;
	ll ans = 0;

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j <= V; j++)
		{
			if (items[i].second > j)
				dp2[j] = dp1[j];
			else
				dp2[j] = min({dp2[j], dp1[j], items[i].first + dp1[j - items[i].second]});
		}
		reset(dp1, dp2, max__val);
	}

	for (int i = 0; i <= V; i++)
	{
		if (dp1[i] <= W)
			ans = i;
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll N, W;
	cin >> N >> W;
	vector<pair<ll, ll>> items(N);

	for (ll i = 0; i < N; i++)
	{
		ll wt, val;
		cin >> wt >> val;
		items[i] = {wt, val};
	}
	cout << solve(items, N, W) << endl;
}