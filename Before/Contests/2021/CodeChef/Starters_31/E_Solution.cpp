#include <bits/stdc++.h>
using namespace std;

bool is_possible(vector<int> &b) {
	int n = b.size();
	for (int i = 0; i < n - 1; i++) {
		if (b[i + 1] == -1) {
			b[i + 1] = b[i];
		}
		if (b[i + 1] < b[i] || b[i] > i + 1) {
			return false;
		}
	}
	return true;
}

vector<int> solution(vector<int> b, int n) {
	if (b[0] == -1) b[0] = 0;

	bool is = is_possible(b);

	if (not is) {
		return vector<int> { -1};
	}


	set<int> st;
	for (int i = 0; i < b[n - 1]; i++) {
		st.emplace(i);
	}
	for (int i = 0; i < n; i++) {
		st.emplace(b[n - 1] + 1 + i);
	}
	vector<int> a(n, -1);
	int last = 0;
	for (int i = 0; i < n; i++) {
		if (b[i] > last) {
			a[i] = last;
			st.erase(last);
			last = b[i];
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == -1) {
			a[i] = *st.begin();
			st.erase(st.begin());
		}
	}
	return a;
}

int main() {
	int tt = 1;
	// cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> b(n);
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		vector<int> ans = solution(b, n);
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	return 0;
}