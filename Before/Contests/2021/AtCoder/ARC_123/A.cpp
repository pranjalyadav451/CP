#include <bits/stdc++.h>
using namespace std;
int fastio() {
	ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0;
}
int __fastio = fastio();
template<typename A, typename B>    ostream &operator<<(ostream &os, const pair<A, B> &p);
template<typename A>                ostream &operator<<(ostream &os, const set<A> &m) {
	os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}";
}
template<typename A>                ostream &operator<<(ostream &os, const multiset<A> &m) {
	os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}";
}
template<typename A, typename B>    ostream &operator<<(ostream &os, const map<A, B> &m) {
	os << "{"; string sep = ""; for (auto e : m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}";
}
template<typename T>                ostream &operator<<(ostream &os, const vector<T> &v) {
	os << "["; string sep = ""; for (auto e : v) os << sep << e, sep = ", "; return os << "]";
}
template<typename T, size_t L>      ostream &operator<<(ostream &os, const array<T, L> &v) {
	os << "["; string sep = ""; for (int i = 0; i < L; ++i) os << sep << v[i], sep = ", "; return os << "]";
}
template<typename A, typename B>    ostream &operator<<(ostream &os, const pair<A, B> &p) {
	os << '(' << p.first << ", " << p.second << ')'; return os;
}

template<class Fun> class y_combinator_result {
Fun fun_; public: template<class T> explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {} template<class ...Args> decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
#define yc y_combinator
template<typename ...Args>

void logger(string vars, Args&&... values) {
	cout << "[" << "( " << vars << " )" << " :-> ( "; string delim = ""; (..., (cout << delim << values, delim = ", ")); cout << " )]" << endl;
}
typedef long long                           ll;
typedef pair<ll, ll>                        pll;
typedef vector<vector<ll>>                  vvl;
typedef vector<pll>                         vpl;
typedef pair<int, int>                      pii;
typedef long double                         ld;
typedef vector<ll>                          vll;

#define all(x)                              (x).begin(),(x).end()
#define REP(i, a, b)                        for (int i = (a); i <= (b); (i)++)
#define RREP(i, a, b)                       for (int i = (a); i >= (b); (i)--)
#define dbg(x)                              cout << #x << ": " << x << endl
#define dbgg(x, y)                          cout << #x << ": " << x << "  " << #y << ": " << y << endl
#define log_all(...)                        logger(#__VA_ARGS__, __VA_ARGS__)


void solve() {
	long long A, B, C;
	cin >> A >> B >> C;

	vll arr = { A , B , C };
	sort(all(arr));

	ll moves = 0;

	if (arr[2] == B) {
		moves = 2 * arr[2] - A - C;
		cout << moves << endl;
		return;
	}


	ll ileft = A - B, iright = B - C;


	if (arr[0] == B) {
		moves = abs(iright - ileft);
		if (moves % 2 == 1) moves = moves / 2 + 2;
		else moves /= 2;
		cout << moves << endl;
		return;
	}

	// when the middle element is in between

	if (arr[2] == A) {
		if (ileft > iright) {
			moves = ileft - iright;
			if (moves % 2 == 1) moves = moves / 2 + 2;
			else moves /= 2;
		}
		else {
			moves = iright - ileft;
		}
	}
	else {
		ileft = -ileft; iright = -iright;
		if (iright < ileft) {
			moves = ileft - iright;
		}
		else {
			moves = iright - ileft;
			if (moves % 2 == 1) moves = moves / 2 + 2;
			else moves = moves / 2;
		}
	}
	cout << moves << endl;
}

int main() {
	int tt = 1;
	while (tt--) {
		solve();
	}
}
