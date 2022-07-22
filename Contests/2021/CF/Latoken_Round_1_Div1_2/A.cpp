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

template<class Fun> class y_combinator_result { Fun fun_; public: template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {} template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); } };
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
#define yc y_combinator
template<typename ...Args>

void logger(string vars, Args&&... values) {cout << "[" << "( " << vars << " )" << " :-> ( "; string delim = ""; (..., (cout << delim << values, delim = ", ")); cout << " )]" << endl;}
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
#define log_all(...)                        logger(#__VA_ARGS__, __VA_ARGS__)

vector<string> arr;

int color(int i, int j) {
	int color = (arr[i][j] == 'R' ? 1 : (arr[i][j] == 'W' ? 0 : -1));
	return color;
}

bool is_safe(int i , int j, int n, int m) {
	int current = color(i, j);
	bool left = (j -  1 < 0) , right = (j + 1 >= m) , top = (i - 1 < 0) , bottom = (i + 1 >= n);

	if (j - 1 >= 0 and color(i, j - 1) != current) {
		left = true;
		arr[i][j - 1] = (current == 1 ? 'W' : 'R');
	}
	if (j + 1 < m and color(i, j + 1) != current) {
		right = true;
		arr[i][j + 1] = (current == 1 ? 'W' : 'R');
	}
	if (i - 1 >= 0 and color(i - 1, j) != current) {
		top = true;
		arr[i - 1][j] = (current == 1 ? 'W' : 'R');
	}
	if (i + 1 < n and color(i + 1, j) != current) {
		bottom = true;
		arr[i + 1][j] = (current == 1 ? 'W' : 'R');
	}

	return left and right and top and bottom;
}


void solve() {
	int N, M;
	cin >> N >> M;
	arr.assign(N, string(M, '_'));

	bool all_dots = true;
	bool is_dot = false;

	for (auto &a : arr) {
		for (auto &b : a) {
			cin >> b;
			if (b != '.') all_dots = false;
			if (b == '.') is_dot = true;
		}
	}
	if (all_dots) {
		arr[0][0] = 'R';
	}

	do {
		is_dot = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (color(i, j) != -1) {
					if (is_safe(i, j, N, M))
						continue;
					else {
						cout << "NO" << endl;
						return;
					}
				}
				else {
					is_dot = true;
				}
			}
		}
	} while (is_dot);

	cout << "YES" << endl;
	for (auto a : arr) {
		cout << a << endl;
	}
}

int main() {
	int tt = 1;
	cin >> tt; // "UN-COMMENT THIS FOR TESTCASES"
	while (tt--) {
		solve();
	}
}
