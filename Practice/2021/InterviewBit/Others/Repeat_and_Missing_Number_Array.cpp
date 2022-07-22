#include <bits/stdc++.h>
#include <numeric>
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


vector<int> repeatedNumber(const vector<int> &A) {
	vector<int> res;
	ll sum = 0 , other_sum = 0;
	ll N = A.size();

	sum = N * (N + 1) / 2LL;


	for (int i = 0; i < N; i++) {
		other_sum += (long long)A[i];
	}

	ll sq_sum_actual = 0 , sq_sum_ideal = 0;

	for (int i = 0; i < N; i++) {
		sq_sum_ideal += (long long)(i + 1) * (long long)(i + 1);
		sq_sum_actual += (long long) A[i] * (long long) A[i];
	}

	ll X = (sq_sum_actual - sq_sum_ideal) / (other_sum - sum);
	ll Y = other_sum - sum;

	res.push_back((X + Y) / 2);
	res.push_back((X - Y) / 2);

	return res;
}



int main() {
	int N;
	cin >> N;
	vector<int> arr(N);
	for (auto &a : arr) {
		cin >> a;
	}
	vector<int> ans = repeatedNumber(arr);
	for (auto &a : ans) {
		cout << a << "\t";
	}
	cout << endl;
}
