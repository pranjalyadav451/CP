#include <bits/stdc++.h>
#include <utility>
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
vector<pair<pll, int >> arr;
bool cmpx(const pair<pll, int> &a, const pair<pll, int> &b) {
	return a.first.first < b.first.first;
}
bool cmpy(const pair<pll, int> &a, const pair<pll, int> &b) {
	return a.first.second < b.first.second;
}
ll cheb(const pll &a, const pll &b) {
	return max(abs(a.first - b.first), abs(a.second - b.second));
}
void solve(int n) {
	sort(all(arr), cmpx);

	ll mxx = cheb(arr[0].first, arr[n - 1].first);
	ll mxxs = max(cheb(arr[0].first, arr[n - 2].first), cheb(arr[1].first, arr[n - 1].first));

	set<pair<pair<pll, int>, pair<pll, int>> >s;

	s.insert({arr[0], arr[n - 1]});
	s.insert({arr[0], arr[n - 2]});
	s.insert({arr[1], arr[n - 1]});

	vll values = { mxx, mxxs};

	sort(all(arr), cmpy);

	for (int i = 0; i < 2; i++) {
		if (i == 0) {
			if (s.count({arr[n - 1], arr[0]}) == 0 and s.count({arr[0], arr[n - 1]}) == 0 ) {
				values.push_back(cheb(arr[n - 1].first, arr[0].first));
			}
			if (s.count({arr[n - 2], arr[0]}) == 0 and s.count({arr[0], arr[n - 2]}) == 0 ) {
				values.push_back(cheb(arr[n - 2].first, arr[0].first));
			}
		}

		if (i == 1) {
			if (s.count({arr[n - 1], arr[1]}) == 0 and s.count({arr[1], arr[n - 1]}) == 0 ) {
				values.push_back(cheb(arr[n - 1].first, arr[1].first));
			}
		}
	}
	sort(all(values), greater<int>());
	cout << values[1] << endl;
}


int main() {
	int n;
	cin >> n;
	arr.resize(n);
	REP(i, 0, n - 1) {
		ll a , b;
		cin >> a >> b;
		arr[i] = {{a, b}, i};
	}
	solve(n);
}
