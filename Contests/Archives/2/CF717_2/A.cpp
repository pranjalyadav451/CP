#include <bits/stdc++.h>
#define ll long long
#define vec vector
#define MOD 1000000007
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ff first
#define ss second
#define deb(x) cout << #x << ": " << x << endl
#define deb2(x, y) cout << #x << ": " << x << ", " << #y << ": " << y << endl

using namespace std;

void solve(vector<int>&arr, int n, int k)
{
	// int count = 0;
	for (int i = 0; i < n - 1 and k > 0; i++)
	{
		while (arr[i] != 0 and k > 0)
		{
			arr[i]--;
			arr[n - 1]++;
			k--;
		}
	}

	for (int i : arr)
	{
		cout << i << " ";
	}
	cout << endl;
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
		vector <int>arr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		solve(arr, n, k);

	}
}

/*
    Notes -:
*/