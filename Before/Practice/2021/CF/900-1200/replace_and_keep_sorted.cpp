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

	ll n, q, k;
	cin >> n >> q >> k;

	vector<ll> v(n);

	for (ll i = 0; i < n; i++)
		cin >> v[i];

	while (q--)
	{
		ll l, r;
		cin >> l >> r;

		ll nOnes = v[l - 1] - 1 + k - v[r - 1];
		ll nZeros = r - l + 1;
		ll nTwos = v[r - 1] - v[l - 1] + 1 - nZeros;

		ll ans = nOnes + nTwos * 2 ;

		cout << ans << endl;

	}

}