#include<bits/stdc++.h>
// #include<atcoder/all>
using namespace std;
using ll = long long;
using mint = atcoder::modint1000000007;
mint dp[100005][2]; // 0 : +, 1 : -
mint cnt[100005][2];
mint m[100005];
int N;
int a[100005];
int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> a[i];
    for (int i = 1; i <= N; ++i) m[i] = a[i];
    if (N == 1) {
        cout << a[1] << '\n';
        return 0;
    }
    dp[2][0] = m[1] + m[2];
    dp[2][1] = m[1] - m[2];
    cnt[2][0] = 1;
    cnt[2][1] = 1;
    for (int i = 3; i <= N; ++i) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) + (cnt[i - 1][0] + cnt[i - 1][1]) * m[i];
        cnt[i][0] = cnt[i - 1][0] + cnt[i - 1][1];
        dp[i][1] = dp[i - 1][0] - cnt[i - 1][0] * m[i];
        cnt[i][1] = cnt[i - 1][0];
    }
    cout << (dp[N][0] + dp[N][1]).val() << '\n';
    return 0;
}