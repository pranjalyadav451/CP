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
		int i  = s.find("11");
		int j = s.rfind("00");

		if (i != -1 and j != -1)
		{
			if (i > j)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		else
		{
			cout << "YES" << endl;;
		}
	}
}