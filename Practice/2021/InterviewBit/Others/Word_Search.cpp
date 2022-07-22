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
	{0, 0}, { -1, 0}, {1, 0}, {0, 1}, {0, -1}
};
bool is_valid(int x, int y, int N , int M) {
	return x >= 0 and x < N and y >= 0 and y < M;
}
bool g_ans = false;

void dfs(vector<string> &A, string &target, pair<int, int> now, pair<int, int> from, string &current, vector<vector<bool>>&visited) {
	if (current == target) {
		g_ans = true;
		return;
	}
	if (current.size() >= target.size()) return;

	// if (visited[now.first][now.second] and now != from) return;
	visited[now.first][now.second] = true;


	int N = A.size(), M = A[0].size();

	for (auto move : moves) {
		int x = now.first + move.first , y = now.second + move.second;
		if (is_valid(x, y, N, M) and A[x][y] == target[current.size()]) {
			current.push_back(A[x][y]);
			dfs(A, target, {x, y}, now, current, visited);
			current.pop_back();
		}
	}
}



int exist(vector<string> &A, string B) {
	int N = A.size(), M = A[0].size();
	g_ans = 0;
	string start;
	vector < vector<bool>> visited(N, vector<bool> (M, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j] == B[0]) {
				visited.assign(N, vector<bool>(M, 0));
				start = "";
				start.push_back(A[i][j]);
				dfs(A, B, {i, j}, {i, j}, start, visited);
			}
		}
	}
	return g_ans;
}

int main() {
	int N ;
	cin >> N;
	vector<string> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		cout << A[i] << endl;
	}
	string B;
	cin >> B;
	cout << exist(A, B) << endl;

}
