#include <bits/stdc++.h>
#include <cctype>
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

bool is_reachable(int posx, int posy, int reachx, int reachy, int x) {
	posx = posx - reachx;
	posy = posy - reachy;

	ll dis = posx * posx + posy * posy;
	if (dis <= x * x) {
		return true;
	}
	return false;
}

void solve(vector<string > &arr, int n, int m, int x, int q, string text) {
	set<char> s;
	// to store the possible reachable characters with one hand.
	// How to incorporate Euclidean Distance in the calculation.
	vector<pii> key_shift;

	REP(i, 0, n - 1) {
		REP(j, 0, m - 1) {
			if (arr[i][j] != 'S') {
				s.insert(arr[i][j]);
			}
			else {
				key_shift.push_back({i, j});
			}
		}
	}

	REP(i, 0, n - 1) {
		REP(j, 0, m - 1) {
			if (arr[i][j] != 'S') {
				for (auto ele : key_shift) {
					if (is_reachable(i, j, ele.first, ele.second, x)) {
						s.insert(toupper(arr[i][j]));
					}
				}
			}
		}
	}

	bool is_shift  = key_shift.size();
	int cnt = 0;

	for (int i = 0; i < text.size(); i++) {
		if (s.find(text[i]) != s.end()) {
			continue;
		}
		else {
			if (islower(text[i])) {
				cout << - 1 << endl;
				return;
			}

			char ch = tolower(text[i]);
			if (is_shift and s.find(ch) != s.end()) {
				cnt++;
			}
			else {
				cout << - 1 << endl;
				return;
			}
		}
	}
	cout << cnt << endl;
}

int main() {
	int n, m, x;
	cin >> n >> m >> x;
	vector<string> arr(n);
	REP(i, 0, n - 1) {
		cin >> arr[i];
	}
	int q;
	cin >> q;
	string text ;
	cin >> text;
	solve(arr, n, m, x, q, text);
}
