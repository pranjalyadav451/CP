// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
void printList(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if(arr[i]!=INT_MAX-1)
        cout << arr[i] << "_";
        else
        cout<<"✔"<<"_";
    }
    cout << endl;
}
class Solution
{

public:
    int minCoins(int coins[], int M, int V)
    {
        int dp[V + 1];
        dp[0] = 0;
        for (int i = 1; i <= V; i++)
            dp[i] = INT_MAX - 1;

        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j <= V; j++)
            {
                if (coins[i] <= j)
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
            printList(dp, V + 1);
        }

        if (dp[V] == INT_MAX)
            return -1;
        else
            return dp[V];
    }
};

// { Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for (int i = 0; i < m; i++)
            cin >> coins[i];

        Solution ob;
        cout << ob.minCoins(coins, m, v) << "\n";
    }
    return 0;
}
// } Driver Code Ends