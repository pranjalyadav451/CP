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

ll pw (ll n, ll k )
{
	ll ans = 1;
	for (int i = 0; i < k; i++)
	{
		ans = (ans % MOD * n % MOD) % MOD;
	}
	return ans;
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
		int n, k;
		cin >> n >> k;
		cout << pw(n, k) << endl;
	}
}

// Notes -:
/*
	-> Problem related to basic combinatorics.
	-> Each array element will have 'k' bits because we have to maximize the sum.
	-> AT A GIVEN BIT POSITION 'i'-> Out of the 'n' elements only one will have '0' at the given i'th position.
	-> If you have any confusion around the sum -:
		- Try this example n = 3, k = 3
		-> 111 + 111 + 000
		-> 110 + 011 + 101

		- Both of the given options given the same sum because the number of 1's and 0's in a given column always remain same.
*/