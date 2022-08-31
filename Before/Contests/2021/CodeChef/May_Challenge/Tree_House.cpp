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
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define pp(...) cerr << "\t[" << #__VA_ARGS__ << "]:\t", dbg_out(__VA_ARGS__)
#define ppp(x) cerr << x << "\n"
#else
#define pp(...)
#define ppp(...)
#endif
template<class Fun> class y_combinator_result { Fun fun_; public: template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {} template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); } };
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
#define yc y_combinator

typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef long double ld;
#define all(x) (x).begin(),(x).end()
#define rep(i, a, b) for (int i = (a); i <= (b); (i)++)
#define rrep(i, a, b) for (int i = (a); i >= (b); (i)--)
#define deb(x) cout << #x << ": " << x << endl
#define deb2(x, y) cout << #x << ": " << x << "  " << #y << ": " << y << endl

const ll MXN = 3e5 + 10;
vector<bool> visited(MXN, 0);

ll dfs(vector<ll> graph[], ll node, vector<ll>& nodeHeight) {
	if (visited[node]) return 0;
	visited[node] = true;
	ll num = 0;

	for (ll a : graph[node]) {
		if (visited[a])
			continue;
		num = max(num, dfs(graph, a, nodeHeight));
	}


	return nodeHeight[node] = num + 1;
}

const ll _mod = 1e9 + 7;

void solve(vector<ll> graph[], ll n, ll x) {

	vector<ll> nodeSize(n + 1);

	visited.assign(MXN, 0);
	dfs(graph, 1, nodeSize);
	visited.assign(MXN, 0);

	queue<pll> q;
	vector<pll>order;

	q.push({1, x});
	visited[1] = 1;
	ll ans = 0;

	while (q.empty() == false) {

		ll nd = q.front().first, wt = q.front().second;
		q.pop();

		ans = (ans % _mod + wt % _mod) % _mod;

		for (ll ele : graph[nd]) {

			if (visited[ele]) continue;
			visited[ele] = true;
			order.push_back({nodeSize[ele], ele});
		}

		ll every = wt;
		wt = wt * (order.size());
		sort(order.rbegin(), order.rend());

		while (order.empty() == false) {
			pll t = order.back();
			q.push({t.second, wt });
			wt = wt - every;
			order.pop_back();
		}
	}
	cout << ans << endl;
}
int  main() {
	ll tt;
	cin >> tt;
	while (tt--) {
		ll n, x;
		cin >> n >> x;
		vector<ll> graph[n + 1];
		for (ll i = 1; i <= n - 1; i++) {
			ll u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		solve(graph, n, x);
	}
}
