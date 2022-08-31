// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Returns the maximum value that
// can be put in a knapsack of capacity W

int dp[1001][1001];

int knapSack(int W, int wt[], int val[], int n)
{
    if (n == 0 or W == 0)
        return 0;
    if (dp[n][W] != -1)
        return dp[n][W];
    else
    {
        if (wt[n - 1] <= W)
        {
            return dp[n][W] = max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1));
        }
        else
        {
            return dp[n][W] = knapSack(W, wt, val, n - 1);
        }
    }
}


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(dp, -1, sizeof(dp));

        int n, w;
        cin >> n >> w;

        int val[n];
        int wt[n];

        for (int i = 0; i < n; i++)
            cin >> val[i];

        for (int i = 0; i < n; i++)
            cin >> wt[i];

        cout << knapSack(w, wt, val, n) << endl;
    }
    return 0;
}