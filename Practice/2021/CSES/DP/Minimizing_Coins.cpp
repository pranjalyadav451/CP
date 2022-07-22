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
typedef vector<vector<ll>> vvl; typedef vector<ll> vll; typedef vector<pll> vpl;
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
const ll inf = 1e12;
const int mxn = 1e6 + 10;
ll dp[2][mxn];

void reset(int n) {
	for (int i = 1; i <= n; i++) {
		dp[0][i] = dp[1][i];
		dp[1][i] = inf;
	}
}

void print(int sum) {
	for (int i = 0; i <= sum; i++) {
		cout << (dp[0][i] == inf ? -1 : dp[0][i]) << " ";
	}
	cout << endl;
	for (int i = 0; i <= sum; i++) {
		cout << (dp[1][i] == inf ? -1 : dp[1][i]) << " ";
	}
	cout << endl;
}

int main() {
	ll n, sum;
	cin >> n >> sum;
	vll arr(n);
	for (ll &a : arr) cin >> a;

	// initialization
	dp[0][0] = 0, dp[1][0] = 0;
	for (int i = 1; i <= sum; i++) {
		dp[0][i] = inf;
		dp[1][i] = inf;
	}

	// filling the dp array
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (j >= arr[i - 1]) {
				dp[1][j] = min(1 + dp[1][j - arr[i - 1]], dp[0][j]);
			}
			else {
				dp[1][j] = dp[0][j];
			}
		}
		reset(sum);
	}

	ll res = dp[0][sum];
	cout << (res == inf ? -1 : res) << endl;
}
