#include<bits/stdc++.h>
using namespace std;
int dp[100009];
int main() {
    int n, tmp, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &tmp);
        dp[tmp]++;
        dp[tmp - 1]++;
        dp[tmp + 1] = 0;
        if (tmp != 1)dp[tmp - 2] = 0;
        ans = max(ans, dp[tmp]);
        ans = max(ans, dp[tmp - 1]);
    }
    cout << ans << endl;
    return 0;
}
