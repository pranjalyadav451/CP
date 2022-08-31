// why is this code not working
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


bool bfs(vector<int> graph[], int start, vector<int> &visited) {
	queue<int> nodes;
	nodes.push(start);
	visited[start] = 0;

	while (nodes.size()) {
		int at = nodes.front();
		nodes.pop();

		for (int a : graph[at]) {
			if (visited[a] == -1) {
				visited[a] = 1 - visited[at];
				nodes.push(at);
			}
			else if (visited[a] == visited[at])
				return false;
		}
	}
	return true;
}

int solve(int A, vector<vector<int> > &B) {
	int N = A + 1, M = B.size();
	vector<int> graph[N];

	for (int i = 0; i < M; i++) {
		int go = B[i][0] , to = B[i][1];
		graph[go].push_back(to);
		graph[to].push_back(go);
	}
	vector<int> visited(N, -1);

	for (int i = 1; i < N; i++) {
		if (visited[i]) continue;
		if (bfs(graph, i, visited) == false) return false;
	}
	return true;
}
