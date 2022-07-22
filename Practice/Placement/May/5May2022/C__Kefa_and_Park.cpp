/*
https://codeforces.com/contest/580/problem/C
Time Limit: 2000
Memory Limit: 256
Thu May 05 2022 11:34:36 GMT+0530 (India Standard Time)
*/
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

vector<int> is_cat;
vector<bool> visited;
vector<vector<int>> graph;
ll N , M;
ll ans = 0;

void dfs(int node, int cats) {
	if (visited[node]) return;
	visited[node] = true;

	cats = is_cat[node] ? cats + 1 : 0;

	if (cats > M) return;
	for (auto a : graph[node]) {
		dfs(a, cats);
	}
	// just hadn't put node!=0 check
	if (node != 0 and graph[node].size() == 1) ans++;
}


void solve() {

	cin >> N >> M;

	is_cat.assign(N, 0);
	graph.assign(N, vector<int>());
	visited.assign(N, 0);

	for (auto &a : is_cat) cin >> a;


	ll X , Y;
	for (int i = 0; i < N - 1; i++) {
		cin >> X >> Y;
		X--; Y--;
		graph[X].push_back(Y);
		graph[Y].push_back(X);
	}

	dfs(0, 0);
	cout << ans << endl;
}

int main() {
	int tt = 1;
	// cin >> tt; // "UN-COMMENT THIS FOR TESTCASES"
	while (tt--) {
		solve();
	}
}