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

template<class Fun> class y_combinator_result { Fun fun_; public: template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {} template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); } };
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
#define yc y_combinator
template<typename ...Args>

void logger(string vars, Args&&... values) {cout << "[" << "( " << vars << " )" << " :-> ( "; string delim = ""; (..., (cout << delim << values, delim = ", ")); cout << " )]" << endl;}
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
#define log_all(...)                        logger(#__VA_ARGS__, __VA_ARGS__)

vector<pii> knight = {
	{ -2, 1}, { -2 , - 1}, { -1, 2}, { -1, -2},
	{ 2, 1}, { 2 , - 1}, { 1, 2}, { 1, -2}
};

bool is_safe(pii &pos) {
	int f = pos.first , s = pos.second;
	return f >= 1 and f <= 8 and s <= 8 and s >= 1;
}

int main() {
	string from, to;
	while (cin >> from >> to) {
		// Parse the position into something usable
		pair<int, int> A = {from[0] - 'a' + 1, from[1] - '0'}, B = {to[0] - 'a' + 1, to[1] - '0'};

		map<pair<int, int>, int> dist;
		queue<pair<int, int>> bfs;

		dist[A] = 0;
		bfs.push(A);

		while (bfs.empty() == false) {
			pii current = bfs.front();
			int X = current.first, Y = current.second, D = dist[current];
			bfs.pop();

			for (int i = 0; i < 8; i++) {
				pii t = {X + knight[i].first, Y + knight[i].second};
				if (not is_safe(t) or dist.count(t)) continue;
				bfs.push(t);
				dist[t] = D + 1;
			}
		}
		// dbgg(A, B);
		// for (auto a : dist) cout << a << endl;

		int ans = (dist.count(B) == 0 ? -1 : dist[B]);
		cout << "To get from " << from << " to " << to << " takes " << ans << " knight moves." << endl;
	}
}
