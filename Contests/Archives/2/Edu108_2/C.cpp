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
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

// void solve(vector<ll>&uni, vector<ll>&skill)
// {

// }

const ll N = 2e5 + 5;




void solve(map<ll , vector<ll>>&uni, map<ll, vector<ll>>&prefixSum, ll n)
{
	ll ans[n];
	memset(ans, 0, sizeof(ans));

	for (auto a : prefixSum)
	{
		int a_size = a.second.size();

		for (int i = 0; i < a_size; i++)
		{
			int toLeave = a_size % (i + 1);
			ans[i] += a.second[a_size - toLeave - 1];
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
}

int main()
{
	ll tt;
	cin >> tt;
	while (tt--)
	{

		map<ll , vector<ll>>uni;
		map<ll, vector<ll>>prefixSum;

		ll n;
		cin >> n;

		vector<ll>children(n + 1);


		ll temp = 0;

		for (ll i = 1; i <= n; i++)
		{
			cin >> children[i];
		}


		for (ll i = 1; i <= n; i++)
		{
			cin >> temp;
			uni[children[i]].push_back(temp);
		}


		ll sum = 0;

		ll mx_size = INT_MIN;

		for (auto &a : uni)
		{
			sum = 0;
			mx_size = max((ll)a.second.size(), (ll)mx_size);
			sort(a.second.rbegin(), a.second.rend());
			for (ll b : a.second)
			{
				sum += b;
				prefixSum[a.first].push_back(sum);
			}
		}


		solve(uni, prefixSum, n);
	}
}