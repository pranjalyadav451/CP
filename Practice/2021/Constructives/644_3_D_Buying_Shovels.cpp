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
#ifdef LOCAL
#define pp(...) cerr << "\t[" << #__VA_ARGS__ << "]:\t", dbg_out(__VA_ARGS__)
#define ppp(x) cerr << x << "\n"
#else
#define pp(...)
#define ppp(...)
#endif
template<class Fun> class y_combinator_result { Fun fun_; public: template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {} template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); } };
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
#define yc y_combinator

typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef long double ld;
#define all(x) (x).begin(),(x).end()
#define rep(i, a, b) for (int i = (a); i <= (b); (i)++)
#define rrep(i, a, b) for (int i = (a); i >= (b); (i)--)
#define deb(x) cout << #x << ": " << x << endl
#define deb2(x, y) cout << #x << ": " << x << "  " << #y << ": " << y << endl

ll biggest_factor(ll n, ll k) {
	ll ans = -1;
	for (ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			if (i <= k)
				ans = max(ans, i);
			if (n / i <= k)
				ans = max(ans, n / i);
		}
	}
	return ans;
}

void run_case(ll n, ll k ) {
	if (k >= n) {
		cout << 1 << endl;
		return;
	}

	ll ans  = biggest_factor(n, k);
	if (ans == -1)
		cout << n << endl;
	else
		cout << n / ans << endl;
}
/**
 * What exactly is the question asking ?
 * What I understand now -:
 	- If the number of shovels is less than the types of packages the shopkeeper
 	then we can just buy one package of size n.
 	- Else find the package with the greatest size that which divides n.
*/

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		ll n, k;
		cin >> n >> k;
		run_case(n, k);
	}
}


