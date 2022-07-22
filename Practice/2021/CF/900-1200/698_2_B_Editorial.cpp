#include <bits/stdc++.h>
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
using namespace std;

const int maxn = 100;
bool dp[maxn];

void printList(bool arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;

    while (t--)
    {
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        int q, d;
        cin >> q >> d;

        int mx = d * 10;

        for (int i = d; i <= mx; i += 10)
        {
            for (int j = 0; i + j <= mx; j++)
            {
                dp[i + j] = dp[j] || dp[i + j];
            }
        }

        while (q--)
        {
            int u;
            cin >> u;
            if (u >= mx || dp[u])
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}