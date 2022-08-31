#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define dbg(x) cout << #x << ": " << x << endl
#define dbgg(x, y) cout << #x << ": " << x << "," << #y << ": " << y << endl

/*
 * Given a number x, we have to reduce the number to 1 in minimum number of steps
 * using the given three operations which are :
 *   - Can subtract 1
 *   - If the number is divisible by 2, then can divide by 2.
 *   - If the number is divisible by 3, then can divide by 3.
*/

const ll inf = 1e12;
const int mxn = 1e6 + 10;
ll dp[mxn];

int init() {
    memset(dp, -1, sizeof(dp)); return 0;
} int init_dp = init();

ll reduce(ll x) {
    if (x == 1) return 0;
    if (x < 1) return inf;

    ll &ans = dp[x];
    if (ans != -1) return ans;
    ans = inf;
    ans = 1 + reduce(x - 1);
    if (x % 2 == 0) ans = min(ans, 1 + reduce(x / 2));
    if (x % 3 == 0) ans = min(ans, 1 + reduce(x / 3));
    return ans;
}

ll reduce_bottom_up(ll x) {
    vector<ll> dp(x + 1);
    dp[0] = inf; dp[1] = 0;
    for (int i = 2; i <= x; i++) {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0) dp[i] = min(dp[i], 1 + dp[i / 2]);
        if (i % 3 == 0) dp[i] = min(dp[i], 1 + dp[i / 3]);
    }
    return dp[x];
}

int main() {
    int x;
    cin >> x;
    ll ans = reduce(x), ans_bottom_up = reduce_bottom_up(x);
    dbgg(x, ans); dbgg(x, ans_bottom_up);
}
