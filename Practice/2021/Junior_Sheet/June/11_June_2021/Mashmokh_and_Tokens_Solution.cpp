#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n, a, b, x;
	cin >> n >> a >> b;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		cout << ((x * a) % b) / a << ' ';
	}
	return 0;
}