#include <bits/stdc++.h>
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

using namespace std;

const int LIM = 1e5 + 10;
int dp[LIM];

int solve(int arr[], int n, int k)
{

    dp[0] = 0;

    int mn = INT_MAX;
    int iter = 0;

    for (int i = 1; i < n; i++)
    {
        iter = i >= k ? k : i;
        mn = INT_MAX;

        for (int j = 1; j <= iter; j++)
            mn = min(dp[i - j] + abs(arr[i] - arr[i - j]), mn);

        dp[i] = mn;
    }

    return dp[n - 1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;

    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << solve(arr, n, k) << endl;
}