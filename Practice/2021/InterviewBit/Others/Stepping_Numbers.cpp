#include <bits/stdc++.h>
#include <string>
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


vector<int> res;
void rec(string &upper, string &lower, string &current) {
	int num = stoi(current);
	int nup = stoi(upper), nlo = stoi(lower);


	if ((current.size() >= lower.size() and nlo > num) or num > nup) return;

	if (num >= nlo and num <= nup) res.push_back(num);

	int N = current.size();
	if (current[N - 1] == '9') {
		current.push_back(current[N - 1] - 1);
		rec(upper, lower, current);
		current.pop_back();
	}
	else if (current[N - 1] == '0') {
		current.push_back(current[N - 1] + 1);
		rec(upper, lower, current);
		current.pop_back();
	}
	else {
		current.push_back(current[N - 1] - 1);
		rec(upper, lower, current);
		current.pop_back();
		current.push_back(current[N - 1] + 1);
		rec(upper, lower, current);
		current.pop_back();
	}
}

vector<int> stepnum(int A, int B) {
	string U = to_string(A), L = to_string(B);
	for (int i = 1; i <= 9; i++) {
		string current = to_string(i);
		rec(L, U, current);
	}
	sort(res.begin(), res.end());
	return res;
}




int main() {
	int A , B;
	cin >> A >> B;
	vector<int> ans = stepnum(A, B);
	cout << ans << endl;
}
