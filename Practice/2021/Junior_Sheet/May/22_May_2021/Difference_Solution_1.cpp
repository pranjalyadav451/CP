#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } int __fastio = fastio();
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p);
template<typename A> ostream& operator<<(ostream &os, const set<A> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A> ostream& operator<<(ostream &os, const multiset<A> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const map<A, B> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}"; }
template<typename T>ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; string sep = ""; for (auto e : v) os << sep << e, sep = ", "; return os << "]"; }
template<typename T, size_t L>ostream& operator<<(ostream& os, const array<T, L>& v) { os << "["; string sep = ""; for (int i = 0; i < L; ++i) os << sep << v[i], sep = ", "; return os << "]"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }


template<class Fun> class y_combinator_result { Fun fun_; public: template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {} template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); } };
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
#define yc y_combinator

typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef long double ld;
typedef vector<vector<ll>> vvl; typedef vector<ll> vll; typedef vector<pll> vpl;
#define all(x) (x).begin(),(x).end()
#define REP(i, a, b) for (int i = (a); i <= (b); (i)++)
#define RREP(i, a, b) for (int i = (a); i >= (b); (i)--)
#define dbg(x) cout << #x << ": " << x << endl
#define dbgg(x, y) cout << #x << ": " << x << "  " << #y << ": " << y << endl
#define log_all(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
	cout << "[" << "( " << vars << " )" << " :-> ( ";
	string delim = ""; (..., (cout << delim << values, delim = ", ")); cout << " )]" << endl;
}

vector<int> g[505], vg[505];
int d[505], used[505];
int dfs(int v) {
	if (used[v])    return 0;
	used[v] = 1;
	int sum = d[v];
	for (int i = 0; i < g[v].size(); i++)
		sum += dfs(g[v][i]);
	return sum;
}
int dfs2(int v) {
	if (used[v])    return 0;
	used[v] = 1;
	int sum = d[v];
	for (int i = 0; i < vg[v].size(); i++)
		sum += dfs2(vg[v][i]);
	return sum;
}
int main() {
	int cases = 0;
	int n, m, q;
	int x, y;
	while (cin >> n >> m) {
		if (n == 0 and m == 0) return 0;

		int total_weight = 0;
		for (int i = 1; i <= n; i++) {
			cin >> d[i];
			total_weight += d[i];
		}
		for (int i = 1; i <= n; i++) {
			g[i].clear(), vg[i].clear();
		}

		for (int i = 0; i < m; i++) {
			cin >> x >> y;
			g[x].push_back(y);
			vg[y].push_back(x);
		}

		cin >> q;
		cout << "Case #" << ++cases << ":" << endl;
		while (q--) {
			cin >> x;
			memset(used, 0, sizeof(used));
			int minD = dfs2(x);
			memset(used, 0, sizeof(used));
			int maxD = total_weight - dfs(x) + d[x];
			cout << maxD - minD << endl;
		}
		cout << endl;
	}
	return 0;
}