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

struct Triplet {
    ll x{ 0 }, y{ 0 }, z{ 0 };
};
set<ll> pyth;

void gen_all() {
    ll N = 0;
    ll current = 0;
    // dbg(pyth.size());
    vector<Triplet> inter;
    while (current < 80) {
        ll first = (2 * N + 1),
           second = (2 * N * N + 2 * N),
           third = 2 * N * N + 2 * N + 1;
        current = third;

        Triplet trip;
        trip.x = first, trip.y = second, trip.z = third;
        inter.push_back(trip);
        N++;
    }

    for (auto &ele : inter) {
        ll sq = ele.z * ele.z;
        for (int i = 1; i <= 100; i++) {
            ll x = ele.x * i, y = ele.y * i, z = ele.z * i;
            Triplet trip;
            trip.x = x, trip.y = y, trip.z = z;
            pyth.insert(trip.z * trip.z);
        }
    }
    // cout << "here" << endl;
}

bool comp(const Triplet &X, const Triplet &Y) {
    vector<ll> first = { X.x, X.y, X.z }, second = { Y.x, Y.y, Y.z };
    sort(all(first));
    sort(all(second));
    return first < second;
}

void solve() {
    ll X, Y;
    cin >> X >> Y;
    ll dist = X * X + Y * Y;
    // cout << pyth << endl;
    if (X == 0 and Y == 0) cout << 0 << endl;
    else if (pyth.find(dist) != pyth.end()) cout << 1 << endl;
    else cout << 2 << endl;
}
int main() {
    int tt = 1;
    gen_all();
    cin >> tt; // "UN-COMMENT THIS FOR TESTCASES"
    while (tt--) {
        solve();
    }
}