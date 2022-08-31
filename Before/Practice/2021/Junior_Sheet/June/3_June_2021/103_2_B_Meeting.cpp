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
#define log_all(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
	cout << "[" << "( " << vars << " )" << " :-> ( ";
	string delim = ""; (..., (cout << delim << values, delim = ", ")); cout << " )]" << endl;
}

/** *** GLOBALS *** **/

struct Heater {
	ll x, y, r;
};

// int grid[2010][2010] = {};
// int ORIGIN = 1005;
set<pii> visited;

bool can(int x, int y, vector<Heater> &arr) {
	if (visited.count({x, y}) == 0) visited.insert({x, y});
	else return 1;

	int n = arr.size();
	for (int i = 0; i < n; i++) {
		if ((arr[i].x - x) * (arr[i].x - x) + (arr[i].y - y) * (arr[i].y - y) <= arr[i].r * arr[i].r)
			return 1;
	}
	return 0;
}


int main() {
	int xa, ya , xb , yb;
	cin >> xa >> ya >> xb >> yb;
	int n;
	cin >> n;
	vector<Heater> arr(n);
	REP(i, 0, n - 1) {
		cin >> arr[i].x >> arr[i].y >> arr[i].r ;
	}
	int mnx = min(xa, xb), mxx = max(xa, xb), mny = min(ya, yb), mxy = max(ya, yb);

	int cnt = 0;
	for (int i = mnx; i <= mxx; i++) {
		if (can(i, mny, arr) == 0) cnt++;
		if (can(i, mxy, arr) == 0) cnt++;
	}
	for (int i = mny; i <= mxy; i++) {
		if (can(mnx, i, arr) == 0) cnt++;
		if (can(mxx, i, arr) == 0) cnt++;
	}
	cout << cnt << endl;
}
