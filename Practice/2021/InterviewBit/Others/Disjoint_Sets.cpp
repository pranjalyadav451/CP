#include <bits/stdc++.h>
using namespace std;
#define dbg(x)                              cout << #x << ": " << x << endl
#define dbgg(x, y)                          cout << #x << ": " << x << "  " << #y << ": " << y << endl
template<typename A, typename B>    ostream& operator<<(ostream &os, const pair<A, B> &p);
template<typename A>                ostream& operator<<(ostream &os, const set<A> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A>                ostream& operator<<(ostream &os, const multiset<A> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A, typename B>    ostream& operator<<(ostream &os, const map<A, B> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}"; }
template<typename T>                ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; string sep = ""; for (auto e : v) os << sep << e, sep = ", "; return os << "]"; }
template<typename T>                ostream& operator<<(ostream& os, const list<T>& v) { os << "["; string sep = ""; for (auto e : v) os << sep << e, sep = ", "; return os << "]"; }
template<typename T, size_t L>      ostream& operator<<(ostream& os, const array<T, L>& v) { os << "["; string sep = ""; for (int i = 0; i < L; ++i) os << sep << v[i], sep = ", "; return os << "]"; }
template<typename A, typename B>    ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }

int solve(vector<vector<int> > &A) {
	int N = A.size();
	sort(A.begin(), A.end());
	cout << A << endl;
	stack<pair<int, int>> disjoint;

	for (int i = 0; i < N; i++) {
		pair<int, int> current = {A[i][0], A[i][1]};
		if (disjoint.size() > 0) {
			pair<int, int> top_ele = disjoint.top();
			if (current.first >= top_ele.first and current.second <= top_ele.second) {
				disjoint.pop();
				disjoint.push(current);
			}
			if (current.first > top_ele.second) {
				disjoint.push(current);
			}
		}
		else {
			disjoint.push(current);
		}


	}
	return disjoint.size();
}


int main() {
	int N; cin >> N;
	vector<vector<int>> arr(N, vector<int>(2));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> arr[i][j];
		}
	}
	int ans = solve(arr);
	cout << ans << endl;
}
