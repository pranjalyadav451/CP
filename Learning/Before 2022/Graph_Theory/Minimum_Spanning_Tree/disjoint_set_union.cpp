#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }
int __fastio = fastio();
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

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define rep(i, a, b) for (int i = (a); i <= (b); (i)++)
#define rrep(i, a, b) for (int i = (a); i >= (b); (i)--)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << ": " << x << "  " << #y << ": " << y << endl

const int N = 1e4 + 1;
int parent[N];
int cap[N];

int get_root(int u) {
	if (parent[u] == -1) return u;
	return parent[u] = get_root(parent[u]);
}

void merge(int u, int v) {
	if (cap[u] >= cap[v]) {
		parent[v] = u;
		cap[u] += cap[v];
		return;
	}
	else merge(v, u);
}


int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		parent[i] = -1;
		cap[i] = 1;
	}

	int q;
	cin >> q;
	while (q--) {
		string qtype;
		int u, v;
		cin >> qtype >> u >> v;


		int u_root = get_root(u);
		int v_root = get_root(v);
		if (qtype == "M") {
			if (u_root == v_root) {
				cout << "Do Nothing" << endl;
			}
			else merge(u, v);
		}
		else if (qtype == "A") {
			/* You need to answer if 'u' and 'v' belong to the same set*/
			if (u_root == v_root) {
				cout << "YES" << endl;
				cout << "u and v belong to the same set: " << u_root << endl;
			}
			else {
				cout << "NO, they do not belong to same set.\n" << "u belongs to: " << u_root << "\t" << "v belongs to: " << v_root << endl;
			}
		}
	}
}

/**
 * Two optimizations -:
 	- size heuristics
 	- path compression
*/