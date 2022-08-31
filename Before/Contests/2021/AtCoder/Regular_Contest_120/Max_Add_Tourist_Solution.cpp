/**
 *    author:  tourist
 *    created: 23.05.2021 13:59:17
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	long long s = 0;
	long long t = 0;
	long long m = 0;
	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;
		s += x;
		t += s;
		m = max(m, x);
		cout << t + m * (i + 1) << '\n';
	}
	return 0;
}
