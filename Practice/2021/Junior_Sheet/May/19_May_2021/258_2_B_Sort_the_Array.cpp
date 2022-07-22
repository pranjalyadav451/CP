#include <bits/stdc++.h>
#include <limits.h>
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

/**
 * Started at 12:40pm
 * Finished on 20 May
 * Status : AC.
*/
void solve(vector<ll> &arr, int n) {
	int start = -1, end = -1, count = 0;
	arr.push_back(INT_MAX);
	n = n + 1;

	for (int i = 0; i < n - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			start = i;
			int temp = i;
			while (arr[temp] > arr[temp + 1] and temp < n - 1) {
				temp++;
			}
			end = temp;
			i = temp - 1;
		}
	}
	// dbgg(start, end);

	reverse(arr.begin() + start, arr.begin() + end + 1);
	bool ans = is_sorted(ALL(arr));
	if (ans) {
		cout << "yes" << endl;
		if (start == -1 and end == -1) {
			cout << 1 << " " << 1 << endl;
		}
		else {
			cout << start + 1 << " " << end  + 1 << endl;
		}
	}
	else cout << "no" << endl;
}

int main() {
	int n;
	cin >> n;
	vector<ll> arr(n);
	REP(i, 0, n - 1) cin >> arr[i];
	solve(arr, n);
}
