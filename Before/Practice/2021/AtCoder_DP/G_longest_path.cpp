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

vector<int> graph[100005];

int dp[100005];

int findLongestPath(int src)
{
	if (dp[src] != -1)
		return dp[src];

	int result = INT_MIN;
	bool no_neighbour = true;
	for (int neighbour : graph[src])
	{
		no_neighbour = false;
		result = max(result, findLongestPath(neighbour));
	}

	return dp[src] = no_neighbour ? 0 : result + 1;

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	memset(dp, -1, sizeof(dp));
	int n, m;
	cin >> n >> m;

	while (m--)
	{
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
	}

	int result = INT_MIN;

	for (int i = 1; i <= n; i++)
	{
		result = max(result, findLongestPath(i));
	}
	cout << result << endl;
}

