#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int equalPartition(int N, int arr[])
    {
        long long sum = 0;
        for (int i = 0; i < N; i++)
            sum += arr[i];
        if (sum % 2 == 0)
        {
            int target = sum / 2;
            bool dp[N + 1][target + 1];

            for (int i = 0; i <= target; i++)
                dp[0][i] = false;

            for (int i = 0; i <= N; i++)
                dp[i][0] = true;

            for (int i = 1; i < N + 1; i++)
            {
                for (int j = 1; j <= target; j++)
                {
                    if (arr[i - 1] <= j)
                    {
                        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                    }
                    else
                        dp[i][j] = dp[i - 1][j];
                }
            }
            return dp[N][target];
        }
        else
            return false;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
} // } Driver Code Ends