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
typedef vector<vector<ll>> vvl; typedef vector<ll> vll; typedef vector<pll> vpl;
#define all(x) (x).begin(),(x).end()
#define REP(i, a, b) for (int i = (a); i <= (b); (i)++)
#define RREP(i, a, b) for (int i = (a); i >= (b); (i)--)
#define dbg(x) cout << #x << ": " << x << endl
#define dbgg(x, y) cout << #x << ": " << x << "  " << #y << ": " << y << endl

/** *** GLOBALS *** **/
/**
 * Problem :
 * Given an array of integers, the array is called special if for every pair of
 * adjacent array elements their sum is a perfect square.
 * Find all the different permutations of a given array that are special.
 * **/

// ll is_perfect(ll N) {
// 	ll left = 0, right = N, mid = 0 , ans = -1;
// 	while (left <= right) {
// 		mid = left + (right - left) / 2;
// 		if (mid * mid == N) {ans = mid; break;}
// 		else if ( mid * mid < N) left = mid + 1;
// 		else right = mid - 1;
// 	}
// 	return ans == -1 ? false : true;
// }

// bool is_special(vll &arr, int N) {
// 	bool ans = true;
// 	for (int i = 1; i < N; i++) {
// 		ans = ans and is_perfect(arr[i] + arr[i - 1]);
// 	}
// 	return ans;
// }

// // NOT COMPLETED NOW.

int cnt = 0;
bool check_special(ll x, ll y) {
	ld root = sqrt(x + y);
	return root - floor(root) == 0;
}
void helper(vll &arr, int start) {
	if (start > 1 and !check_special(arr[start - 2], arr[start - 1])) {
		return;
	}
	if (start == arr.size() - 1 and !check_special(arr[start], arr[start - 1])) {
		return;
	}
	if (start == arr.size()) cnt++;
	unordered_set<int> s;
	for (int i = start; i < arr.size(); i++) {
		if (s.count(arr[i]) == 0) {
			s.insert(arr[i]);
			swap(arr[i], arr[start]);
			helper(arr, start + 1);
			swap(arr[i], arr[start]);
		}
	}
}

int number_of_special_perm(vll &arr, int N) {
	helper(arr, 0);
	return cnt;
}

int main() {

	int tt = 1;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vll arr(n);
		REP(i, 0, n - 1) {
			cin >> arr[i];
		}
		cnt = 0;
		number_of_special_perm(arr, n);
		dbg(cnt);
	}
}
