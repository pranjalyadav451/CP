#include <bits/stdc++.h>
#define ll long long
#define vec vector
#define MOD 1000000007
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define trav(a, x) for (auto &a : x)
#define fo(i, n) for (i = 0; i < n; i++)
#define deb(x) cout << #x << "=>" << x << endl
#define deb2(x, y) cout << #x << "=>" << x << "," << #y << "=>" << y << endl

using namespace std;
ll solve(int a[], int n)
{

	unordered_set<int> hash;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			hash.insert(a[j] - a[i]);
		}
	}
	deb(hash.size());
	return hash.size();
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

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		cout << solve(a, n) << endl;
	}
}