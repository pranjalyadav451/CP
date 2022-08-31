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
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define deb(x) cout << #x << ": " << x << endl
#define deb2(x, y) cout << #x << ": " << x << ", " << #y << ": " << y << endl

using namespace std;

int solve(vector<ll> &arr, int n, int k)
{
	if (is_sorted(arr.rbegin(), arr.rend()) == 1)
		return -1;

	while (k >= 0)
	{
		rep(i, 0, n -	 1)
		{
			if (arr[i + 1] > arr[i])
			{
				k--;
				arr[i]++;
				if (k <= 0)
					return i + 1;
				break;
			}
		}
		if (is_sorted(arr.rbegin(), arr.rend()))
			return -1;
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
		int n, k;
		cin >> n >> k;

		vector<ll> arr(n);
		rep(i, 0, n)
		cin >>
		    arr[i];

		cout << solve(arr, n, k) << endl;
	}
}

/*
    Notes -:
*/