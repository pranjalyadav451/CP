## Rod Cutting Problem Variation
```cpp
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int memo[52][52];
vector<int> v;

int f(int a, int b)
{
	if (b - a == 1) return 0;

	if (memo[a][b] != -1) return memo[a][b];

	int x = 4000000;

	for (int i = a + 1; i < b; i++)
		x = min(v[b] - v[a] + f(a, i) + f(i, b), x);

	memo[a][b] = x;
	return x;

}

int main()
{
	int L;
	int n;
	int aux;

	while (true)
	{
		scanf("%d", &L);
		if (L == 0) break;

		cin >> n;

		v.clear();
		v.push_back(0);
		for (int i = 0; i < n; i++)
		{
			cin >> aux;
			v.push_back(aux);
		}
		v.push_back(L);

		memset(memo, -1, sizeof(memo));

		printf("The minimum cutting is %d.\n", f(0, n + 1));

	}


	return 0;
}
```
## Tanya and Candies
```cpp
#include<bits/stdc++.h>
using namespace std;
string s;
int dp[50][2000], r[50], n;
const int inf = 1e6;
int abs(int a) { return a > 0 ? a : -a; }

int getTime(int id, int k)
{
	if (k <= 0) return 0;
	if (dp[id][k]) return dp[id][k];
	dp[id][k] = inf;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == s[id] or r[i] <= r[id])
			continue;
		dp[id][k] = min(dp[id][k], abs(i - id) + getTime(i, k - r[i]));
	}
	return dp[id][k];
}

int solve(int st, int k)
{
	int ans = inf;
	for (int id = 0; id < n; id++)
		ans = min(ans, abs(st - id) + getTime(id, k - r[id]));
	return ans == inf ? -1 : ans;
}

int main()
{
	int st, k; cin >> n >> st >> k;
	for (int i = 0; i < n; i++) cin >> r[i];
	cin >> s;
	cout << solve(st - 1, k) << endl;
}
```

