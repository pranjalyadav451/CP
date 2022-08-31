#include<bits/stdc++.h>
#define ll long long

using namespace std;
long long ceil_div(ll x, ll y)
{
	long long q == (x % y) ? x / y + 1 : x / y;
	return q;
}
ll solve(ll p, ll a, ll b, ll c) {
	ll ans = 0;

	ll na = ceil_div(p, a) * a - p;
	ll nb = ceil_div(p, b) * b - p;
	ll nc = ceil_div(p, c) * c - p;

	ans = min(min(na, nb), nc);

	return ans;
}


int main() {

	int t;
	cin >> t;
	while (t--) {
		ll p, a, b, c;
		cin >> p >> a >> b >> c;
		cout << solve(p, a, b, c) << endl;
	}
	return 0;
}