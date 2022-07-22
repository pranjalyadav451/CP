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

// int mxSum(vec<vec<int>> &arr, int n, int m)
// {
// 	int ans = 0;

// }

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int tt;
	cin >> tt;
	while (tt--)
	{
		int n, m;
		cin >> n >> m;

		vector<vector<int>> arr(n, vector<int>(m));
		int negs = 0;
		int minAbs = INT_MAX;
		ll sum = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> arr[i][j];
				if (arr[i][j] < 0)
					negs++;
				minAbs = min(minAbs, abs(arr[i][j]));
				sum += abs(arr[i][j]);
			}
		}

		if (negs % 2 == 0)
			cout << sum;
		else
			cout << sum - 2 * minAbs ;

		cout << endl;
	}
}