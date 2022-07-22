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

/*
*-> The absolute difference between the number of ones and zeroes upto the i'th index in the string 'a' will always remain same even after we flip the bits.
*-> Because every time we flip the bits, the number of zeroes and ones are getting swapped.
*/


string solve(string &a, string &b, int n)
{
	bool flipped = false;
	int nz = 0, n1 = 0;
	for (auto i : a)
	{
		if (i == '1') n1++;
		else nz++;
	}

	for (int i = n - 1; i >= 0; i--)
	{
		if ((flipped == false and a[i] != b[i]) or (flipped and a[i] == b[i]))
		{
			if (abs(nz - n1) == 0)
				flipped = !flipped;
			else
				return "NO";
		}
		if (a[i] == '0') nz--;
		else n1--;
	}
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
		int n;
		cin >> n;
		string a, b;
		cin >> a >> b;

		cout << solve(a, b, n) << endl;
	}
}