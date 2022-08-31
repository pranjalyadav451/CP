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
#define ALL(x) (x).begin(),(x).end()
#define REP(i, a, b) for (int i = (a); i <= (b); (i)++)
#define RREP(i, a, b) for (int i = (a); i >= (b); (i)--)
#define dbg(x) cout << #x << ": " << x << endl
#define dbgg(x, y) cout << #x << ": " << x << "  " << #y << ": " << y << endl

/** *** GLOBALS *** **/



/** *** FUNCTIONS *** **/



int main() {
	/** *** INPUT *** **/
	int tt = 1;
	cin >> tt;
	while (tt--) {



		/** *** SOLUTION *** **/
	}
}


/** Official Editorial
The solution is based on the fact that an optimal assignment for a exists such that for each vertex v, av∈lv,rv.

Proving this fact isn't hard, pick any assignment for a. Assume v is a vertex in this assignment such that av∉lv,rv.

Let p be the number of vertices u adjacent to v such that au>av.

Let q be the number of vertices u adjacent to v such that au<av.

Consider the following cases:

p>q: In this case we can decrease av to lv and get a better result.
p<q: In this case we can increase av to rv and get a better result.
p=q: In this case changing av to lv or rv will either increase or not change the beauty of the tree.
Based on this fact, we can use dynamic programming to find the answer.

Define dpv,0 as the maximum beauty of v's subtree if av is equal to lv.

Similarly, define dpv,1 as the maximum beauty of v's subtree if av is equal to rv.

dpv,j is calculated based on v's children, for each of v's children such as u, we add u's contribution to dpv,j.

The transitions are:

dpv,0+=max(dpu,0+|lv−lu|,dpu,1+|lv−ru|)
dpv,1+=max(dpu,0+|rv−lu|,dpu,1+|rv−ru|)
It's clear that the answer is equal to max(dpv,0,dpv,1).

complexity: O(n)
**/