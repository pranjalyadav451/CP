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


vector<vector<int>> g_res;
void com_sum(vector<int> &A, vector<int> &curr, int curr_sum, int sum, int i = 0) {
	if (i >= A.size() or curr_sum > sum) return;
	if (curr_sum == sum) {
		g_res.push_back(curr);
		return;
	}

	if (curr_sum + A[i] <= sum) {
		curr.push_back(A[i]);
		com_sum(A, curr, curr_sum + A[i], sum, i);
		curr.pop_back();
	}
	com_sum(A, curr, curr_sum, sum, i + 1);
}



vector<vector<int> > combinationSum(vector<int> &A, int B) {
	g_res.clear();
	vector<int> curr;
	sort(A.begin(), A.end());
	com_sum(A, curr, 0, B);
	(void)unique(g_res.begin(), g_res.end());
	sort(g_res.begin(), g_res.end());
	return g_res;
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
