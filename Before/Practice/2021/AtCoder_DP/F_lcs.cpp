#include <bits/stdc++.h>
#define ll long long
#define vec vector
#define MOD 1000000007
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

using namespace std;

int dp[3001][3001];

void print(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}


string lcs(string &s1, string &s2, int m, int n)
{
	memset(dp, 0, sizeof(dp));
	string ans = "";

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}

	int i = m, j = n;
	while (i > 0 and j > 0)
	{

		if (s1[i - 1] != s2[j - 1])
		{
			if (dp[i - 1][j] > dp[i][j - 1])
				i--;
			else
				j--;
		}
		else
		{
			i--; j--;
			ans.pb(s1[i]);
		}
	}

	reverse(ans.begin(), ans.end());


	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s1, s2;
	cin >> s1;
	cin >> s2;
	int m = s1.size();
	int n = s2.size();

	cout << lcs(s1, s2, m, n) << endl;

}