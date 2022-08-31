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

void run_case(ll n) {

	ll a = 1 , b = 1, c = 1;
	bool isPrime = true;

	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			a = min(i, n / i);
			isPrime = false;
			break;
		}
	}
	if (isPrime) {
		cout << "NO" << endl;
		return;
	}

	n = n / a;
	isPrime = true;
	for (ll i = a + 1; i * i <= n; i++) {
		if (n % i == 0) {
			b = min(i, n / i);
			isPrime = false;
			break;
		}
	}

	c = n / b;
	// cout << a << " " << b << " " << c << endl;

	if (isPrime) {
		cout << "NO" << endl;
	}
	else {
		if (c != a and c != b) {
			cout << "YES" << endl;
			cout << a << " " << b << " " << c << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

}


int main() {
	int tt = 1;
	cin >> tt;
	while (tt--) {
		ll n;
		cin >> n;
		run_case(n);
	}
}
/**
* Good Question :
 - If any number has three distinct factors a , b ,c
 - Then we can safely assume that a < b < c (assigning smallest factor to 'a' and largest to 'c')
 - Then we can try minimising 'a' and 'b' and maximising 'c'. (Greedy Approach)
*/

/*
* Editorial :
Suppose a<b<c. Let's try to minimize a and maximize c.
Let a be the minimum divisor of n greater than 1.
Then let b be the minimum divisor of na that isn't equal a and 1.
If n/(ab) isn't equal a, b and 1 then the answer is "YES", otherwise the answer is "NO".
Time complexity: O(√n) per query.
*/