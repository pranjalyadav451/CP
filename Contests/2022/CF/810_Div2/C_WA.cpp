/*
name: C. Color the Picture
group: Codeforces - Codeforces Round #810 (Div. 2)
url: https://codeforces.com/contest/1711/problem/C
interactive: false
memoryLimit: 256
timeLimit: 1000
Started At: 8:52:35 PM
*/
#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

int fastio() {
	ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0;
} int __fastio = fastio();
template<typename A, typename B>    ostream &operator<<(ostream &os, const pair<A, B> &p);
template<typename A>                ostream &operator<<(ostream &os, const set<A> &m) {
	os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}";
}
template<typename A>                ostream &operator<<(ostream &os, const multiset<A> &m) {
	os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}";
}
template<typename A, typename B>    ostream &operator<<(ostream &os, const map<A, B> &m) {
	os << "{"; string sep = ""; for (auto e : m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}";
}
template<typename T>                ostream &operator<<(ostream &os, const vector<T> &v) {
	os << "["; string sep = ""; for (auto e : v) os << sep << e, sep = ", "; return os << "]";
}
template<typename T, size_t L>      ostream &operator<<(ostream &os, const array<T, L> &v) {
	os << "["; string sep = ""; for (int i = 0; i < L; ++i) os << sep << v[i], sep = ", "; return os << "]";
}
template<typename A, typename B>    ostream &operator<<(ostream &os, const pair<A, B> &p) {
	os << '(' << p.first << ", " << p.second << ')'; return os;
}


typedef long long                           ll;
typedef vector<ll>                          vll;
typedef pair<ll, ll>                        pll;
typedef vector<vector<ll>>                  vvl;
typedef vector<pll>                         vpl;
typedef pair<int, int>                      pii;
typedef long double                         ld;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> oset;




#define all(x)                              (x).begin(),(x).end()
#define REP(i, a, b)                        for (int i = (a); i <= (b); (i)++)
#define RREP(i, a, b)                       for (int i = (a); i >= (b); (i)--)
#define dbg(x)                              cout << #x << ": " << x << endl
#define dbgg(x, y)                          cout << #x << ": " << x << "  " << #y << ": " << y << endl

template<typename T> void in_arr(ll n, vector<T> &arr) {
	if (arr.size() != n) arr.resize(n); for (int i = 0; i < n; i++) cin >> arr[i];
}
template<typename... Args> void in(Args&... args) {
	((cin >> args), ...);
}

vector<string >process(string &str) {
	vector<string> res; string temp = ""; for (int i = 0; i < str.size(); i++) {
		if (str[i] == '|') {
			res.push_back(temp); temp = "";
		}
		else temp.push_back(str[i]);
	} res.push_back(temp); return res;
}
template<typename ...Args> void logger(string vars, Args&&... values) {
	string delim = ""; stringstream ss; (..., (ss << delim << values, delim = "|")); delim = ""; string arrow = " : ", str_values = ss.str(); for (auto &a : vars) if (a == ',') a = '|'; auto labels = process(vars), content = process(str_values); cout << "[ "; for (int i = 0; i < labels.size(); i++) {
		cout << delim << labels[i] << arrow << content[i]; delim = ", ";
	} cout << " ]" << endl;
}
#define out(...)                        logger(#__VA_ARGS__, __VA_ARGS__)



bool color(ll n , ll m, vll &pigment) {
	int k = pigment.size();

	vll can_color(k);
	for (int i = 0; i < k; i++) {
		can_color[i] = pigment[i] / m;
	}
	ll colored = 0;
	bool great = false;

	for (int i = 0; i < k; i++) {
		if (can_color[i] >= 2) colored += can_color[i];
		if (can_color[i] > 2) great = true;
	}
	if (n % 2) return colored >= n and great;
	return colored >= n;
}


void solve() {
	ll n, m, k;
	in(n, m, k);
	vll pigment(k); in_arr(k, pigment);
	ll total = 0;
	for (int i = 0; i < k; i++) {
		total += pigment[i];
	}
	// there are problemms with accumulate();
	if (total < n * m) {
		cout << "NO" << endl;
		return;
	}
	bool ans = color(n, m, pigment) || color(m, n, pigment);
	cout << (ans ? "YES" : "NO") << endl;
}
int main() {
	int tt = 1;
	cin >> tt; // "UN - COMMENT THIS FOR TESTCASES"
	while (tt--) {
		solve();
	}
}