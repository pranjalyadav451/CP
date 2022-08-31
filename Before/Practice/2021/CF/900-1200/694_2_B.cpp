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
ll solve(vector<ll> &arr, ll n, ll x)
{
	ll ans = 0;
	ll count = 0;
	ll temp = 0;
	int minTimes = INT_MAX;
	int idx = 0;

	for (int i = 0; i < n; i++)
	{
		ans += arr[i];
		temp = arr[i];
		count = 0 ;
		while (temp % x == 0 and temp > 0)
		{
			temp /= x;
			count++;
		}
		if (minTimes > count)
		{
			minTimes = count;
			idx = i;
		}
		// deb2(minTimes, idx);
	}

	ans += minTimes * ans;
	for (int i = 0; i < idx; i++)
	{
		ans += arr[i];
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
		ll n, x;
		cin >> n >> x;
		vector<ll> arr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		cout << solve(arr, n, x) << endl;
	}
}