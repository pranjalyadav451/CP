#include <bits/stdc++.h>
#include <vector>

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
#define log_all(...)                        logger(#__VA_ARGS__, __VA_ARGS__)

int maxSpecialProduct(vector<int> &A) {
	int N = A.size();
	vector<int> left(N) , right(N);
	stack<int> L, R;

	left[0] = -1, right[N - 1] = -1;
	L.push(A[0]);
	R.push(A[N - 1]);
	for (int i = 1; i < N; i++) {
		while (L.size() and L.top() <= A[i]) {
			L.pop();
		}
		if (L.empty()) {
			left[i] = -1;
		}
		else {
			left[i] = L.top();
		}
		L.push(A[i]);
	}
	for (int i = N - 2 ; i >= 0; i--) {
		while (R.size() and R.top() <= A[i]) {
			R.pop();
		}
		if (R.empty()) {
			right[i] = -1;
		}
		else {
			right[i] = R.top();
		}
		R.push(A[i]);
	}
	long long ans = 0;
	long long MOD = 1e9 + 7;

	cout << left << endl;
	cout << right << endl;

	for (int i = 0; i < N; i++) {
		if (left[i] >= 0 and right[i] >= 0) {
			ans = max(ans, (long long)left[i] * (long long)right[i]);
		}
	}
	return ans % MOD;
}



int main() {
	int N; cin >> N;
	vector<int> arr(N);
	for (auto &a : arr) cin >> a;
	int ans = maxSpecialProduct(arr);
	cout << ans << endl;
}
