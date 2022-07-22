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

void solve(vector<string> &s) {
	char one , two , three;
	one = s[0][0];
	two = s[0][2];
	if (s[0][1] == '<') {
		swap(one, two);
	}
	bool is_one_three = false, is_two_three = false;

	if (s[1][0] == two) {
		three = s[1][2];
		if (s[1][1] == '>') {
			is_two_three = true;
		}
	}
	else if (s[1][0] == one) {
		three = s[1][2];
		if (s[1][1] == '>') {
			is_one_three = true;
		}
	}
	else if (s[1][0] != one and s[1][0] != two) {
		three  = s[1][0];
		if (s[1][2] == one and s[1][1] == '<') {
			is_one_three = true;
		}
		else if (s[1][2] == two and s[1][1] == '<') {
			is_two_three = true;
		}
	}


	if (s[2][0] == two) {
		if (s[2][1] == '>') {
			is_two_three = true;
		}
	}
	else if (s[2][0] == one) {
		if (s[2][1] == '>') {
			is_one_three = true;
		}
	}
	else if (s[2][0] != one and s[2][0] != two) {
		if (s[2][2] == one and s[2][1] == '<') {
			is_one_three = true;
		}
		else if (s[2][2] == two and s[2][1] == '<') {
			is_two_three = true;
		}
	}



	// deb(one);
	// deb(two);
	// deb(three);
	// deb(is_one_three);
	// deb(is_two_three);

	if (is_one_three == is_two_three) {
		if (is_one_three == true) {
			cout << three << two << one << endl;
			return;
		}
		else {
			cout << two << one << three << endl;
		}
	}
	else if (is_two_three == false and is_one_three == true) {
		cout << two << three << one << endl;
	}
	else {
		cout << "Impossible" << endl;
	}
}

int main() {
	int n  = 3;
	vector<string> s(3);
	for (int i = 0; i < 3; i++) {
		cin >> s[i];
	}
	solve(s);
}
