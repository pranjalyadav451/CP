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


bool is(string &A, bool is_exp) {
	if (A.size() == 0) return true;

	int N = A.size();
	int i = 0;
	if (A[i] == '-') i++;
	int decimals = 0;
	for (; i < N; i++) {
		if (A[i] == '.' and i == N - 1) return false;
		if (A[i] == '.') decimals++;
		else {
			if (A[i] - '0' >= 0 and A[i] - '0' <= 9) continue;
			else return false;
		}
	}
	if (is_exp) return decimals == 0;
	return decimals <= 1;
}

void trimmed(string &A, const string &arr) {
	int start = 0 , end = arr.size() - 1;
	int N = arr.size();
	while (start < N and arr[start] == ' ') start++;
	while (end >= 0 and arr[end] == ' ') end--;

	if (end < start) A = "";

	A = arr.substr(start, end - start + 1);
}

int isNumber(const string arr) {
	string base , exp;
	string options = "-0123456789.e";
	int idx_exp = -1;
	string A;
	trimmed(A, arr);
	if (A.size() == 0) return false;

	dbg(A);
	for (int i = 0; i < A.size(); i++) {
		if (options.find(A[i]) == string::npos) return false;

		if (A[i] == 'e' and (i == 0 or i == A.size() - 1)) return false;

		if (A[i] == '.' and i == A.size() - 1) return false;
		if (A[i] == 'e') {
			idx_exp = i + 1;
			break;
		}
		base.push_back(A[i]);
	}
	if (idx_exp != -1)
		exp = A.substr(idx_exp);
	dbgg(base, exp);
	// exponent cannot contain decimal points
	bool ans = is(base, 0) && is(exp, 1);
	return ans;
}

vector<string> deserialize(string A) {
	vector<string> res;
	int N = A.size();

	string break_at = "123456789";

	for (int i = 0; i < N; i++) {
		string current = "";
		int j = i;
		while (j < N and A[j] != '~') {
			if (break_at.find(A[j]) != string::npos) {
				j++;
				continue;
			}
			current.push_back(A[j]);
			j++;
		}
		i = j;
		res.push_back(current);
	}
	return res;
}




int main() {
	string str;
	cin >> str;
	vector<string> res = deserialize(str);
	cout << res << endl;
}