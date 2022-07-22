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

int solve(std::vector<ll> speed , int n)
{
	ll ans = 0;
	sort(speed.begin(), speed.end());
	for (int i = 0; i < n; i++)
		cout << speed[i] << " ";
	cout << endl;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<ll>speed(n);

	for (int i = 0; i < n; i++)
		cin >> speed[i];

	cout << solve(speed, n) << endl;
}