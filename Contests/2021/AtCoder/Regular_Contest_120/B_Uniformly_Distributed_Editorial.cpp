#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD = 998244353;
/**
 * Great Implementation and logic of dp.
 Todo : Read the logic behind this problem.
**/

int n, m;
string grid[505];
int cnta[1005];
int cntb[1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> grid[i];
	}

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			if (grid[x][y] == 'R') cnta[x + y]++;
			if (grid[x][y] == 'B') cntb[x + y]++;
		}
	}
	ll ans = 1;
	for (int x = 0; x < n + m - 1; x++) {
		if (cnta[x] == 0 && cntb[x] == 0) ans = ans * 2 % MOD;
		if (cnta[x] != 0 && cntb[x] != 0) ans = 0;
	}

	cout << ans << endl;
}
