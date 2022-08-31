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
#define fo(i, n) for (int i = 0; i < n; i++)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

using namespace std;
bool equalSum(int a[], int n, int target)
{
	if (target == 0)
		return 1;
	if (n == 0 and target != 0)
		return 0;
	if (target >= a[n - 1])
	{
		return (equalSum(a, n - 1, target - a[n - 1])) || (equalSum(a, n - 1, target));
	}
	else
	{
		return equalSum(a, n - 1, target);
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int testCase = 1;
	cin >> testCase;
	// deb(testCase);
	while (testCase--)
	{
		int n;
		cin >> n;
		int a[n];
		ll sum = 0;
		fo(i, n)
		{
			cin >> a[i];
			sum += a[i];
		}
		if (sum % 2 == 0 and equalSum(a, n, sum / 2))
			cout << "True" << endl;
		else
			cout << "False" << endl;
	}
}