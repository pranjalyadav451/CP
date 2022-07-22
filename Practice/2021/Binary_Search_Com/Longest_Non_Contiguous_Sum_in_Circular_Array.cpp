#include <bits/stdc++.h>
using namespace std;
int fastio() {
	ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0;
} int __fastio = fastio();
template<typename A, typename B>    ostream &operator<<(ostream &os, const pair<A, B> &p);
template<typename A>                ostream &operator<<(ostream &os, const set<A> &m) {
	os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}";
}
template<typename A>                ostream &operator<<(ostream &os, const multiset<A> &m) {
	os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}";
}
template<typename A, typename B>    ostream &operator<<(ostream &os, const map<A, B> &m) {
	os << "{"; string sep = ""; for (auto e : m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}";
}
template<typename T>                ostream &operator<<(ostream &os, const vector<T> &v) {
	os << "["; string sep = ""; for (auto e : v) os << sep << e, sep = ", "; return os << "]";
}
template<typename T, size_t L>      ostream &operator<<(ostream &os, const array<T, L> &v) {
	os << "["; string sep = ""; for (int i = 0; i < L; ++i) os << sep << v[i], sep = ", "; return os << "]";
}
template<typename A, typename B>    ostream &operator<<(ostream &os, const pair<A, B> &p) {
	os << '(' << p.first << ", " << p.second << ')'; return os;
}

template<class Fun> class y_combinator_result {
Fun fun_; public: template<class T> explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {} template<class ...Args> decltype(auto) operator()(Args &&...args) {
	return fun_(std::ref(*this), std::forward<Args>(args)...);
}
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
#define yc y_combinator
template<typename ...Args>

void logger(string vars, Args&&... values) {
	cout << "[" << "( " << vars << " )" << " :-> ( "; string delim = ""; (..., (cout << delim << values, delim = ", ")); cout << " )]" << endl;
}
typedef long long                           ll;
typedef pair<ll, ll>                        pll;
typedef vector<vector<ll>>                  vvl;
typedef vector<pll>                         vpl;
typedef pair<int, int>                      pii;
typedef long double                         ld;
typedef vector<int>                         vii;

#define all(x)                              (x).begin(),(x).end()
#define REP(i, a, b)                        for (int i = (a); i <= (b); (i)++)
#define RREP(i, a, b)                       for (int i = (a); i >= (b); (i)--)
#define dbg(x)                              cout << #x << ": " << x << endl
#define dbgg(x, y)                          cout << #x << ": " << x << "  " << #y << ": " << y << endl
#define log_all(...)                        logger(#__VA_ARGS__, __VA_ARGS__)

int util(vii &arr, int N) {

	vii dp(N + 1);
	dp[0] = 0, dp[1] = max(0, arr[0]);
	for (int i = 2; i <= N; i++) {
		dp[i] = max(dp[i - 2] + arr[i - 1], dp[i - 1]);
	}
	return dp[N];
}

int largest_non_contiguous_sum(vii &arr, int N) {

	cout << arr << endl;

	if (N == 0) return 0;
	if (N == 1) return max(0, arr[0]);


	vii one(N - 1), other(N - 1);

	for (int i = 0; i < N - 1; i++) {
		one[i] = arr[i];
	}
	for (int i = 1; i < N; i++) {
		other[i - 1] = arr[i];
	}

	int way1 = util(one, N - 1), way2 = util(other, N - 1), ans = max(way1, way2);
	return ans;
}

void solve() {
	int N;
	cin >> N;
	vii arr(N);
	for (auto &a : arr) {
		cin >> a;
	}
	cout << arr << endl;
	int ans = largest_non_contiguous_sum(arr, N);
	cout << ans << endl;
}

int main() {
	int tt = 1;
	// cin >> tt; // "UN-COMMENT THIS FOR TESTCASES"
	while (tt--) {
		solve();
	}
}
