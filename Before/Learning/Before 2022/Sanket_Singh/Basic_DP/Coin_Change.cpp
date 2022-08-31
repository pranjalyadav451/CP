#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define dbg(x) cout << #x << ": " << x << endl
#define dbgg(x, y) cout << #x << ": " << x << "," << #y << ": " << y << endl

const ll inf = 1e12;

/***
 * What's the state of DP in this?
 * dp[i] -> the minimum number of steps to make sum i.
 * */

ll min_coins(vector<ll> &arr, int n, ll X) {

    vector<ll> dp(X + 1, inf);
    // Initialization
    dp[0] = 0;

    // Filling the dp array.
    for (int j = 1; j <= X; j++) {
        for (int i = 0; i < n; i++) {
            if (j >= arr[i]) {
                dp[j] = min(1 + dp[j - arr[i]], dp[j]);
            }
        }
    }
    ll ans = dp[X];
    return (ans == inf ? -1 : ans);
}

int main() {
    int N, X;
    cin >> N >> X;
    vector<ll> coins(N);
    for (ll &A : coins) cin >> A;
    ll ans = min_coins(coins, N, X);
    cout << ans << endl;
}