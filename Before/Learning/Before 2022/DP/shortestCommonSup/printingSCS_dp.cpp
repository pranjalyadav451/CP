#include <bits/stdc++.h>
using namespace std;
void SCS(string x, string y, int m, int n);
string printSCS(string, string, int, int);

int main()
{

    int t;
    string x;
    string y;

    cin >> t;
    while (t--)
    {

        cin >> x >> y;

        cout << printSCS(x, y, x.size(), y.size()) << endl;
    }
    return 0;
}

int dp[101][101];
void SCS(string x, string y, int m, int n)
{
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= m; i++)
        dp[i][0] = i;
    for (int i = 0; i <= n; i++)
        dp[0][i] = i;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i - 1] == y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
}

string printSCS(string x, string y, int m, int n)
{
    SCS(x, y, m, n);
    string res = "";
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }

    int i, j;
    for (i = m, j = n; j >= 1 && i >= 1;)
    {
        if (x[i - 1] == y[j - 1])
        {
            res.push_back(x[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] >= dp[i][j - 1])
            {
                res.push_back(y[j - 1]);
                j--;
            }
            else
            {
                res.push_back(x[i - 1]);
                i--;
            }
        }
    }

    if (i == 0)
    {
        while (j != 0)
        {
            res.push_back(y[j - 1]);
            j--;
        }
    }
    else
    {
        while (i != 0)
        {
            res.push_back(x[i - 1]);
            i--;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}