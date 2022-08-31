#include <bits/stdc++.h>
#define ll long long
#define vec vector
#define MOD 1000000007
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ff first
#define ss second
#define read(x) cin >> x
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define rev(i, a, b) for (int i = (a); i >= (b); i--)
#define deb(x) cout << #x << ": " << x << endl
#define deb2(x, y) cout << #x << ": " << x << "	| " << #y << ": " << y << endl

using namespace std;

ll solve(ll n)
{
	ll base = 2050e15;
	int count = 0;

	if (n == 0)
		return 0;
	while (n >= 2050 and base >= 2050)
	{
		if (n >= base)
		{
			count += n / base;
			n = n % base;
		}
		else
		{
			base /= 10;
		}
	}

	// Silly mistake here
	/**
	 * While doing the modulo operations
	 * n==0 if the number is expressible into 2050 numbers.
	 * count==0 tells if the number is not greater than 2050.
	 * wrong code : return count==0?-1:count;
	*/

	return n != 0 ? -1 : count;
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
		ll n;
		cin >> n;
		cout << solve(n) << endl;
	}
}

/**
 * Notes -:
*/