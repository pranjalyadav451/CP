//* https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=944

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

typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef long double ld;
#define ALL(x) (x).begin(),(x).end()
#define REP(i, a, b) for (int i = (a); i <= (b); (i)++)
#define RREP(i, a, b) for (int i = (a); i >= (b); (i)--)
#define dbg(x) cout << #x << ": " << x << endl
#define dbgg(x, y) cout << #x << ": " << x << "  " << #y << ": " << y << endl

/** *** GLOBALS *** **/



vector<int> arr;
int dp[60][60];
/** *** FUNCTIONS *** **/
int making_cuts(int start, int end) {
	if (end - start <= 1) {
		return 0;
	}
	if (dp[start][end] != -1) { return dp[start][end];}
	int mn = INT_MAX;
	for (int i = start + 1; i < end; i++) {
		mn = min(mn, arr[end] - arr[start] + making_cuts(start , i) + making_cuts(i, end));
	}
	return dp[start][end] = mn;
}


int main() {
	/** *** INPUT *** **/
	int l, n;
	while (cin >> l) {
		if (l == 0) return 0;
		cin >> n;

		arr.assign(n + 1, 0);
		for (int i = 1; i <= n; i++) { cin >> arr[i]; }
		arr.push_back(l);

		/** *** SOLUTION *** **/
		memset(dp, -1, sizeof(dp));
		string ans = "The minimum cutting is ";
		int mn = making_cuts(0, n + 1);
		cout << ans << mn << "." << endl;
	}



}
