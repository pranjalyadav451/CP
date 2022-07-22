#include <bits/stdc++.h>
using namespace std;
int K, L, M;
vector<long long > choices;
const int mxn = 1e6 + 10;
int rec[mxn];

int win(long long sum) {
	if (sum < 0) return 1;
	if (sum == 0) return 0;

	int &ans = rec[sum];
	if (ans != -1) return ans;
	ans = 0;
	for (int i = 0; i < 3; i++) {
		ans |= !win(sum - choices[i]);
	}
	return ans;
}

void solve() {
	cin >> K >> L >> M;
	choices = { 1, K , L };
	vector<long long> queries(M);
	for (auto &a : queries) {
		cin >> a;
	}
	memset(rec, -1, sizeof(rec));
	for (int i = 0; i < M; i++) {
		int ans = win(queries[i]);
		cout << (ans ? "A" : "B");
	}
}

int main() {
	int tt = 1;
	while (tt--) {
		solve();
	}
}
