#include <bits/stdc++.h>
using namespace std;
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


vector<vector<int>> res;

void comb_sum(vector<int> &A, vector<int> &ans, int target, int current = 0, int i = 0) {
	if (current == target) {
		res.push_back(ans);
		return;
	}
	if (i >= A.size()) return;

	if (current + A[i] <= target) {
		ans.push_back(A[i]);
		comb_sum(A, ans, target, current + A[i], i + 1);
		ans.pop_back();
	}
	comb_sum(A, ans, target, current, i + 1);
}

vector<vector<int> > combinationSum(vector<int> &A, int B) {
	res.clear();
	sort(A.begin(), A.end());
	vector<int> ans;
	comb_sum(A, ans, B);
	sort(res.begin(), res.end());
	return res;
}


int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (auto &a : A)
		cin >> a;
	int B; cin >> B;
	vector<vector<int>> ans = combinationSum(A, B);
	for (auto a : ans) {
		cout << a << endl;
	}
}
