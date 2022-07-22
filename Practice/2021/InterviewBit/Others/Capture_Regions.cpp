#include <bits/stdc++.h>
#include <string>
#include <vector>
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


const vector<pair<int, int>> moves = {
	{ -1, 0}, {1, 0}, {0, -1}, {0, 1}
};
bool is_valid(int x, int y, int N , int M) {
	return x >= 0 and x < N and y >= 0 and y < M;
}
void bfs(vector<vector<char>> &A, vector<vector<bool>>& visited, pair<int, int> start) {
	queue<pair<int, int>> nodes;
	nodes.push(start);
	int N = A.size(), M = A[0].size();
	visited[start.first][start.second] = true;

	while (nodes.size()) {
		pair<int, int> temp = nodes.front();
		nodes.pop();
		for (auto move : moves) {
			int x = temp.first + move.first , y = temp.second + move.second;
			if (is_valid(x, y, N, M) and visited[x][y] == false and  A[x][y] == 'O') {
				nodes.push({x, y});
				visited[x][y] = true;
			}
		}

	}
}
void solve(vector<vector<char> > &A) {
	cout << A << endl;
	int N = A.size(), M = A[0].size();

	vector<vector<bool>>visited(N, vector<bool>(M, 0));

	for (int i = 0; i < N; i++) {
		if (visited[i][0]) continue;
		if (A[i][0] == 'O') bfs(A, visited, {i, 0});
	}
	for (int i = 0; i < N; i++) {
		if (visited[i][M - 1]) continue;
		if (A[i][M - 1] == 'O') bfs(A, visited, {i, M - 1});
	}
	for (int i = 0; i < M; i++) {
		if (visited[0][i]) continue;
		if (A[0][i] == 'O') bfs(A, visited, {0, i});
	}
	for (int i = 0; i < M; i++) {
		if (visited[N - 1][i]) continue;
		if (A[N - 1][i] == 'O') bfs(A, visited, {N - 1, i});
	}

	for (int i = 0; i < N; i++ ) {
		for (int j = 0; j < M; j++) {
			if (A[i][j] == 'O' and !visited[i][j]) {
				A[i][j] = 'X';
			}
		}
	}
}

int main() {
	int N , M;
	cin >> N >> M;
	vector<vector<char>> A(N, vector<char>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}
	solve(A);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout <<  A[i][j] << " ";
		}
		cout << endl;
	}
}
