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

typedef long long ll;

int cnt_moves(int A) {
	long long sum = abs(A);
	long long left = 1, right = sum , mid = 0, ans = -1;
	while (left <= right) {
		mid = left + (right - left) / 2;
		long long current = (mid * (mid + 1)) / 2;
		if (current == sum) return mid;
		if (current < sum) {
			left = mid + 1;
		} else {
			ans = mid;
			right = mid - 1;
		}
	}
	return ans;
}
int solve(int A) {
	A = abs(A);
	ll cnt = cnt_moves(A);
	ll diff = (cnt * (cnt + 1)) / 2 - A;
	if (diff % 2 == 0) return cnt + 1;
	else {
		if (cnt % 2 == 0) return cnt + 1;
		else return cnt + 2;
	}
}




int main() {
	int N ; cin >> N;
	int ans = solve(N);
	cout << ans << endl;
}