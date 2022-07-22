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

bool do_intersect(pii &a, pii &b) {
	pii mn = min(a, b), mx = max(a, b);
	if (mn.first + (mn.second - mn.first) >= mx.first)
		return true;
	return false;
}

int main() {
	int p, q, l, r;
	cin >> p >> q >> l >> r;
	vector<pii> lz(p), lx(q);
	REP(i, 0, p - 1) {
		int a, b;
		cin >> a >> b;
		lz[i] = make_pair(a, b);
	}
	REP(i, 0, q - 1) {
		int c, d;
		cin >> c >> d;
		lx[i] = {c, d};
	}

	/** * Solution  */

	bool any = false;
	int cnt = 0;
	REP(i, 0, q - 1) {
		lx[i] = {lx[i].first + l, lx[i].second + l};
	}

	while (l <= r) {
		any = false;
		REP(i, 0, q - 1) {
			REP(j, 0, p - 1) {
				if (do_intersect(lx[i], lz[j])) {
					any = true;
					break;
				}
			}
			lx[i] = {lx[i].first + 1, lx[i].second + 1};
		}
		if (any) cnt++;
		l++;
	}

	cout << cnt << endl;

}
