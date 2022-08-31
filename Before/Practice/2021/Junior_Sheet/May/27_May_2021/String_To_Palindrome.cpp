#include <bits/stdc++.h>
using namespace std;
int fastio() {
	ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0;
} int __fastio = fastio();
template<typename A, typename B> ostream &operator<<(ostream &os, const pair<A, B> &p);
template<typename A> ostream &operator<<(ostream &os, const set<A> &m) {
	os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}";
}
template<typename A> ostream &operator<<(ostream &os, const multiset<A> &m) {
	os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}";
}
template<typename A, typename B> ostream &operator<<(ostream &os, const map<A, B> &m) {
	os << "{"; string sep = ""; for (auto e : m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}";
}
template<typename T>ostream &operator<<(ostream &os, const vector<T> &v) {
	os << "["; string sep = ""; for (auto e : v) os << sep << e, sep = ", "; return os << "]";
}
template<typename T, size_t L>ostream &operator<<(ostream &os, const array<T, L> &v) {
	os << "["; string sep = ""; for (int i = 0; i < L; ++i) os << sep << v[i], sep = ", "; return os << "]";
}
template<typename A, typename B> ostream &operator<<(ostream &os, const pair<A, B> &p) {
	os << '(' << p.first << ", " << p.second << ')'; return os;
}
void dbg_out() {
	cerr << endl;
}
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
	cerr << ' ' << H; dbg_out(T...);
}

template<class Fun> class y_combinator_result {
Fun fun_; public: template<class T> explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {} template<class ...Args> decltype(auto) operator()(Args &&...args) {
	return fun_(std::ref(*this), std::forward<Args>(args)...);
}
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
#define yc y_combinator

typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef long double ld;
#define ALL(x) (x).begin(),(x).end()
#define REP(i, a, b) for (int i = (a); i <= (b); (i)++)
#define RREP(i, a, b) for (int i = (a); i >= (b); (i)--)
#define dbg(x) cout << #x << ": " << x << endl
#define dbgg(x, y) cout << #x << ": " << x << "  " << #y << ": " << y << endl

/** *** GLOBALS *** **/


vector<int> idx;
const int mxn = 1e3 + 1;
int dp[mxn][mxn];
int edit(string &s, int a, int b) {
	if (a < b) {
		int &ret = dp[a][b];
		if (ret != -1) {
			return ret;
		}
		if (s[a] == s[b]) {
			return ret = edit(s, a + 1, b - 1);
		}
		else {
			int ans = min({ edit(s, a + 1, b), edit(s, a, b - 1),edit(s,a + 1, b - 1) });
			return ret = ans + 1;
		}
	}
	else {
		return 0;
	}
}

void solve(string s, int n) {

	memset(dp, -1, sizeof dp);
	int cost = edit(s, 0, n - 1);
	cout << cost << endl;
}



int main() {
	/** *** INPUT *** **/
	int tt = 1;
	cin >> tt;
	REP(i, 1, tt) {
		string s;
		cin >> s;
		int n = s.size();

		/** *** SOLUTION *** **/
		cout << "Case " << i << ": " ;
			solve(s, n);
	}
}
