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

const ll LIM = 1e4 + 10;
bool squares[LIM];

void iSsquare()
{
	for (int i = 0; i * i <= LIM - 9; i++)
	{
		squares[i * i] = true;
	}
}
// Neat little trick to find out the number of perfect squares upto a gien LIMIT.



string solve(vector<ll> &arr, ll n)
{
	for (int i = 0; i < n; i++)
		if (squares[arr[i]] == false)
			return "YES";
	return "NO";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll tt;
	cin >> tt;
	memset(squares, 0, sizeof(squares));

	while (tt--)
	{
		ll n;
		cin >> n;
		vector<ll> arr(n);
		for (auto &a : arr)
			cin >> a;
		iSsquare();
		cout << solve(arr, n);
		cout << endl;
	}
}