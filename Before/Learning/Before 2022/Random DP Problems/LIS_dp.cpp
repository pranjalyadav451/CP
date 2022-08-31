#include <bits/stdc++.h>
#define ll long long
#define vec vector
#define MOD 1000000007
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define trav(a, x) for (auto &a : x)
#define fo(i, n) for (i = 0; i < n; i++)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

using namespace std;
// int solve(int n, int a[])
// {
//     int dp[n];
//     // memset(dp, '1', sizeof(dp));
//     // dp[0] = 1;
//     deb(dp[1]);
//     dp[0] = 1;
//     for (int i = 1; i < n; i++)
//     {
//         dp[i] = 1;
//         for (int j = 0; j < i; j++)
//         {
//             if (a[j] < a[i] and dp[i] < dp[j] + 1)
//             {
//                 dp[i] = dp[j] + 1;
//             }
//         }
//     }
//     // return dp[n-1];
//     //the above return statement will not give the correct answer because there might be a case that we are getting the longest subsequence in the middle of the sequence provided to us which doesn't include the last element of the dp.
//     //https://www.youtube.com/watch?v=fV-TF4OvZpk&t=863s
//     //the best dynamic programming explanation
//     return *max_element(dp, dp + n);
// }
vector<int> len(100, 1);
int solve(int n, int a[], int left = 0, int prev = -1)
{
    // memoized version of the problem
    // I want to make a memoized version of this solution.
    if (left == n)
    {

        return 0;
    }
    if (a[left] > prev)
    {
        return len[left] == (max(1 + solve(n, a, a[n - 1], left + 1), solve(n - 1, a, prev, left + 1)));
    }
    else
    {
        return solve(n - 1, a, prev, left + 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        deb(a[0]);
        cout << solve(n, a) << endl;
    }
}