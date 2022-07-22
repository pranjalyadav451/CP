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

double dp[3005][3005];


double moreHeads(double arr[], int n, int currentHeads)
{
	if (currentHeads == 0)
		return 1;
	if (n == 0)
		return 0;

	if (dp[n][currentHeads] > -0.1)
		return dp[n][currentHeads];

	return dp[n][currentHeads] = moreHeads(arr, n - 1, currentHeads - 1) * arr[n - 1] + moreHeads(arr, n - 1, currentHeads ) * ((double)1 - arr[n - 1]);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	double arr[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int currentHeads = (n) / 2 + 1;

	memset(dp, -1, sizeof(dp));

	cout << fixed << setprecision(10) << moreHeads(arr, n, currentHeads);
	cout << endl;

}