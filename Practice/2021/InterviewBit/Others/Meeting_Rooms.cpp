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


bool comp(const vector<int> &a , const vector<int> &b) {
	return a[0] < b[0];
}

int solve(vector<vector<int> > &A) {
	int N = A.size();
	priority_queue <int, vector<int>, greater<int> > end_times;
	int ans = 0;
	sort(A.begin(), A.end(), comp);
	for (int i = 0 ; i < N; i++) {
		while (end_times.size() > 0 and A[i][0] >= end_times.top()) {
			end_times.pop();
		}
		end_times.push(A[i][1]);
		ans = max(ans, (int)end_times.size());
	}
	return ans;
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