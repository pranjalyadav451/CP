// { Driver Code Starts
#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;

int dp[1001][1001];
string res = "";

class Solution
{
public:
	int solveLcs(string x, string y, int m, int n)
	{
		if (n == 0 or m == 0)
			return dp[m][n] = 0;

		if (dp[m][n] == -1)
		{
			if (y[n - 1] == x[m - 1])
			{
				return dp[m][n] = 1 + solveLcs(x, y, m - 1, n - 1);
			}
			else
				return dp[m][n] = max(solveLcs(x, y, m - 1, n), solveLcs(x, y, m, n - 1));
		}
		else
			return dp[m][n];
	}

	int lcs(int x, int y, string s1, string s2)
	{

		memset(dp, -1, sizeof(dp));
		return solveLcs(s1, s2, x, y);
	}
};

// { Driver Code Starts.
int main()
{
	int t, x, y;
	cin >> t;
	while (t--)
	{
		cin >> x >> y; // Take size of both the strings as input
		string s1, s2;
		cin >> s1 >> s2; // Take both the string as input
		Solution ob;
		cout << ob.lcs(x, y, s1, s2) << endl;

		cout << res << endl;
	}
	return 0;
}
// } Driver Code Ends