#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define dbg(x) cout << #x << ": " << x << endl
#define dbgg(x, y) cout << #x << ": " << x << "," << #y << ": " << y << endl
/*
 * Given a number N, find the binary strings of length N such that there are no
 * consecutive ones.
 **/

ll count(ll N) {
    vector<ll> dp(N + 1);
    dp[0] = 0, dp[1] = 2, dp[2] = 3;
    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[N];
}

int main() {
    int tt; cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        ll ans = count(n);
        dbgg(n, ans);
    }
}