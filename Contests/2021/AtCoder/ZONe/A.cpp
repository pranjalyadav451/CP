#include <bits/stdc++.h>
#define ll long long
#define vec vector
#define MOD 1000000007
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ff first
#define ss second
#define read(x) cin>>x
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define deb(x) cout << #x << ": " << x << endl
#define deb2(x, y) cout << #x << ": " << x << ", " << #y << ": " << y << endl

using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	int pos = 0;
	int count = 0;
	while (pos != string::npos and pos < 12)
	{
		pos = s.find("ZONe", pos);
		if (pos != string::npos)
		{
			count++;
			pos++;
		}

	}
	cout << count << endl;
}

/*
    Notes -:
*/