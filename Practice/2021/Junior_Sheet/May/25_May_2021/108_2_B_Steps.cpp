#include <bits/stdc++.h>
#include <limits.h>
#include <stdint.h>
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

int main() {
	ll n , m;
	cin >> n >> m;

	/* Initial Position */
	ll xc , yc ;
	cin >> xc >> yc ;

	/* Vectors */
	int k;
	cin >> k;

	vector<pii> arr(k);

	for (int i = 0; i < k; i++) {
		int dx , dy;
		cin >> dx >> dy;
		arr[i] = {dx, dy};
	}

	/* Solution */

	ll steps = 0;
	for (int i = 0; i < k; i++) {
		ll dx = arr[i].first , dy = arr[i].second;

		if ((xc + dx > n) or (xc + dx < 0)) {
			continue;
		}
		if ((yc + dy > m) or (yc + dy < 0)) {
			continue;
		}

		ll x_steps = INT64_MAX, y_steps = INT64_MAX;
		// dbgg(xc, yc);

		// dbgg(dx, dy);

		if (dx < 0) {
			x_steps = (xc - 1) / abs(dx);
		}
		else if (dx > 0) {
			x_steps = (n - xc) / dx;
		}

		if (dy < 0 ) {
			y_steps = (yc - 1) / abs(dy);
		}
		else if (dy > 0) {
			y_steps = (m - yc) / dy;
		}

		ll moves = min(x_steps , y_steps);
		// dbgg(x_steps, y_steps);
		// dbg(steps);
		steps += moves;
		// dbg(steps);

		if (x_steps != INT64_MAX) {
			xc = xc + moves * ( dx );
		}
		if (y_steps != INT64_MAX) {
			yc = yc + moves * (dy);
		}
		// dbgg(xc, yc);
		// cout << endl;
	}
	cout << steps << endl;
}
