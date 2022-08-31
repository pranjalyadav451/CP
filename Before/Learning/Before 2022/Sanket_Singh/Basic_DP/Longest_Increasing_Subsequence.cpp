#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define dbg(x) cout << #x << ": " << x << endl
#define dbgg(x, y) cout << #x << ": " << x << "," << #y << ": " << y << endl

const int mxn = 1e6 + 10;
const ll inf = 1e12;
vll dp;

ll rec(vll &arr, int n, ll prev = inf) {
    if (n == 0) return 0;
    ll ans = -inf;
    ans = rec(arr, n - 1, prev);
    if (arr[n - 1] < prev) {
        ans = max(ans, 1 + rec(arr, n - 1, arr[n - 1]));
    }
    return ans;
}

ll longest_increasing(vll &arr, int n) {
    // Initialization.
    dp.assign(n + 1, 1); dp[0] = 0;
    // Filling the array.
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++) {
            if (arr[i - 1] > arr[j - 1])
                dp[i] = max(1 + dp[j], dp[i]);
        }
    }
    dp.clear();
    return dp[n];
}

int main() {
    int n; cin >> n;
    vll arr(n);
    for (ll &A : arr) cin >> A;
    ll ans = longest_increasing(arr, n);
    dbg(ans);
    ll rec_ans = rec(arr, n);
    dbg(rec_ans);
}