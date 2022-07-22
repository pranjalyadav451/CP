#include<bits/stdc++.h>
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
#define fo(i,n) for(int i=0;i<n;i++)
#define deb(x) cout << #x << " => " << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
using namespace std;

bool isSorted(int a[], int n, int prev = INT_MAX)
{
	if (n == 1)
	{
		return true;
	}
	else
	{
		if (a[n - 1] <= prev)
		{
			return isSorted(a, n - 1, a[n - 1]);
		}
		else
		{
			return false;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);



	int testCase;
	cin >> testCase;
	while (testCase--)
	{
		int n;
		cin >> n;
		int a[n];
		fo(i, n)
		cin >> a[i];
		if (isSorted(a, n))
			cout << "sorted" << endl;
		else
			cout << "unsorted" << endl;
	}
}
