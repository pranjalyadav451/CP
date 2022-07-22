/*
name: C. 3SUM Closure
group: Codeforces - Codeforces Round #803 (Div. 2)
url: https://codeforces.com/contest/1698/problem/C
interactive: false
memoryLimit: 256
timeLimit: 1000
Started At: 8:42:33 PM
*/
#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> oset;

int fastio() {
	ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0;
} int __fastio = fastio();
template<typename A, typename B>    ostream &operator<<(ostream &os, const pair<A, B> &p);
template<typename A>                ostream &operator<<(ostream &os, const set<A> &m) {os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A>                ostream &operator<<(ostream &os, const multiset<A> &m) {os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A, typename B>    ostream &operator<<(ostream &os, const map<A, B> &m) {os << "{"; string sep = ""; for (auto e : m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}"; }
template<typename T>                ostream &operator<<(ostream &os, const vector<T> &v) {os << "["; string sep = ""; for (auto e : v) os << sep << e, sep = ", "; return os << "]"; }
template<typename T, size_t L>      ostream &operator<<(ostream &os, const array<T, L> &v) {os << "["; string sep = ""; for (int i = 0; i < L; ++i) os << sep << v[i], sep = ", "; return os << "]"; }
template<typename A, typename B>    ostream &operator<<(ostream &os, const pair<A, B> &p) {os << '(' << p.first << ", " << p.second << ')'; return os; }


typedef long long                           ll;
typedef vector<ll>                          vll;
typedef pair<ll, ll>                        pll;
typedef vector<vector<ll>>                  vvl;
typedef vector<pll>                         vpl;
typedef pair<int, int>                      pii;
typedef long double                         ld;




#define all(x)                              (x).begin(),(x).end()
#define REP(i, a, b)                        for (int i = (a); i <= (b); (i)++)
#define RREP(i, a, b)                       for (int i = (a); i >= (b); (i)--)
#define dbg(x)                              cout << #x << ": " << x << endl
#define dbgg(x, y)                          cout << #x << ": " << x << "  " << #y << ": " << y << endl


template<typename T> void read_array(ll n, vector<T> &arr) {arr.resize(n); for (int i = 0; i < n; i++) cin >> arr[i]; }
template<typename... Args> void read(Args&... args) {((cin >> args), ...); }

vector<string >process(string &str) {vector<string> res; string temp = ""; for (int i = 0; i < str.size(); i++) {if (str[i] == ',') {res.push_back(temp); temp = ""; i++; } else temp.push_back(str[i]); } res.push_back(temp); return res; }
template<typename ...Args> void logger(string vars, Args&&... values) {string delim = ""; stringstream ss; (..., (ss << delim << values, delim = ", ")); delim = ""; string arrow = " : ", str_values = ss.str(); auto labels = process(vars), content = process(str_values); cout << "[ "; for (int i = 0; i < labels.size(); i++) {cout << delim << labels[i] << arrow << content[i]; delim = ", "; } cout << " ]" << endl; }
#define log_all(...)                        logger(#__VA_ARGS__, __VA_ARGS__)


bool check(vll &arr, int n) {
	bool res = true;
	set<ll> uniq;
	for (int i = 0; i < n; i++) uniq.insert(arr[i]);

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				ll t = arr[i] + arr[j] + arr[k];
				if (uniq.count(t) == 0) return false;
			}
		}
	}
	return true;
}

void solve() {
	ll n; read(n);
	vll arr; read_array(n, arr);

	ll p = 0 , neg = 0 , z = 0;
	for (int i = 0; i < n; i++) {
		p += arr[i] > 0;
		neg += arr[i] < 0;
		z += arr[i] == 0;
	}

	if (p > 2 or neg > 2) {
		cout << "NO" << endl;
		return;
	}

	vll B;
	z = min(z, 3LL);
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0 and z) {
			B.push_back(arr[i]);
			z--;
		}
		if (arr[i] != 0)
			B.push_back(arr[i]);
	}


	bool ans = check(B, B.size());
	cout << (ans ? "YES" : "NO") << endl;
}
int main() {
	int tt = 1;
	cin >> tt; // "UN - COMMENT THIS FOR TESTCASES"
	while (tt--) {
		solve();
	}

}