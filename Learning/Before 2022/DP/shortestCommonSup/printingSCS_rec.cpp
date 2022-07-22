// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

string SCS(string, string, int, int);

int main()
{

    int t;
    string x;
    string y;

    cin >> t;
    while (t--)
    {

        cin >> x >> y;

        cout << SCS(x, y, x.size(), y.size()) << endl;
    }
    return 0;
}

// int dp[101][101];

string SCS(string x, string y, int m, int n)
{
    if (m == 0)
        return y.substr(0, n);
    if (n == 0)
        return x.substr(0, m);
    else
    {
        string res = "";
        if (y[n - 1] == x[m - 1])
        {
            return SCS(x, y, m - 1, n - 1) + y[n - 1];
        }
        else
        {
            string temp1 = SCS(x, y, m - 1, n) + x[m - 1];
            string temp2 = SCS(x, y, m, n - 1) + y[n - 1];

            if (temp1.size() > temp2.size())
                res = temp2 + res;
            else
                res = temp1 + res;
        }
        return res;
    }
}