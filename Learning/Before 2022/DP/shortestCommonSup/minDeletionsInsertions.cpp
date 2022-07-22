// { Driver Code Starts
#include <bits/stdc++.h>
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int dp[1001][1001];

    int solve(string x, string y)
    {
        int m = x.size();
        int n = y.size();

        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (x[i - 1] == y[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[m][n];
    }

    int minOperations(string str1, string str2)
    {
        int deletions = str1.size() - solve(str1, str2);
        int insertions = str2.size() - solve(str1, str2);

        deb(solve(str1, str2));
        deb2(insertions, deletions);

        return str1.size() + str2.size() - 2 * solve(str1, str2);
    }
};

// { Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

        Solution ob;
        cout << ob.minOperations(s1, s2) << "\n";
    }
    return 0;
}

// } Driver Code Ends