#include <bits/stdc++.h>
#define ll long long
#define vec vector
#define MOD 1000000007
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define trav(a, x) for (auto &a : x)
#define fo(i, n) for (i = 0; i < n; i++)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

using namespace std;

void solve(vec<ll>&h, int n)
{
	vec<ll>odd;
	vec<ll>even;

	for (int i = 0; i < n; i++)
	{
		if (h[i] % 2 == 0)
			even.push_back(h[i]);
		else
			odd.push_back(h[i]);
	}

	int i = 0;
	while (i < n)
	{
		if (i < even.size())
			cout << even[i];
		else
			cout << odd[i - even.size()];
		cout << " ";
		i++;
	}
	cout << endl;

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

		vec<ll> heights(n);

		for (int i = 0; i < n; i++)
			cin >> heights[i];

		solve(heights, n);
	}
}