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

template<class Fun> class y_combinator_result { Fun fun_; public: template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {} template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); } };
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
#define yc y_combinator

typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef long double ld;
#define ALL(x) (x).begin(),(x).end()
#define REP(i, a, b) for (int i = (a); i <= (b); (i)++)
#define RREP(i, a, b) for (int i = (a); i >= (b); (i)--)
#define dbg(x) cout << #x << ": " << x << endl
#define dbgg(x, y) cout << #x << ": " << x << "  " << #y << ": " << y << endl

/**
 * More Knowledge on Topologicalcol Sorting Required.
 	- Generating all Topological Sort arrangements.
*/

vector<int> duration(505, 0);
vector<bool> visited(505, 0);
ll dfs(vector<int> graph[], int node) {
	if (visited[node]) return 0;
	visited[node] = true;
	ll sum = 0;
	for (auto a : graph[node]) {
		sum += dfs(graph, a);
	}
	return sum + duration[node];
}


int main() {
	int v, e, case_number = 0;
	while (cin >> v >> e) {
		// Terminating Condition
		case_number++;
		if (v == 0 and e == 0) return 0;

		ll total_time = 0;
		REP(i, 1, v) {
			cin >> duration[i];
			total_time += duration[i];
		}

		vector<int> before[v + 1], after[v + 1];
		REP(i, 1, e) {
			int x, y;
			cin >> x >> y;
			before[y].push_back(x);
			after[x].push_back(y);
		}

		ll q, x;
		cin >> q;
		cout << "Case #" << case_number << ":" << endl;
		while (q--) {
			cin >> x;
			visited.assign(v + 1, false);
			ll  min_time = dfs(before, x);
			visited.assign(v + 1, false);
			ll max_time = total_time - dfs(after, x) + duration[x];
			cout << max_time - min_time << endl;
		}
		cout << endl;
	}
}
