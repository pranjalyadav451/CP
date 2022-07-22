#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
typedef long long ll;

const ll MOD = 1e9 + 7;

ll gcd(ll a, ll b) { if (a == 0) return b; return gcd(b % a, a); }

ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

ll binary_expo(ll a, ll b, bool useMod = false) {
    ll res = 1;
    while (b > 0) {
        if (b % 2) {
            if (useMod) res = (res * a) % MOD;
            else res = (res * a);
        }
        if (useMod) a = (a * a) % MOD;
        else a = (a * a);
        b >>= 1;
    }
    return res;
}

/**
 *  0 - stands still or falls left
 *  1 - falls right
 */

// Recursive function
int rec(int x[], int h[], int n, int i, int direction) {
    if (i == n) {
        return 0;
    }
    else if (direction == 0) {
        int ans = rec(x, h, n, i + 1, 0); // Stands
        if (x[i - 1] + h[i] < x[i]) ans++; // Falls left
        return max(ans, 1 + rec(x, h, n, i + 1, 1)); // Falls right
    }
    else {
        if (x[i - 1] + h[i - 1] >= x[i]) return INT_MIN / 2;// The condition if the previous tree can't fall to the right.
        int ans = rec(x, h, n, i + 1, 0); // Stands
        if (x[i - 1] + h[i - 1] + h[i] < x[i]) ans++;
        return max(ans, 1 + rec(x, h, n, i + 1, 1));
    }
}

void solve() {
    int n;
    cin >> n;
    int x[n], h[n];
    for (int i = 0; i < n; i++) cin >> x[i] >> h[i];

    // cout << rec(x, h, n, 1, 0) + 1 << endl;
    int dp[n + 1][2];
    dp[n][0] = dp[n][1] = 0;
    for (int i = 1; i <= n - 1; i++) {
        if (x[i - 1] + h[i - 1] >= x[i]) {
            dp[i][1] = INT_MIN / 2;
        }
    }
    for (int i = n - 1; i >= 1; i--) {
        dp[i][0] = dp[i + 1][0];
        if (x[i - 1] + h[i] < x[i]) dp[i][0]++;
        dp[i][0] = max(dp[i][0], 1 + dp[i + 1][1]);

        if (x[i - 1] + h[i - 1] >= x[i]) continue;
        dp[i][1] = dp[i + 1][0];
        if (x[i - 1] + h[i - 1] + h[i] < x[i]) dp[i][1]++;
        dp[i][1] = max(dp[i][1], 1 + dp[i + 1][1]);
    }
    cout << (1 + dp[1][0]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}