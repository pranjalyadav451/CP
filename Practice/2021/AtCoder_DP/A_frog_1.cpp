#include <bits/stdc++.h>
#include <vector>
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

using namespace std;

const int N = 1e5;

int dp[N];
int solve(int n, int arr[]) {
	dp[0] = 0;
	dp[1] = abs(arr[1] - arr[0]);
	for (int i = 2; i < n; i++)
		dp[i] = min(dp[i - 2] + abs(arr[i] - arr[i - 2]),
		            dp[i - 1] + abs(arr[i] - arr[i - 1]));
	return dp[n - 1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << solve(n, arr) << endl;
}