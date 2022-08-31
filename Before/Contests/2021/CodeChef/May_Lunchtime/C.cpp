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
const int mxn = 1e7 + 10;
// const int mxn = 20;
vector<bool> isPrime(mxn, 1);
vll primes, cnt_primes(mxn);
void sieve() {
	isPrime[0] = isPrime[1] = 0;
	ll cnt = 0;
	for (ll i = 2; i < mxn; i++) {
		if (isPrime[i]) {
			primes.push_back(i);
			for (ll j = i; j * i < mxn; j++) {
				isPrime[j * i] = false;
			}
			cnt++;
		}
		cnt_primes[i] = cnt;
	}
}
void groups(ll N) {
	// finding max primes less than N
	// find the biggest prime when multiplied by 2 is smaller than or equal to N
	ll left = 0, right = primes.size() - 1, mid = 0, ans = -1;
	while (left <= right) {
		mid = left + (right - left) / 2;
		if (primes[mid] * 2 <= N) {
			ans = primes[mid];
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	ll final_ans = 0;
	if (ans == -1) {
		final_ans = cnt_primes[N];
	}
	else {
		final_ans = 1 - cnt_primes[ans] + cnt_primes[N];
	}
	cout << final_ans << endl;
}
int main() {

	int tt = 1;
	cin >> tt;
	sieve();
	while (tt--) {

		ll N;
		cin >> N;
		groups(N);
		/**---------------***-------------**/

	}
}
