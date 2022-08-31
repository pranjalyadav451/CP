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


void solve(vector<string> &arr, int n) {

	bool valid_count = false, valid_win = false;
	int x_win = 0, o_win = 0, cntu = 0, diff_xo = 0;

	string x = "XXX", o = "OOO";
	string hz, vt, dia, rdia;

	for (int i = 0; i < n; i++) {
		if (arr[i] == x) x_win++;
		if (arr[i] == o) o_win++;

		vt.clear();
		for (int j = 0; j < n; j++) {
			vt.push_back(arr[j][i]);

			if (i == j)dia.push_back(arr[i][j]);
			if ((i == 1 and j == 1 ) or abs(j - i) == 2) {
				rdia.push_back(arr[i][j]);
			}

			if (arr[i][j] == 'X') diff_xo++;
			else if (arr[i][j] == 'O') diff_xo--;
			else cntu++;

		}
		if (vt == x) x_win++;
		if (vt == o) o_win++;
	}

	if (rdia == x) x_win++;
	if (rdia == o) o_win++;
	if (dia == x) x_win++;
	if (dia == o) o_win++;


	if (diff_xo == 1 or diff_xo == 0) valid_count = true;

	bool isdraw = false, iswon = false;

	// if (x_win + o_win <= 1) {
	// 	if (x_win and diff_xo == 1) {
	// 		iswon = true;
	// 		valid_win = true;
	// 	}
	// 	else if (o_win and diff_xo == 0) {
	// 		iswon = true;
	// 		valid_win = true;
	// 	}
	// 	else {
	// 		if (x_win == 0 and o_win == 0) {
	// 			iswon = false;
	// 			valid_win = true;
	// 		}
	// 		else {
	// 			iswon = false;
	// 			valid_win = false;
	// 		}
	// 	}

	// } else {
	// 	valid_win = false;
	// }
	if (x_win == 0 and o_win == 0 and (diff_xo == 0 or diff_xo == 1)) {
		valid_win = true;
		iswon = false;
	}

	if (x_win != 0) {
		if ((x_win == 1 or x_win == 2) and o_win == 0 and diff_xo == 1) {
			valid_win = true;
			iswon = true;
		}
		else {
			valid_win = false; iswon = false;
		}
	}
	else if (o_win != 0) {
		if (o_win == 1 and x_win == 0 and diff_xo == 0) {
			iswon = true;
			valid_win = true;
		}
	}



	if (iswon == false and cntu == 0) isdraw = true;

	// deb(valid_win);
	// deb(valid_count);
	// deb(diff_xo);
	// deb(cntu);
	// deb(isdraw);
	// deb(x_win);
	// deb(o_win);
	/**
	OXX
	XOO
	X_O
	*/


	if (valid_win == false or  valid_count == false) {
		cout << 3 << endl;
	}
	else if (valid_win and valid_count) {
		if (iswon or isdraw) cout << 1 << endl;
		else if (iswon == false and cntu > 0)
			cout << 2 << endl;
	}
}

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		vector<string> arr(3);
		for (auto & ele : arr) {
			cin >> ele;
		}
		solve(arr, 3);
	}
}
