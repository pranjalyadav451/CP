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



int solve(vll &arr, int n, int m) {
    map<ll, ll>marr;
    for (int i = 0; i < n; i++) {
        marr[arr[i] % m]++;
    }

    vector<bool >visited(m, false);
    ll cnt = marr.find(0) == marr.end() ? 0 : 1;
    visited[0] = true;

    for (auto &ele : marr) {
        if (visited[ele.first]) continue;
        visited[ele.first] = true;

        auto other = marr.find(m - ele.first);
        if (other != marr.end()) {
            if (other->first == ele.first) {
                cnt++;
            }
            else {
                cnt += max(ele.second, other->second) - min(ele.second, other->second) + (other->second == ele.second);
            }
            visited[other->first] = true;
        }
        else {
            cnt += ele.second;
        }
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt;
    cin >> tt;
    while (tt--)
    {
        int n, m;
        cin >> n >> m;
        vll arr(n);
        REP(i, 0, n - 1)
        {
            cin >> arr[i];
        }
        cout << solve(arr, n, m) << endl;
    }
}