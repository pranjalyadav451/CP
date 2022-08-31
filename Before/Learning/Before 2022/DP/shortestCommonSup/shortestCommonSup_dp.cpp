#include <bits/stdc++.h>
using namespace std;

int shortestCommonSupersequence(char *, char *, int, int);

int main()
{

    int t;
    char X[10001], Y[10001];

    cin >> t;
    while (t--)
    {

        cin >> X >> Y;

        cout << shortestCommonSupersequence(X, Y, strlen(X), strlen(Y)) << endl;
    }
    return 0;
}

int dp[101][101];

int solve(char *x, char *y, int m, int n)
{
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

int shortestCommonSupersequence(char *X, char *Y, int m, int n)
{
    return m + n - solve(X, Y, m, n);
}