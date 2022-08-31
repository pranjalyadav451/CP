#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxn = 61;
ll grid[mxn][mxn];

int main() {
	ll a, b, k;
	cin >> a >> b >> k;

	/** Storing all the C(n,r) values that are going to be used. */
	for (int i = 0; i < mxn; ++i) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				grid[i][j] = 1;
			}
			else
				grid[i][j] = grid[i - 1][j - 1] + grid[i - 1][j];
		}
	}
	/* * Solution * */
	ll n = a + b;

	while (n > 0) {
		if (grid[n - 1][b] >= k) {
			cout << 'a' ;
		}
		else {
			k = k - grid[n - 1][b];
			cout << 'b';
			b--;
		}
		n--;
	}
	cout << endl;

}