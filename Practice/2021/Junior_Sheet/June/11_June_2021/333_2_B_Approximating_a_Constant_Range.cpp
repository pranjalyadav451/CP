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
// TODO: do this problem using set or map as suggested in the editorial

void solve() {
	int N ;
	cin >> N;
	vll arr(N);
	for (auto &a : arr) {
		cin >> a;
	}
	// cout << arr << endl;
	ll last_mn_idx = 0, last_mx_idx = 0 , current_mn = arr[0], current_mx = arr[0];
	ll len = 1, mx_len = 1;
	for (int i = 1; i < N; i++) {
		mx_len = max(mx_len, len);
		if (abs(current_mx - arr[i]) <= 1 and abs(arr[i] - current_mn) <= 1) {
			len++;
			last_mn_idx = current_mn >= arr[i] ? i : last_mn_idx;
			last_mx_idx = current_mx <= arr[i] ? i : last_mx_idx;
			current_mn = min(current_mn, arr[i]);
			current_mx = max(current_mx , arr[i]);
		}
		else {
			ll dist_mx = abs(current_mx - arr[i]), dist_mn = abs(current_mn - arr[i]);
			if (dist_mn <= 1) {
				len = i - last_mx_idx;
				last_mx_idx = last_mn_idx;
				last_mn_idx = i;
				current_mx = max(current_mn , arr[i]), current_mn = min(arr[i], current_mn);
			}
			else if (dist_mx <= 1) {
				len = i - last_mn_idx;
				last_mn_idx = last_mx_idx;
				last_mx_idx = i;
				current_mn = min(arr[i], current_mx), current_mx = max(current_mx, arr[i]);
			}
			else {
				len = 1;
				current_mx = arr[i], current_mn = arr[i];
			}
		}
	}
	mx_len = max(mx_len, len);
	cout << mx_len << endl;
}

int main() {
	int tt = 1;
	// cin >> tt; // "UN-COMMENT THIS FOR TESTCASES"
	while (tt--) {
		solve();
	}
}
