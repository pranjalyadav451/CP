#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } int __fastio = fastio();
template<typename A, typename B>    ostream& operator<<(ostream &os, const pair<A, B> &p);
template<typename A>                ostream& operator<<(ostream &os, const set<A> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A>                ostream& operator<<(ostream &os, const multiset<A> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A, typename B>    ostream& operator<<(ostream &os, const map<A, B> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}"; }
template<typename T>                ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; string sep = ""; for (auto e : v) os << sep << e, sep = ", "; return os << "]"; }
template<typename T, size_t L>      ostream& operator<<(ostream& os, const array<T, L>& v) { os << "["; string sep = ""; for (int i = 0; i < L; ++i) os << sep << v[i], sep = ", "; return os << "]"; }
template<typename A, typename B>    ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }


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



const int mxn = 2e3 + 10;
int dp[mxn][mxn];

int LIS(const vector<int> &A, int idx, int last_idx) {
	if (idx >= A.size()) return 0;

	if (last_idx == -1)
		return max(1 + LIS(A, idx + 1, idx), LIS(A, idx + 1, last_idx));

	int &ans = dp[idx][last_idx];
	if (ans != -1) return ans;

	if (A[idx] > A[last_idx]) {
		return max(1 + LIS(A, idx + 1 , idx) , LIS(A, idx + 1, last_idx));
	}
	return LIS(A, idx + 1, last_idx);
}

int lis(const vector<int> &A) {
	memset(dp, -1, sizeof(dp));

	int ans = LIS(A, 0, -1);
	return ans;
}

int main() {
	int N; cin >> N;
	vector<int> A(N);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int ans = lis(A);
	cout << ans << endl;
}