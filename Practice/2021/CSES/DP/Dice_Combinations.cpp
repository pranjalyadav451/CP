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

const int mod = 1e9 + 7;
const int mxn = 1e6 + 10;
ll dp[mxn];

int main() {
	int n;
	cin >> n;

	dp[0] = 0, dp[1] = 1, dp[2] = 2, dp[3] = 4, dp[4] = 8, dp[5] = 16, dp[6] = 32;
	for (int i = 7; i <= n; i++) {
		dp[i] = ((dp[i - 1] % mod + dp[i - 2] % mod ) % mod + (dp[i - 3] % mod + dp[i - 4] % mod) % mod + (dp[i - 5] % mod + dp[i - 6] % mod) % mod) % mod;
	}
	cout << dp[n] << endl;
}
