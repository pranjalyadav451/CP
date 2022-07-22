/*
https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1266
Time Limit: 3000
Memory Limit: 32
Sun Mar 27 2022 13:00:28 GMT+0530 (India Standard Time)
*/


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

ll gcd(ll a, ll b) {
	while (a) {
		b = b % a;
		swap(a, b);
	}
	return b;
}
ll lcm(ll a , ll b = 1) {
	ll hcf = gcd(a, b);
	ll ans = (a / hcf) * b;
	return ans;
}


vvl all_comb;
void gen_comb(vll &arr, int i, vll & comb) {
	if (i >= arr.size()) {
		all_comb.push_back(comb);
		return;
	}

	comb.push_back(arr[i]);
	gen_comb(arr, i + 1, comb);
	comb.pop_back();
	gen_comb(arr, i + 1, comb);
}



ll get_lucky(ll N , ll M , vll &arr) {
	ll ans = N;
	vll comb;
	all_comb.clear();
	gen_comb(arr, 0, comb);
	all_comb.pop_back();

	for (int i = 0; i < all_comb.size(); i++) {
		int K = all_comb[i].size();
		ll current_lcm = 1;
		for (int j = 0; j < all_comb[i].size(); j++) {
			current_lcm = lcm(current_lcm, all_comb[i][j]);
		}
		if (K % 2) {
			ans -= N / current_lcm;
		}
		else ans += N / current_lcm;
	}

	return ans;
}

int main() {
	ll N , M;
	while (cin >> N) {
		cin >> M;
		vll arr(M);
		for (int i = 0; i < M; i++) {
			cin >> arr[i];
		}
		ll ans = get_lucky(N, M, arr);
		cout << ans << endl;
	}
}
