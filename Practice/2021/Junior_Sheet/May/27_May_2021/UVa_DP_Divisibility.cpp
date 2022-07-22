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
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

template<class Fun> class y_combinator_result { Fun fun_; public: template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {} template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); } };
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
#define yc y_combinator

typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef long double ld;
#define ALL(x) (x).begin(),(x).end()
#define REP(i, a, b) for (int i = (a); i <= (b); (i)++)
#define RREP(i, a, b) for (int i = (a); i >= (b); (i)--)
#define dbg(x) cout << #x << ": " << x << endl
#define dbgg(x, y) cout << #x << ": " << x << "  " << #y << ": " << y << endl

/** *** GLOBALS *** **/
const int inf = 1e9 + 7;
int dp[10010][110];

bool is_divisible_wrong(vector<int> &arr, int N, int K, int sum ) {
	if (N == 0) {
		return (sum % K == 0);
	}
	if (dp[N][sum] != -1) {
		return dp[N][sum];
	}
	if (sum % K == 0) {
		return dp[N][sum] = true;
	}
	bool ans = is_divisible_wrong(arr, N - 1, K, (sum % K + K) % K)
	           || is_divisible_wrong(arr, N - 1, K, ((sum % K - arr[N - 1] % K) + K ) % K);
	return dp[N][sum] = ans;
}
/*
 Find out why the wrong solution dosen't work.
*/


bool is_divisible_correct(vector<int> &arr, int N, int K, int sum ) {
	if (N == 0) {
		return (sum % K == 0);
	}
	if (dp[N][sum] != -1) {
		return dp[N][sum];
	}
	bool ans = is_divisible_correct(arr, N - 1, K, (sum % K + arr[N - 1] % K) % K)
	           || is_divisible_correct(arr, N - 1, K, ((sum % K - arr[N - 1] % K) + K ) % K);
	return dp[N][sum] = ans;
}



/** *** FUNCTIONS *** **/
void solve(vector<int> &arr, int N, int K, int sum) {
	memset(dp, -1, sizeof(dp));
	bool ans = is_divisible_correct(arr, N, K, 0);

	/* * we can minus from the sum or keep it same. */

	if (ans) {
		cout << "Divisible" << endl;
	}
	else {
		cout << "Not divisible" << endl;
	}
}


int main() {
	/** *** INPUT *** **/
	int M;
	cin >> M;
	while (M--) {
		int N, K;
		cin >> N >> K ;
		vector<int> arr(N);
		ll sum = 0;
		REP(i, 0, N - 1) {
			cin >> arr[i];
			sum += abs(arr[i]);
		}
		solve(arr, N, K, sum);
	}
}
