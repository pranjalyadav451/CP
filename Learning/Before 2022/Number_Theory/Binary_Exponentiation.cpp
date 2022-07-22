#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll binpow_rec(int a, int b) {
	if (b == 0) return 1;

	ll res = binpow_rec(a, b / 2);
	if (b % 2 == 0)
		return res * res;
	else
		return res * res * a;
}
ll binpow_iter(ll a, ll b) {
	ll res = 1;
	while (b > 0) {
		if (b % 2 == 1) {
			res = res * a;
		}
		a = a * a;
		b = b / 2;
	}
	return res;
}


int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		ll a, b;
		cin >> a >> b;
		cout << a << "^" << b << " :" << binpow_rec(a, b) << endl;
		cout << a << "^" << b << " :" << binpow_iter(a, b) << endl;
		cout << endl;

	}
}