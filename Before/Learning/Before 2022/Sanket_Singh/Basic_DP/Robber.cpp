/*
 * QUESTION :
 * There is a robber who is going on robbing houses, but in order to not alarm the
 * entire neighbourhood he won't rob from any two adjacent houses.
 * Find the maximum loot he can get if he knows how much loot he will get in each house.
 **/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define dbg(x) cout << #x << ": " << x << endl
#define dbgg(x, y) cout << #x << ": " << x << ", " << #y << ": " << y << endl

const ll inf = 1e12;
/*
 * One Dimensional DP :
 * We do not need to make a two dimensional dp, first index of which maps to the
 * number of houses and the second index maps to the previous selected house.
 * dp[i] -> indicates the best loot till the i'th house when we have not picked
 * any adjacent house (whether we have picked the i'th house or nots).
 * Transition : dp[i] = max(arr[i] + dp[i - 2], dp[i - 1])
**/
ll rob(vector<ll> &arr, int n) {
	vector<ll > dp(n + 1, 0);
	/* Initialization */
	dp[0] = 0; dp[1] = arr[0];
	/* Building up the solution.*/
	for (int i = 2; i <= n; i++) {
		dp[i] = max(arr[i - 1] + (dp[i - 2]), dp[i - 1]);
	}
	return dp[n];
}

int main() {
	int n;
	cin >> n;
	vector<ll> arr(n);
	for (ll &a : arr)
		cin >> a;
	ll ans = rob(arr, n);
	cout << ans << endl;
}