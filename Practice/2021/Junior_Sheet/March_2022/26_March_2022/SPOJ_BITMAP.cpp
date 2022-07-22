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

bool is_valid(int i, int j, int N , int M) {
	return i >= 0 and i < N and j >= 0 and j < M;
}
const vpl moves = {
	{ -1, 0}, {1, 0}, {0, 1}, {0, -1}
};
void print(vector<vector<int>> &arr) {
	for (auto &a : arr) {
		for (auto &b : a) {
			cout << b << " ";
		}
		cout << endl;
	}
}

void bfs(vector<string> &graph, vector<vector<int>>&dist, queue<pll>&nodes) {
	// MULTI - SOURCE BFS
	int N = graph.size(), M = graph[0].size();
	vector<vector<bool>>visited(N, vector<bool>(M));

	while (nodes.size()) {
		pair<int, int> current = nodes.front();
		nodes.pop();

		for (auto move : moves) {
			int x = current.first + move.first, y = current.second + move.second;
			if (is_valid(x, y, N, M) and visited[x][y] == false) {
				dist[x][y] = min(dist[x][y], dist[current.first][current.second] + 1);
				nodes.push(make_pair(x, y));
				visited[x][y] = true;
			}
		}
	}
}




void solve() {
	int N , M;
	cin >> N >> M;
	vector<string>arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	const int INF = 1e8;
	queue<pll> nodes;
	vector<vector<int>> dist(N, vector<int>(M, INF));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == '1') {
				nodes.push(make_pair(i, j));
				dist[i][j] = 0;
			}
		}
	}
	bfs(arr, dist, nodes);
	print(dist);
}
int main() {
	int tt = 1;
	cin >> tt; // "UN-COMMENT THIS FOR TESTCASES"

	while (tt--) {
		solve();
	}
}