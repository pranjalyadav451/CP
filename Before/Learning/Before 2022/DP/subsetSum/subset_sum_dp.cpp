#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
public:
    int subsetSum(int N, int arr[], int target)
    {
        int dp[N + 1][target + 1];
        // init
        for (int i = 0; i <= target; i++)
            dp[0][i] = 0;
        for (int i = 0; i <= N; i++)
            dp[i][0] = 1;
        // logic
        for (int i = 1; i <= N; i++)
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

        // for (int i = 0; i < N + 1; i++)
        // {
        //     for (int j = 0; j < target + 1; j++)
        //     {
        //         cout << "| ";
        //         cout << dp[i][j] << " ";
        //     }

        //     cout<<endl;
        // }

        return dp[N][target];
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)

    {
        int target = 0;
        cin >> target;
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.subsetSum(N, arr, target))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
