#include <bits/stdc++.h>
#include <string>
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
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i <= (b); (i)++)
#define rrep(i, a, b) for (int i = (a); i >= (b); (i)--)
#define deb(x) cout << #x << ": " << x << endl
#define deb2(x, y) cout << #x << ": " << x << "  " << #y << ": " << y << endl

ll cnt = 0;
/**
* What is the problem in this code.
**/



void brute(string rec, pii current, pii sent, int n) {
	if (n <= 0) {
		return;
	}

	if (current.fi > sent.fi or current.se > sent.se) {
		return;
	}

	if (current.fi == sent.fi or current.se == sent.se) {
		// cout << rec << endl;
		cnt++;
		return;
	}

	if (rec[n - 1] == '?') {

		rec[n - 1] = '+';
		current.fi++;
		brute(rec, current, sent, n - 1);


		/**
		* On passing 'rec' as a reference we were messing up the string for the next recursion call below.
		*/

		rec[n - 1] = '-';
		current.fi--; current.se++;
		brute(rec, current, sent, n - 1);
	}
	else {
		brute(rec, current, sent, n - 1);
	}
}

void solve(string &sent, string &rec) {

	int sentf = count(all(sent), '+'), sentb = count(all(sent), '-'),
	    recf = count(all(rec), '+'), recb = count(all(rec), '-');

	int N = rec.size();


	int recu = N - (recf + recb);

	if (recu == 0) {
		if (sentf == recf and recb == sentb) {
			cout << 1 << endl;
		}
		else {
			cout << 0 << endl;
		}
		return;
	}


	cnt = 0;
	brute(rec, {recf, recb}, {sentf, sentb}, rec.size());

	// deb(cnt);

	ld temp = 1.0;

	while (recu--) {
		temp = temp * (ld)(0.5);
	}

	ld ans = (ld)cnt * temp;
	cout << ans << endl;

}

int main() {
	string sent, rec;
	cin >> sent >> rec;
	solve(sent, rec);
}