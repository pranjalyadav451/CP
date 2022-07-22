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


template<class Fun> class y_combinator_result { Fun fun_; public: template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {} template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); } };
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
#define yc y_combinator

typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef long double ld;
typedef vector<vector<ll>> vvl; typedef vector<ll> vll; typedef vector<pll> vpl; typedef vector<bool> vbl;
#define all(x) (x).begin(),(x).end()
#define REP(i, a, b) for (int i = (a); i <= (b); (i)++)
#define RREP(i, a, b) for (int i = (a); i >= (b); (i)--)
#define dbg(x) cout << #x << ": " << x << endl
#define dbgg(x, y) cout << #x << ": " << x << "  " << #y << ": " << y << endl
#define log_all(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
	cout << "[" << "( " << vars << " )" << " :-> ( ";
	string delim = ""; (..., (cout << delim << values, delim = ", ")); cout << " )]" << endl;
}

/** *** GLOBALS *** **/
ll total_paths = 0;
bool is_it_safe(int row, int col, int n, vector<vbl> &visited) {
	return row >= 0 and col >= 0 and row < n and col < n and visited[row][col] == false;
}

void helper(int i, int j, int n, vvl &grid, vector<vbl> &visited) {
	if (i == n - 1 and j == n - 1) {
		total_paths++;
		return;
	}
	if (not is_it_safe(i, j, n, visited)) {
		return;
	}
	visited[i][j] = true;
	if (i + 1 < n and grid[i + 1][j] == 0) {
		helper(i + 1, j, n, grid, visited);
	}
	if (j + 1 < n and grid[i][j + 1] == 0) {
		helper(i, j + 1, n, grid, visited);
	}
	if (i - 1 >= 0 and grid[i - 1][j] == 0) {
		helper(i - 1, j, n, grid, visited);
	}
	if (j - 1 >= 0 and grid[i][j - 1] == 0 ) {
		helper(i , j -  1, n, grid, visited);
	}
	visited[i][j] = false;
}

void count_rat_maze_paths(vvl& arr, int N) {
	vector<vbl> visited(N, vbl(N, false));
	helper(0, 0, N, arr, visited);
}


int main() {
	int n;
	cin >> n;
	vvl arr(n, vll(n, 0));
	REP(i, 0, n - 1) {
		REP(j, 0, n - 1) {
			cin >> arr[i][j];
		}
	}
	count_rat_maze_paths(arr, n);
	cout << total_paths << endl;
}