#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll extended_euclid(ll a, ll b, ll &x, ll &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	ll x1, y1;
	ll g = extended_euclid(b, a % b, x1, y1);
	x = y1;
	y = x1 - (a / b) * y1;
	return g;
}

ll inverse_mod(ll a, ll m) {
	ll x , y , gcd;
	gcd = extended_euclid(a, m, x, y);
	if (gcd == 1) {
		x = (x % m + m ) % m;
		return x;
	}
	return -1;
}


ll binpow(ll a, ll b) {
	ll res = 1;
	while (b > 0) {
		if (b % 2) {
			res = res * a;
		}
		a = a * a;
		b /= 2;
	}
	return res;
}



int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		ll a, m;
		cin >> a >> m;
		ll ans = inverse_mod(a, m);
		if (ans == -1) {
			cout << "Inverse NOT FOUND!!" << endl;
		}
		else {
			cout << "Inverse of " << a << " % " << m << ": " << ans << endl;
		}
	}
	return 0;
}