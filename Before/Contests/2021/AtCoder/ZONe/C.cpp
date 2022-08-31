#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }
int __fastio = fastio();
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p);
template<typename A> ostream& operator<<(ostream &os, const set<A> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A> ostream& operator<<(ostream &os, const multiset<A> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const map<A, B> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}"; }
template<typename T>ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; string sep = ""; for (auto e : v) os << sep << e, sep = ", "; return os << "]"; }
template<typename T, size_t L>ostream& operator<<(ostream& os, const array<T, L>& v) { os << "["; string sep = ""; for (int i = 0; i < L; ++i) os << sep << v[i], sep = ", "; return os << "]"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define pp(...) cerr << "\t[" << #__VA_ARGS__ << "]:\t", dbg_out(__VA_ARGS__)
#define ppp(x) cerr << x << "\n"
#else
#define pp(...)
#define ppp(...)
#endif
template<class Fun> class y_combinator_result { Fun fun_; public: template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {} template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); } };
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
#define yc y_combinator
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second
#define sz(x) (int((x).size()))
#define rep(i, a, b) for (int(i) = (a); i <= (b); (i)++)
#define rrep(i, a, b) for (int(i) = (a); i >= (b); (i)--)
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()


const int MXN = 3e5 + 1;


vector<ll> dp[MXN][4];
vector<ll>final_ans(5);
const int __team = 3;


void solve(ll N, vector<vector<ll>>&stats, int curr_size, vector<ll>current)
{
	vector<ll>res(5);
	if (curr_size == 0)
	{
		if (*min_element(all(current)) > *min_element(all(final_ans)))
			final_ans = current;
	}

	if (N == 0 or curr_size <= 0 or N < curr_size)
		return ;


	vector<ll>inc(5);

	for (int i = 0; i < 5; i++)
		inc[i] = max(stats[N - 1][i], current[i]);

	solve(N - 1, stats, curr_size - 1, inc);
	solve(N - 1, stats, curr_size, current);

}

int main()
{
	ll N;
	cin >> N;
	vector<vector<ll>> stats(N, vector<ll>(5));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 5; j++)
			cin >> stats[i][j];
	}
	vector<ll>current(5);
	solve(N, stats, 3, current);
	// cout << final_ans << endl;
	cout << *min_element(all(final_ans));
}
