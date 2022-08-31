#include <bits/stdc++.h>
using namespace std;
int fastio()
{
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(10);
	cin.tie(nullptr);
	return 0;
}
int __fastio = fastio();
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p);
template <typename A>
ostream &operator<<(ostream &os, const set<A> &m)
{
	os << "{";
	string sep = "";
	for (auto e : m)
		os << sep << e, sep = ", ";
	return os << "}";
}
template <typename A>
ostream &operator<<(ostream &os, const multiset<A> &m)
{
	os << "{";
	string sep = "";
	for (auto e : m)
		os << sep << e, sep = ", ";
	return os << "}";
}
template <typename A, typename B>
ostream &operator<<(ostream &os, const map<A, B> &m)
{
	os << "{";
	string sep = "";
	for (auto e : m)
		os << sep << e.first << ": " << e.second, sep = ", ";
	return os << "}";
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
	os << "[";
	string sep = "";
	for (auto e : v)
		os << sep << e, sep = ", ";
	return os << "]";
}
template <typename T, size_t L>
ostream &operator<<(ostream &os, const array<T, L> &v)
{
	os << "[";
	string sep = "";
	for (int i = 0; i < L; ++i)
		os << sep << v[i], sep = ", ";
	return os << "]";
}
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p)
{
	os << '(' << p.first << ", " << p.second << ')';
	return os;
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
	cerr << ' ' << H;
	dbg_out(T...);
}
#ifdef LOCAL
#define pp(...) cerr << "\t[" << #__VA_ARGS__ << "]:\t", dbg_out(__VA_ARGS__)
#define ppp(x) cerr << x << "\n"
#else
#define pp(...)
#define ppp(...)
#endif
template <class Fun>
class y_combinator_result
{
	Fun fun_;

public:
	template <class T>
	explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
	template <class... Args>
	decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template <class Fun>
decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
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

const int MAXN = 1e5 + 5;

vector<int> graph[MAXN];

/**
	How to divide the vertex-set into two disjoint parts.

*/

short color[MAXN];

void bfs(int i = 1)
{
	queue<int> q;
	q.push(i);
	color[i] = 1;

	int temp = 0;
	while (q.empty() == false)
	{
		temp = q.front();
		q.pop();
		for (int a : graph[temp])
		{
			if (color[a] == -1)
			{
				color[a] = 1 - color[temp];
				q.push(a);
			}
		}
	}
}

ll solve(ll n)
{
	memset(color, -1, sizeof(color));
	bfs();
	ll odd = 0, even = 0;
	for (ll i = 1; i <= n; i++)
	{
		if (color[i] == 1)
			odd++;
		else
			even++;
	}

	ll ans = odd * even - (n - 1);
	return ans;
}

int main()
{
	ll n;
	cin >> n;

	ll u, v;

	for (ll i = 1; i < n; i++)
	{
		cin >> u >> v;
		graph[v].push_back(u);
		graph[u].push_back(v);
	}

	cout << solve(n) << endl;
}