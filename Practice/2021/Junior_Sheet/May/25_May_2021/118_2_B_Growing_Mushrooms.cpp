#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(2); cin.tie(nullptr); return 0; } int __fastio = fastio();
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
int t1, t2, k;
bool cmp(const pair<int, pii>& a, const pair<int, pii>& b) {
	ld sf = (ld)a.second.first, ss = (ld)a.second.second;

	ld gr1 = (ld(100 - k) / (ld) 100) * sf * (ld)t1 + (ld)t2 * ss,
	   gr2 = (ld(100 - k) / (ld) 100) * ss * (ld)t1 + (ld)t2 * sf;
	gr1 = max(gr1, gr2);

	sf = (ld)b.second.first, ss = (ld)b.second.second;
	ld grr1 = (ld(100 - k) / (ld) 100) * sf * (ld)t1 + (ld)t2 * ss,
	   grr2 = (ld(100 - k) / (ld) 100) * ss * (ld)t1 + (ld)t2 * sf;
	grr1 = max(grr1, grr2);

	if (gr1 == grr1) {
		return a.first < b.first;
	}
	else {
		return gr1 > grr1;
	}
}

int main() {
	int n;
	cin >> n >> t1 >> t2 >> k;

	vector <pair<int, pii>> arr(n);
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		arr[i] = {i + 1, {u, v}};
	}

	/**************************** Solution ************************************/
	// dbgg(t1, t2);
	sort(ALL(arr), cmp);
	for (int i = 0; i < n; i++) {
		auto a = arr[i];
		ld sf = (ld)a.second.first, ss = (ld)a.second.second;

		// dbgg(sf, ss);

		ld gr1 = (ld(100 - k) / (ld) 100) * sf * (ld)t1 + (ld)t2 * ss,
		   gr2 = (ld(100 - k) / (ld) 100) * ss * (ld)t1 + (ld)t2 * sf;
		gr1 = max(gr1, gr2);
		cout << a.first << " " << gr1 << endl;
	}

}
