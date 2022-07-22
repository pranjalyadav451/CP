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

vector<string>sorted;
void brute(string str, int a, int b, int n) {
	if (a > n - 2 or b > 2)
		return;
	if (a + b >= n)	{
		sorted.push_back(str);
		// cout << str << endl;
		return;
	}
	brute(str + 'a', a + 1, b, n);
	brute(str + 'b', a, b + 1, n);
}
ll search_nearest(ll a) {
	ll left = 1, right = a, mid = 0, ans = -1;

	while (left <= right) {
		mid = left + (right - left) / 2;

		if (mid * (mid + 1) <= a) {
			ans = mid ;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return ans;
}

void solve(ll n, ll k) {

	ll a = (search_nearest(2 * k));

	string res (n, 'a');

	res[n - a] = 'b'; res[n - a - 1] = 'b';
	ll movesLeft = k - (a) * (a + 1) / 2;


	if (movesLeft == 0) {
		cout << res << endl;
		return;
	}
	else {
		res[n - a - 1] = 'a'; res[n - a - 2] = 'b';
		res[n - a] = 'a'; res[ n - (movesLeft)] = 'b';
	}
	cout << res << endl;

}

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		ll n, k;
		cin >> n >> k;
		solve(n, k);
	}
}
