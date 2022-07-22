#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MXN = 61;
ll dp[MXN][MXN];

/**
 *  * Why isn't the recursive version working.
 *  * My program was not working for get_ncr(60,30) because it was exceeding the time limit.
 *  * We can't use the recursive version of calculating C(n,r) to store all the ncr upto a given limit of n and r.
 *  ? Solve the above question.
*/
ll get_ncr(ll n, ll r) {
	if (r > n) return 0;
	if (r == 0 or r == n) return 1;
	return get_ncr(n - 1, r) + get_ncr(n - 1, r - 1);
}
int main() {

	/** Best way to generate and store all the ncr values*/
	for (int i = 0; i <= 60; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				dp[i][j] = 1;
			}
			else {
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
			}
		}
	}
	// cout << get_ncr(20, 10);
}