#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define deb(x) cout << #x << " => " << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

#define MOD 1000000007
using namespace std;
string solve(string &s)
{
	// char alice = 'a';
	// char bob = 'z';
	int len = s.size();
	for (int i = 0; i < len; ++i)
	{
		if (i % 2 == 0)
		{
			if (s[i] == 'a')
				s[i] = 'b';
			else
				s[i] = 'a';
		}
		else
		{
			if (s[i] == 'z')
				s[i] = 'y';
			else
				s[i] = 'z';
		}
	}
	return s;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int tt;
	cin >> tt;

	while (tt--)
	{
		string s;
		cin >> s;
		cout << solve(s) << endl;
	}
}
