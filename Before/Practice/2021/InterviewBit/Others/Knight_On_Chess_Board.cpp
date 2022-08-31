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
typedef long double                         ld;
typedef vector<ll>                          vll;

#define all(x)                              (x).begin(),(x).end()
#define REP(i, a, b)                        for (int i = (a); i <= (b); (i)++)
#define RREP(i, a, b)                       for (int i = (a); i >= (b); (i)--)
#define dbg(x)                              cout << #x << ": " << x << endl
#define dbgg(x, y)                          cout << #x << ": " << x << "  " << #y << ": " << y << endl


typedef pair<int, int>  pii;

const vector<pii > jumps = {
	{ -1, -2}, {1, 2}, { -1, 2}, {1, -2},
	{ -2, -1}, {2, 1}, { -2, 1}, {2, -1}
};
const int INF = 1e9;

bool is_valid(pii current, pii  board) {
	return current.first >= 0 and current.first < board.first and current.second >= 0 and current.second < board.second;
}

int moves(pii  current, pii  end, pii  board, vector<vector<bool>> &visited, vector<vector<int>> &dist) {

	queue<pii> nodes;
	nodes.push(end);
	visited[end.first][end.second] = true;

	while (nodes.size()) {
		pii on = nodes.front();
		nodes.pop();

		for (auto J : jumps) {
			int x = J.first + on.first , y = J.second + on.second;
			if (is_valid({x, y}, board) and visited[x][y] == false) {
				visited[x][y] = true;
				dist[x][y] = dist[on.first][on.second] + 1;
				nodes.push({x, y});
			}
		}
	}

	return dist[current.first][current.second];
}
int knight(int A, int B, int C, int D, int E, int F) {
	vector<vector<int>>dist(A, vector<int>(B, INF));
	dist[E - 1][F - 1] = 0;
	vector<vector<bool>>visited(A, vector<bool>(B, 0));

	int ans = moves({C - 1, D - 1}, {E - 1, F - 1}, {A, B}, visited, dist);
	return ans;
}


int main() {
	int A , B , C , D , E , F;
	cin >> A >> B >> C >> D >> E >> F;
	int ans = knight(A, B, C, D, E, F);
	cout << ans << endl;
}
