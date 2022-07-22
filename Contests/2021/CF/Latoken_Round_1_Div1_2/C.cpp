#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } int __fastio = fastio();
template<typename A, typename B>    ostream& operator<<(ostream &os, const pair<A, B> &p);
template<typename A>                ostream& operator<<(ostream &os, const set<A> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A>                ostream& operator<<(ostream &os, const multiset<A> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A, typename B>    ostream& operator<<(ostream &os, const map<A, B> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}"; }
template<typename T>                ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; string sep = ""; for (auto e : v) os << sep << e, sep = ", "; return os << "]"; }
template<typename T, size_t L>      ostream& operator<<(ostream& os, const array<T, L>& v) { os << "["; string sep = ""; for (int i = 0; i < L; ++i) os << sep << v[i], sep = ", "; return os << "]"; }
template<typename A, typename B>    ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }

template<class Fun> class y_combinator_result { Fun fun_; public: template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {} template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); } };
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
#define yc y_combinator
template<typename ...Args>

void logger(string vars, Args&&... values) {cout << "[" << "( " << vars << " )" << " :-> ( "; string delim = ""; (..., (cout << delim << values, delim = ", ")); cout << " )]" << endl;}
typedef long long                           ll;
typedef pair<ll, ll>                        pll;
typedef vector<vector<ll>>                  vvl;
typedef vector<pll>                         vpl;
typedef pair<int, int>                      pii;
typedef long double                         ld;
typedef vector<ll>                          vll;

#define all(x)                              (x).begin(),(x).end()
#define REP(i, a, b)                        for (int i = (a); i <= (b); (i)++)
#define RREP(i, a, b)                       for (int i = (a); i >= (b); (i)--)
#define dbg(x)                              cout << #x << ": " << x << endl
#define dbgg(x, y)                          cout << #x << ": " << x << "  " << #y << ": " << y << endl
#define log_all(...)                        logger(#__VA_ARGS__, __VA_ARGS__)

const ll MOD = 1e9 + 7;
vector<bool>visited;

ll bin_pow(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b % 2 == 1) {
			res = ((res % MOD) * (a % MOD) ) % MOD;
		}
		b = b >> 1;
		a = ((a % MOD) * (a % MOD)) % MOD;
	}
	return res;
}


void dfs(int node, vll graph[]) {
	if (visited[node]) return;
	visited[node] = true;

	for (auto ele : graph[node]) {
		dfs(ele, graph);
	}

}

void solve() {
	int N;
	cin >> N;
	vvl arr(2, vll(N));
	for (auto &v : arr) {
		for (auto &a : v) {
			cin >> a;
		}
	}

	vll graph[N + 1];
	for (int i = 0; i < N; i++) {
		graph[arr[0][i]].push_back(arr[1][i]);
		graph[arr[1][i]].push_back(arr[0][i]);
	}

	visited.assign(N + 1, 0);
	ll components = 0;
	for (int i = 0; i < N; i++) {
		if (!visited[arr[0][i]]) {
			dfs(arr[0][i], graph);
			components++;
		}
	}
	ll ans = bin_pow(2, components);
	cout << ans << endl;
}

int main() {
	int tt = 1;
	cin >> tt;
	while (tt--) {
		solve();
	}
}
