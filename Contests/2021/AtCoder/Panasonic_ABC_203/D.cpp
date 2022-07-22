#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } int __fastio = fastio();
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p);
template<typename A> ostream& operator<<(ostream &os, const set<A> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A> ostream& operator<<(ostream &os, const multiset<A> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const map<A, B> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}"; }
template<typename T>ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; string sep = ""; for (auto e : v) os << sep << e, sep = ", "; return os << "]"; }
template<typename T, size_t L>ostream& operator<<(ostream& os, const array<T, L>& v) { os << "["; string sep = ""; for (int i = 0; i < L; ++i) os << sep << v[i], sep = ", "; return os << "]"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

template<class Fun> class y_combinator_result { Fun fun_; public: template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {} template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); } };
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
#define yc y_combinator

typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef long double ld;
typedef vector<vector<ll>> vvl; typedef vector<ll> vll; typedef vector<pll> vpl;
#define all(x) (x).begin(),(x).end()
#define REP(i, a, b) for (int i = (a); i <= (b); (i)++)
#define RREP(i, a, b) for (int i = (a); i >= (b); (i)--)
#define dbg(x) cout << #x << ": " << x << endl
#define dbgg(x, y) cout << #x << ": " << x << "  " << #y << ": " << y << endl

/** *** GLOBALS *** **/

ll N, K;
vvl arr;

void solve() {
	ll n = N;
	ll k = K;
	vector<ll> temp;
	ll md = INT_MAX;
	ll idx = -1;
	idx = k % 2 == 0 ? k * k / 2 - 1 : k * k / 2;
	set<pll>visited;

	if (k == 1) {

	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp.push_back(arr[i][j]);
		}
	}


	for (ll extra = 0 ; extra + k <= n; extra++) {
		for (ll other = 0 ; other + k <= n; other++) {
			visited.insert({extra, other});
			temp.clear();
			for (ll i = extra; i < extra + k; i++) {
				for (ll j = other; j < other + k; j++) {
					temp.push_back(arr[i][j]);
				}
			}
			sort(all(temp));
			md = min(md, temp[idx]);
		}
	}
	for (ll extra = 0 ; extra + k <= n; extra++) {
		for (ll other = 0 ; other + k <= n; other++) {
			if (visited.count(make_pair(extra, other)) == 0) {
				temp.clear();
				for (ll i = extra; i < extra + k; i++) {
					for (ll j = other; j < other + k; j++) {
						temp.push_back(arr[j][i]);
					}
				}
				sort(all(temp));
				idx = k % 2 == 0 ? k * k / 2 - 1 : k * k / 2;
				md = min(md, temp[idx]);
			}
		}
	}

	cout << md << endl;
}



int main() {
	cin >> N >> K;
	arr.assign(N , vector<ll>(N, 0));
	REP(i, 0, N - 1) {
		REP(j, 0, N - 1) {
			cin >> arr[i][j];
		}
	}
	solve();
}
