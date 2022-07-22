#include <bits/stdc++.h>
#include <cctype>
#include <cmath>
#include<numeric>
using namespace std;
int fastio() {
	ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0;
} int __fastio = fastio();
template<typename A, typename B> ostream &operator<<(ostream &os, const pair<A, B> &p);
template<typename A> ostream &operator<<(ostream &os, const set<A> &m) {
	os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}";
}
template<typename A> ostream &operator<<(ostream &os, const multiset<A> &m) {
	os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}";
}
template<typename T>ostream &operator<<(ostream &os, const vector<T> &v) {
	os << "["; string sep = ""; for (auto e : v) os << sep << e, sep = ", "; return os << "]";
}
template<typename A, typename B> ostream &operator<<(ostream &os, const map<A, B> &m) {
	os << "{"; string sep = ""; for (auto e : m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}";
}
template<typename T, size_t L>ostream &operator<<(ostream &os, const array<T, L> &v) {
	os << "["; string sep = ""; for (int i = 0; i < L; ++i) os << sep << v[i], sep = ", "; return os << "]";
}
template<typename A, typename B> ostream &operator<<(ostream &os, const pair<A, B> &p) {
	os << '(' << p.first << ", " << p.second << ')'; return os;
}
void dbg_out() {
	cerr << endl;
}
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
	cerr << ' ' << H; dbg_out(T...);
}
#ifdef LOCAL
#define pp(...) cerr << "\t[" << #__VA_ARGS__ << "]:\t", dbg_out(__VA_ARGS__)
#define ppp(x) cerr << x << "\n"
#else
#define pp(...)
#define ppp(...)
#endif
template<class Fun> class y_combinator_result {
Fun fun_; public: template<class T> explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {} template<class ...Args> decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
#define yc y_combinator

typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef long double ld;
#define all(x) (x).begin(),(x).end()
#define rep(i, a, b) for (int i = (a); i <= (b); (i)++)
#define rrep(i, a, b) for (int i = (a); i >= (b); (i)--)
#define deb(x) cout << #x << ": " << x << endl
#define deb2(x, y) cout << #x << ": " << x << "  " << #y << ": " << y << endl

/**
N: 3  M: 10
2
------------------
N: 7  M: 17
12
------------------
N: 23  M: 43
81
------------------
N: 23  M: 11
217
------------------
**/
int countDivisors(int n, int b) {
	int cnt = 0;
	if (n == 0) return b - 1;
	int lim = (int)sqrt(n);
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			if (n / i <= b - 1) cnt++;
			if (n / i == i) continue;
			if (i <= b - 1) cnt++;
		}
	}
	return cnt;
}
void solve(ll N, ll M) {

	ll cnt = 0, extra = 0;
	ll lim = 0;

	if (N > M) {
		lim = M;
		extra += (N - M) * (M);
		ll nums = N - M - 1;
		extra += (nums) * (nums + 1) / 2;
	}
	else {
		lim = N;
	}

	for (ll i = 1; i <= lim; i++) {
		int toFind = (M - (M % i));
		int divisors = countDivisors(toFind, i);
		cnt += divisors;
	}
	cnt += extra;
	cout << cnt << endl;
}


int main() {
	int tt;
	cin >> tt;

	while (tt--) {
		int N, M;
		cin >> N >> M;
		solve(N, M);
	}
}
