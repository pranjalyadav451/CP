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

bool cmp(const pii &a, const pii &b) {
	if (a.first < b.first) {
		return true;
	}
	else if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return false;
	}
}
void tell_crops(vector<pii> &waste, int posi, int posj, int n, int m) {
	int cnt = 0, len = waste.size();
	pii t;

	for (int i = 0; i < len; i++) {
		t = waste[i];
		if (t.first < posi) {
			cnt++;
		}
		else if (t.first == posi and t.second < posj) {
			cnt++;
		}
		else {
			break;
		}
	}
	// dbg(cnt);
	// dbg(t);
	// cout << endl;

	if (t.first == posi and t.second == posj) {
		cout << "Waste" << endl;
	}
	else {
		int filled = (posi - 1) * m + posj - cnt;
		int ans = filled % 3;
		if (ans == 0) {
			cout << "Grapes" << endl;
		}
		else if (ans == 1) {
			cout << "Carrots" << endl;
		}
		else {
			cout << "Kiwis" << endl;
		}
	}
}

int main() {
	int n, m, k, t;
	cin >> n >> m >> k >> t;
	vector<pii> waste(k);
	REP(i, 0, k - 1) {
		int a, b;
		cin >> a >> b;
		waste[i] = make_pair(a, b);
	}
	// cout << waste << endl;
	sort(ALL(waste), cmp);
	// cout << waste << endl;

	while (t--) {
		int i, j;
		cin >> i >> j;
		tell_crops(waste, i, j, n, m);
	}

}
