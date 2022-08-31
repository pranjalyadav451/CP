#include <bits/stdc++.h>
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=> " << x << ", " << #y << "=> " << y << endl
using namespace std;

ll mx = 0;
ll dp[110][110];

ll solve(vector<ll> &red, int n, vector<ll> &blue, int m)
{
    if (m == 0 and n == 0)
        return 0;

    if (dp[n][m] != -1)
        return dp[n][m];

    if (m == 0 and n != 0)
    {
        mx = max(mx, solve(red, n - 1, blue, m) + red[n - 1]);
        return dp[n][m] = solve(red, n - 1, blue, m) + red[n - 1];
    }
    if (n == 0 and m != 0)
    {
        mx = max(mx, solve(red, n, blue, m - 1) + blue[m - 1]);
        return dp[n][m] = solve(red, n, blue, m - 1) + blue[m - 1];
    }

    if (n != 0 and m != 0)
    {
        ll op_red = solve(red, n - 1, blue, m) + red[n - 1];
        ll op_blue = solve(red, n, blue, m - 1) + blue[m - 1];
        mx = max({mx, op_red, op_blue});
        return dp[n][m] = max(op_red, op_blue);
    }
}


ll prefix_sum(vector<ll> &red, int n, vector<ll> &blue, int m)
{
    ll sum1 = 0;
    ll sum2 = 0;
    ll m1 = 0, m2 = 0;
    for (ll a : red)
    {
        sum1 += a;
        m1 = max(m1, sum1);
    }

    for (ll b : blue)
    {
        sum2 += b;
        m2 = max(m2, sum2);
    }

    return m1 + m2;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        vector<ll> red(n);
        for (int i = 0; i < n; i++)
            cin >> red[i];
        int m;
        cin >> m;
        vector<ll> blue(m);
        for (int i = 0; i < m; i++)
            cin >> blue[i];

        mx = 0;
        memset(dp, -1, sizeof(dp));
        solve(red, n, blue, m);
        cout << mx << endl;
        // cout << prefix_sum(red, n, blue, m) << endl;

    }
}