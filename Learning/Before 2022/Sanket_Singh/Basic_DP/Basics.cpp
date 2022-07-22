#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define dbg(x) cout << #x << ": " << x << endl
#define dbgg(x, y) cout << #x << ": " << x << ", " << #y << ": " << y << endl

/* BRUTE FORCE */
ll fib(ll n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fib(n - 1) + fib(n - 2);
}

/* TOP DOWN APPROACH */
const int mxn = 100;
ll top_down[mxn];
ll fib_top_down(ll n) {
	if (n == 0 or n == 1) return n;
	if (top_down[n] != -1) return top_down[n];
	return top_down[n] = fib_top_down(n - 1) + fib_top_down(n - 2);
}

/* BOTTOM-UP APPROACH */
ll fib_bottom_up(ll N) {
	ll bottom_up[mxn] = {0};
	bottom_up[0] = 0; bottom_up[1] = 1;
	for (int i = 2; i <= N; i++) {
		bottom_up[i] = bottom_up[i - 1] + bottom_up[i - 2];
	}
	return bottom_up[N];
}

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		memset(top_down, -1, sizeof(top_down));
		dbgg(n, fib_top_down(n));
		dbgg(n, fib_bottom_up(n));
		cout << endl;
	}
}