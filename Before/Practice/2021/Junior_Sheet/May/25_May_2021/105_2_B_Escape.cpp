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

/************************** GLOBALS **************************/



/************************** FUNCTIONS **************************/

ld overtook_t(int diff , int vp, int vd) {
	ld ans = (ld) diff / (ld)(vd - vp);
	return ans;
}

int main() {
	/************************** INPUT **************************/
	int vp, vd, t, f, c;
	cin >> vp >> vd >> t >> f >> c;

	/************************** SOLUTION **************************/
	if (vp >= vd and t > 0) {
		cout << 0 << endl;
		return 0;
	}

	ld dist = t * vp, bij = 0;
	ld overtook = overtook_t(dist, vp, vd);
	dist += overtook * (ld) vp;

	/* * Only one change was needed
	   * I needed to find the time more accurately
	   * Wasn't doing so initiallly due to the fear of precision loss while dealing
	   - with floating point numbers.
	   * But, eventually I was having more precision loss due to the use of integers to find time.
	*/

	while (dist < c) {
		bij++;
		dist +=	(overtook  + (ld)f) * (ld)vp;
		overtook = overtook_t(dist, vp, vd);
		dist += (ld)vp * overtook;
	}
	cout << (int)bij << endl;
}
