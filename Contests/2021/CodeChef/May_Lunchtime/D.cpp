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
typedef vector<vector<ll>> vvl; typedef vector<ll> vll; typedef vector<pll> vpl;
#define all(x) (x).begin(),(x).end()
#define REP(i, a, b) for (int i = (a); i <= (b); (i)++)
#define RREP(i, a, b) for (int i = (a); i >= (b); (i)--)
#define dbg(x) cout << #x << ": " << x << endl
#define dbgg(x, y) cout << #x << ": " << x << "  " << #y << ": " << y << endl

/** *** GLOBALS *** **/
const ll ninf = (-1e13);
vvl dp;
vll arr;
ll firstSub = 0, N, K;

ll mx_sum(ll pos, ll jumps = 0, ll iter = 1) {
	if (pos >= N) {
		return 0;
	}

	ll &ans = dp[pos][jumps];
	if (ans != ninf) return ans;

	if (jumps < K) {
		ll with_jump = mx_sum(pos + 1, jumps + 1, iter + 1),
		   without_jump = mx_sum(pos + 1, jumps, iter) + arr[pos];

		if (jumps == K - 1) {
			firstSub = max(firstSub, without_jump);
		}

		return ans = max(with_jump, without_jump);
	}
	else {
		return ans = mx_sum(pos + 1, jumps, iter);
	}
}


int main() {

	int tt = 1;
	cin >> tt;
	while (tt--) {

		// ll n, k;
		cin >> N >> K;
		arr.assign(N, 0);
		REP(i, 0, N - 1) {
			cin >> arr[i];
		}
		/**---------------***-------------**/
		dp.assign(N + 1, vll (K + 1, ninf));
		mx_sum(0);


		// for (auto ele : dp) {
		// 	cout << ele << endl;
		// }

		// remember to change -1 to ninf
		ll res = -2e15;
		ll posx , posy;
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= K; j++) {
				if (res < dp[i][j]) {
					posx = i;
					posy = j;
					res = dp[i][j];
				}
			}
		}

		while (posx <= N and posy <= K) {
			if (dp[posx][posy + 1] == dp[posx][posy]) {
				firstSub = dp[posx][posy];
				break;
			}
			posx++;
		}

		// cout << firstSub << endl;
		if (K == 1) cout << res << endl;
		else {
			ll sub = firstSub;
			cout << res + firstSub << endl;
		}
	}
}
