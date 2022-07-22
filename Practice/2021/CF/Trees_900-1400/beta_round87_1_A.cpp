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

bool visited[2001];
int mx = INT_MIN;

void dfs(vector<int> graph[], int i = 0, int depth = 1)
{
	if (visited[i] == false)
		visited[i] = true;
	else
		return;

	mx = max(mx, depth);

	for (int a : graph[i])
	{
		if (!visited[a])
		{
			dfs(graph, a, depth + 1);
		}
	}
}

int main()
{

	int n;
	cin >> n;
	vector<int> graph[n + 1];
	vector<int> roots;

	int pi = 0;

	for (int i = 1; i <= n; i++)
	{
		cin >> pi;
		if (pi != -1)
			graph[pi].push_back(i);
		else
			roots.push_back(i);
	}

	memset(visited, 0, sizeof visited);
	for (int a : roots)
	{
		dfs(graph, a);
	}
	cout << mx << endl;
}

/**
	Notes -:
	-> According to the given details
		- The given graph is a collection of directed trees.
		- WE CAN FORM GROUP OF ANY SIZE.(NOT JUST OF SIZE = 2)


		OFFICIAL EDITORIAL - :

		We let an employee without a manager called as root. There's an edge from a manager to an employee that he/she manages.

		First notice that the graph is a collection of directed trees. Hence, we can assign a "depth label" to each node - denoting the number of nodes on the simple path from the root to it. The answer is then the maximum depth a node has.

		Why?

		First, the answer is bounded below by this number because any pair of employees in this path cannot be in the same group. Second, since the graph is a tree, each node in the graph has a unique depth label assigned to it.

		|---->  Simply put all nodes with the same depth in the same group.

		It's fairly easy to see that no one will be the superior of another within a group, for otherwise their depths will not be equal.
*/