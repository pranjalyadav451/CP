#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } int __fastio = fastio();
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p);
template<typename A> ostream& operator<<(ostream &os, const set<A> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A> ostream& operator<<(ostream &os, const multiset<A> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const map<A, B> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}"; }
template<typename T>ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; string sep = ""; for (auto e : v) os << sep << e, sep = ", "; return os << "]"; }
template<typename T, size_t L>ostream& operator<<(ostream& os, const array<T, L>& v) { os << "["; string sep = ""; for (int i = 0; i < L; ++i) os << sep << v[i], sep = ", "; return os << "]"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

template<class Fun> class y_combinator_result { Fun fun_; public: template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {} template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); } };
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
#define yc y_combinator

typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef long double ld;
typedef vector<vector<ll>> vvl; typedef vector<ll> vll; typedef vector<pll> vpl;
#define fe first
#define se second
#define all(x) (x).begin(),(x).end()
#define REP(i, a, b) for (int i = (a); i <= (b); (i)++)
#define RREP(i, a, b) for (int i = (a); i >= (b); (i)--)
#define dbg(x) cout << #x << ": " << x << endl
#define dbgg(x, y) cout << #x << ": " << x << "  " << #y << ": " << y << endl

/** *** GLOBALS *** **/
const ll inf = 1e18;
vpl arr;
int N;

/**
 * There could be three cases :
 * tree could keep standing
 * could fall left
 * could fall right
 * * WE have to find the maximum of the three choices.
 * **/

const int mxn = 1e5 + 10;
ll dp[mxn][2];

ll cutting(int i = 1, int right = 0) {
	if (i > N) return 0;
	ll &ans = dp[i][right];
	if (ans != -1) return ans;
	if (!right) {
		ans = cutting(i + 1, 0);
		if (arr[i].fe - arr[i].se > arr[i - 1].fe) ans = max(ans, 1 + cutting(i + 1, 0));
		if (arr[i].fe + arr[i].se < arr[i + 1].fe) ans = max(ans, 1 + cutting(i + 1, 1));
	}
	else {
		ans = cutting(i + 1, 0);
		if (arr[i].fe - arr[i].se > arr[i - 1].fe + arr[i - 1].se) ans = max(ans, 1 + cutting(i + 1, 0));
		if (arr[i].fe + arr[i].se < arr[i + 1].fe) ans = max(ans , 1 + cutting(i + 1, 1));
	}
	return ans;
}

int main() {
	cin >> N;
	arr.assign(N + 2, make_pair(0, 0));
	arr[0] = { -inf, 0}; arr[N + 1] = { inf, 0};
	REP(i, 1, N) {
		cin >> arr[i].first >> arr[i].second;
	}
	memset(dp, -1, sizeof(dp));
	ll ans = cutting();
	cout << ans << endl;
}
