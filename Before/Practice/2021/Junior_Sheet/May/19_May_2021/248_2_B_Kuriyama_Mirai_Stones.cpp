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
#define DEB(x) cout << #x << ": " << x << endl
#define DEBB(x, y) cout << #x << ": " << x << "  " << #y << ": " << y << endl

vector<ll> pre, pre_sort;
void making_pre(vector<ll>&arr, int N) {
	vector<ll > sorted = arr;
	sort(ALL(sorted));
	pre.assign(N + 1, 0);
	pre_sort.assign(N + 1, 0);

	for (int i = 1; i <= N; i++) {
		pre[i] = pre[i - 1] + arr[i - 1] ;
		pre_sort[i] = pre_sort[i - 1] + sorted[i - 1];
	}

}



int main() {
	int N;
	cin >> N;
	vector<ll> arr(N);
	for (ll &a : arr) {
		cin >> a;
	}
	making_pre(arr, N);

	int M;
	cin >> M;
	while (M--) {
		ll type, left, right;
		cin >> type >> left >> right;
		if (type == 1) {
			// Answer the first question.
			ll to_left = pre[N] - pre[left - 1], to_right = pre[N] - pre[right];
			cout << to_left - to_right << endl;
		}
		if (type == 2) {
			// Answer the second question.
			ll to_left = pre_sort[N] - pre_sort[left - 1], to_right = pre_sort[N] - pre_sort[right];
			cout << to_left - to_right << endl;
		}
	}
}