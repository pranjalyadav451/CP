#include <bits/stdc++.h>
#define ll long long
#define vec vector
#define MOD 1000000007
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ff first
#define ss second
#define dbg(x) cout << #x << ": " << x << endl
#define dbgg(x, y) cout << #x << ": " << x << ", " << #y << ": " << y << endl

using namespace std;

void solve(string &s) {
	int n = s.size(), idx;
	bool can_all = (s.find("00") == -1) or (s.find("11") == -1);
	// now if we remove all the non-adjacent characters
	// we will have only the groups of adjacent zeros and ones
	// and in that case any group of one cannot come before a group of zero.

	int adj_ones = s.find("11"), adj_zeros = s.rfind("00");
	if (can_all) cout << "YES" << endl;
	else {
		if (!(adj_ones < adj_zeros)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
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
		solve(s);
	}
}

/*
    Notes -:
*/