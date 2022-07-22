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

vector<vector<string>> solve(vector<vector<string>>& matrix) {
	int N = matrix.size(), M = matrix[0].size();
	vector<int> stops_at;

	for (int i = 0; i < N; i++) {
		stops_at.assign(M + 1, M);

		for (int j = M - 1; j >= 0; j--) {
			if (matrix[i][j] == "*") {
				stops_at[j] = j;
			}
			else if (matrix[i][j] == "#") {
				stops_at[j] = stops_at[j + 1] - 1;
			}
			else {
				stops_at[j] = stops_at[j + 1];
			}
		}
		for (int j = M - 1; j >= 0; j--) {
			if (matrix[i][j] == "#") {
				matrix[i][j] = ".";
				matrix[i][stops_at[j]] = "#";
			}
		}
	}
	vector<vector<string>> res(M, vector<string>(N));
	for (int j = M - 1; j >= 0; j--) {
		for (int i = N - 1; i >= 0; i--) {
			res[j][N - 1 - i] = matrix[i][j];
		}
	}
	return res;
}

int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<string>> matrix(N, vector<string>(M, "_"));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> matrix[i][j];
		}
	}

	vector<vector<string>> res = solve(matrix);
	for (auto vec : res) {
		for (auto str : vec) {
			cout << str << " ";
		}
		cout << endl;
	}
}
