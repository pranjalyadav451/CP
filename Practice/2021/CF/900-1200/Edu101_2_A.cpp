#include <bits/stdc++.h>
#define ll long long
#define vec vector
#define MOD 1000000007
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

using namespace std;
string solve(string &s, int n)
{
	int nOpen = 0;
	int nClose = 0;
	int nq = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(') nOpen++;
		if (s[i] == ')') nClose++;
		if (s[i] == '?') nq++;

		if (nOpen + nq < nClose)
			return "NO";
	}
	if (nOpen == nClose and nq % 2 != 0)
		return "NO";

	nOpen = 0; nClose = 0; nq = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (s[i] == '(') nOpen++;
		if (s[i] == ')') nClose++;
		if (s[i] == '?') nq++;

		if (nClose + nq < nOpen)
			return "NO";
	}
	if (nOpen == nClose and nq % 2 != 0)
		return "NO";
	return "YES";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int tt;
	cin >> tt;
	while (tt--)
	{
		string s;
		cin >> s;
		int n = s.size();

		cout << solve(s, n);
		cout << endl;
	}
}