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

template <long long MOD = 1000000007>
class Modular {
public:
	long long value;
	static const long long MOD_value = MOD;

	Modular(long long v = 0) { value = v % MOD; if (value < 0) value += MOD;}
	Modular(long long a, long long b) : value(0) { *this += a; *this /= b;}

	Modular& operator+=(Modular const& b) {value += b.value; if (value >= MOD) value -= MOD; return *this;}
	Modular& operator-=(Modular const& b) {value -= b.value; if (value < 0) value += MOD; return *this;}
	Modular& operator*=(Modular const& b) {value = (long long)value * b.value % MOD; return *this;}

	friend Modular mexp(Modular a, long long e) {
		Modular res = 1LL; while (e) { if (e & 1LL) res *= a; a *= a; e >>= 1LL; }
		return res;
	}
	friend Modular inverse(Modular a) { return mexp(a, MOD - 2LL); }

	Modular& operator/=(Modular const& b) { return *this *= inverse(b); }
	friend Modular operator+(Modular a, Modular const b) { return a += b; }
	friend Modular operator-(Modular a, Modular const b) { return a -= b; }
	friend Modular operator-(Modular const a) { return 0LL - a; }
	friend Modular operator*(Modular a, Modular const b) { return a *= b; }
	friend Modular operator/(Modular a, Modular const b) { return a /= b; }
	friend std::ostream& operator<<(std::ostream& os, Modular const& a) {return os << a.value;}
	friend bool operator==(Modular const& a, Modular const& b) {return a.value == b.value;}
	friend bool operator!=(Modular const& a, Modular const& b) {return a.value != b.value;}
};


template<typename T> void read_array(ll n, vector<T> &arr) {arr.resize(n); for (int i = 0; i < n; i++) cin >> arr[i]; }
template<typename... Args> void read(Args&... args) {((cin >> args), ...); }

vector<string >process(string &str) {vector<string> res; string temp = ""; for (int i = 0; i < str.size(); i++) {if (str[i] == '|') {res.push_back(temp); temp = ""; i++; } else temp.push_back(str[i]); } res.push_back(temp); return res; }
template<typename ...Args> void logger(string vars, Args&&... values) {string delim = ""; stringstream ss; (..., (ss << delim << values, delim = "| ")); delim = ""; string arrow = " : ", str_values = ss.str(); for (auto &a : vars) if (a == ',') a = '|'; auto labels = process(vars), content = process(str_values); cout << "[ "; for (int i = 0; i < labels.size(); i++) {cout << delim << labels[i] << arrow << content[i]; delim = ", "; } cout << " ]" << endl; }
#define log(...)                        logger(#__VA_ARGS__, __VA_ARGS__)

typedef unordered_map<char, int> umint;

bool is(umint &sm, umint &tm) {
	for (auto t : tm) {
		if (sm.count(t.first) and sm[t.first] >= t.second) continue;
		else return false;
	}
	return true;
}
string minWindow(string S, string T) {

	unordered_map<char, int> sm , tm;
	for (auto t : T) tm[t]++;

	int start = 0 , end = 0;
	int len = 1e9;
	string ret;

	while (end < S.size() and start <= end) {
		if (not is(sm, tm)) {
			sm[S[end]]++;
			end++;
		}
		else {
			if (len > end - start) {
				string temp;
				for (int i = start; i < end; i++) {
					temp.push_back(S[i]);
				}
				ret = temp;
			}
			len = min(len, end - start);

			sm[S[start]]--;
			if (sm[S[start]] == 0) sm.erase(S[start]);

			start++;
		}
	}
	// log(len);

	while (start < end and is(sm, tm)) {
		if (len > end - start) {
			string temp;
			for (int i = start; i < end; i++) {
				temp.push_back(S[i]);
			}
			ret = temp;
		}
		len = min(len, end - start);
		sm[S[start]]--;
		if (sm[S[start]] == 0) sm.erase(S[start]);
		start++;
	}

	return ret;
}


void solve() {
	string A , B; read(A, B);
	string window = minWindow(A, B);
	log(window);
}
int main() {
	int tt = 1;
	// cin >> tt; // "UN - COMMENT THIS FOR TESTCASES"
	while (tt--) {
		solve();
	}
}