#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

inline ll madd(ll a, ll b) {
    return (a % mod + b % mod) % mod;
}
void solve() {
    int n; cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<vector<ll>> dp(2, vector<ll>(n + 1));
    dp[1][1] = (arr[0][0] == '*');


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i - 1][j - 1] == '*') dp[i % 2][j] = 0;
            else if (i == 1 and j == 1) dp[i][j] = 1;
            else dp[i % 2][j] = madd(dp[i % 2][j - 1], dp[(i - 1) % 2][j]);
        }
    }
    ll ans = dp[n % 2][n];
    cout << ans << endl;
}
int main() {
    solve();
}
