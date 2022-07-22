#include <bits/stdc++.h>
#include <inttypes.h>
#include <limits.h>
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

template<class Fun> class y_combinator_result { Fun fun_; public: template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {} template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); } };
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
#define yc y_combinator

typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef long double ld;
#define ALL(x) (x).begin(),(x).end()
#define REP(i, a, b) for (int i = (a); i <= (b); (i)++)
#define RREP(i, a, b) for (int i = (a); i >= (b); (i)--)
#define dbg(x) cout << #x << ": " << x << endl
#define dbgg(x, y) cout << #x << ": " << x << "  " << #y << ": " << y << endl

/** *** GLOBALS *** **/

const int INF = 1000000000;
const int mxn = 2e5;
vector<vector<pair<int, int>>> adj(mxn);

void printPath(vector<int> parent, int j)
{
	if (parent[j] == -1)
		return;

	printPath(parent, parent[j]);

	cout << j << " ";
}



void dijkstra(int s, vector<int> & d, vector<int> & p) {
	int n = adj.size();
	d.assign(n, INF);
	p.assign(n, -1);
	vector<bool> u(n, false);

	d[s] = 0;
	for (int i = 0; i < n; i++) {
		int v = -1;
		for (int j = 0; j < n; j++) {
			if (!u[j] && (v == -1 || d[j] < d[v]))
				v = j;
		}

		if (d[v] == INF)
			break;

		u[v] = true;
		for (auto edge : adj[v]) {
			int to = edge.first;
			int len = edge.second;

			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				p[to] = v;
			}
		}
	}
}
void solve(int nodes, int m, int n, int s) {
	vector<int> d, p;
	dijkstra(s, d, p);
	vector<int> go = {1, n, m*n - n + 1 , m * n};
	for (int a : go) {
		cout << s << " ";
		printPath(p, a);
		cout << endl;
	}

}



int main() {
	/** *** INPUT *** **/
	int m, n, s;
	cin >> m >> n >> s;
	int nodes = m * n;

	/** Input **/
	for (int i = 1; i <= nodes; i++) {
		int node ;
		cin >> node;
		vector<int> can(8);
		for (int i = 0; i < 8; i++) {
			cin >> can[i];
		}
		for (int i = 0; i < 8; i++) {
			if (can[i] == 1) {
				switch (i + 1) {
				case 1:
					adj[node].push_back({node - n, 1});
					break;
				case 2:
					adj[node].push_back({node - n + 1, 1});
					break;
				case 3:
					adj[node].push_back({node + 1, 1});
					break;
				case 4:
					adj[node].push_back({node + n + 1, 1});
					break;
				case 5:
					adj[node].push_back({node + n, 1});
					break;
				case 6:
					adj[node].push_back({node + n - 1, 1});
					break;
				case 7:
					adj[node].push_back({node - 1, 1});
					break;
				case 8:
					adj[node].push_back({node - n - 1, 1});
					break;
				}
			}
		}
	}

	/** Solution **/
	solve(nodes, m, n, s);
}
