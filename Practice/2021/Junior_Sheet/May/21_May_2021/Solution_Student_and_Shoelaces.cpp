#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, ans = 0, A[110] = {0};
	vector<int> Adj[110];
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		A[a]++;
		A[b]++;
		Adj[a].push_back(b);
		Adj[b].push_back(a);
	}
	while (1) {
		vector<int> v;
		for (int i = 1; i <= n; i++) {
			if (A[i] == 1) {
				v.push_back(i);
			}
		}
		if (v.empty()) break;
		ans++;
		for (int i : v) {
			A[i]--;
			for (int j : Adj[i])
				A[j]--;
		}
	}
	cout << ans;
	return 0;
}
