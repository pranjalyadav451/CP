// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Returns the maximum value that
// can be put in a knapsack of capacity W

// int knapSack(int W, int wt[], int val[], int n, int i = 0)
// {
//     int totalValue = 0;
//     if (W <= 0 or i >= n)
//     {
//         return totalValue;
//     }
//     else if (wt[i] < W)
//     {
//         totalValue = max(knapSack(W, wt, val, n, i + 1), val[i] + knapSack(W - wt[i], wt, val, n, i + 1));
//     }
//     else
//     {
//         totalValue = knapSack(W, wt, val, n, i + 1);
//     }
//     return totalValue;
// }
int knapSack(int n, int W, int wt[], int val[])
{
    int dp[n + 1][W + 1];
    // the row index depicts the number of elements that we have in the subproblems
    // the column index depicts the weight of the knapsack that we are filling in the subproblem
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (j - wt[i - 1] >= 0)
            {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
                //  cout<<dp[i][j]<<"  ";

            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
            // cout<<endl;
        }
    }
    // cout<<dp[1][1]<<endl;
    return dp[n][W];
}
// { Driver Code Starts.

int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        //reading number of elements and weight
        int n, w;
        cin >> n >> w;

        int val[n];
        int wt[n];

        //inserting the values
        for (int i = 0; i < n; i++)
            cin >> val[i];

        //inserting the weights
        for (int i = 0; i < n; i++)
            cin >> wt[i];

        //calling method knapSack()
        cout << knapSack(n, w, wt, val) << endl;
    }
    return 0;
} // } Driver Code Ends