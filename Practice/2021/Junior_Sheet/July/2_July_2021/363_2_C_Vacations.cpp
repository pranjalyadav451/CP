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

int N ;
vll arr;
const int mxn = 110;
int dp[mxn][2][2];

int rec(int i = 0, int did_contest = 0, int did_gym = 0) {
	if (i == N) return 0;


	int &ans = dp[i][did_contest][did_gym];
	if (ans != -1) return ans;


	if (arr[i] == 0) ans =  1 + rec(i + 1, 0, 0);
	if (arr[i] == 1) {
		if (did_contest == 0)
			ans =  min(1 + rec(i + 1, 0 , 0 ) , rec(i + 1, 1, 0));
		else
			ans =  1 + rec(i + 1, 0, 0);
	}
	if (arr[i] == 2) {
		if (did_gym == 0)
			ans =  min(1 + rec(i + 1, 0 , 0), rec(i + 1, 0 , 1));
		else
			ans =  1 + rec(i + 1, 0 , 0);
	}
	if (arr[i] == 3) {
		if (did_gym == 0 and did_contest == 0) ans =  min({1 + rec(i + 1, 0 , 0), rec(i + 1, 0 , 1) , rec(i + 1, 1, 0), rec(i + 1, 1, 1)});
		else {
			if (did_contest == 0) ans =  min(rec(i + 1, 1, 0), 1 + rec(i + 1, 0 , 0));
			else if (did_gym == 0) ans =  min(rec(i + 1, 0 , 1) , 1 +  rec(i + 1, 0, 0));
			else ans =  1 + rec(i + 1 , 0 , 0);
		}
	}
	return ans;
}

void solve() {
	cin >> N;
	arr.assign(N, 0);
	REP(i, 0, N - 1) {
		cin >> arr[i];
	}
	memset(dp, -1, sizeof(dp));
	int ans = rec();
	cout << ans << endl;
	// Easy - Peasy Lemon Squeezy
}

int main() {
	int tt = 1;
	// cin >> tt; // "UN-COMMENT THIS FOR TESTCASES"
	while (tt--) {
		solve();
	}
}
