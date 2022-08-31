#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[1001][1001];
    int minimumNumberOfDeletions(string S)
    {
        memset(dp, 0, sizeof(dp));

        int n = S.size();
        string rev = S;
        reverse(S.begin(), S.end());

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (S[i - 1] == rev[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                ;
            }
        }
        return n - dp[n][n];
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}