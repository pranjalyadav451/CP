/*
name: E1. Divisible Numbers (easy version)
group: Codeforces - Codeforces Round  #828 (Div. 3)
url: https://codeforces.com/contest/1744/problem/E1
interactive: false
memoryLimit: 256
timeLimit: 4000
Started At: 8:46:20 PM
*/

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

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
typedef vector<ll>                          vll;
typedef pair<ll, ll>                        pll;
typedef vector<vector<ll>>                  vvl;
typedef vector<pll>                         vpl;
typedef pair<int, int>                      pii;
typedef long double                         ld;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> oset;
typedef map<ll, ll>                        mpll;




#define all(x)                              (x).begin(),(x).end()
#define REP(i, a, b)                        for (int i = (a); i <= (b); (i)++)
#define RREP(i, a, b)                       for (int i = (a); i >= (b); (i)--)
#define dbg(x)                              cout << #x << ": " << x << endl
#define dbgg(x, y)                          cout << #x << ": " << x << "  " << #y << ": " << y << endl

template<typename T> void in_arr(ll n, vector<T> &arr) {
    if (arr.size() != n) arr.resize(n); for (int i = 0; i < n; i++) cin >> arr[i];
}
template<typename... Args> void in(Args&... args) {
    ((cin >> args), ...);
}

vector<string >process(string &str) {
    vector<string> res; string temp = ""; for (int i = 0; i < str.size(); i++) {
        if (str[i] == '|') {
            res.push_back(temp); temp = "";
        }
        else temp.push_back(str[i]);
    } res.push_back(temp); return res;
}
template<typename ...Args> void logger(string vars, Args&&... values) {
    string delim = ""; stringstream ss; (..., (ss << delim << values, delim = "|")); delim = ""; string arrow = " : ", str_values = ss.str(); for (auto &a : vars) if (a == ',') a = '|'; auto labels = process(vars), content = process(str_values); cout << "[ "; for (int i = 0; i < labels.size(); i++) {
        cout << delim << labels[i] << arrow << content[i]; delim = ", ";
    } cout << " ]" << endl;
}
#define out(...)                        logger(#__VA_ARGS__, __VA_ARGS__)

namespace _Number_Theory {
    // EVERYTHING LOOKS GOOD HERE.
    ll gcd(ll a, ll b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }
    std::bitset<15000105> is_prime;
    void just_sieve(int N) {
        is_prime.set();
        is_prime[0] = is_prime[1] = 0;
        for (ll i = 2; i * i <= N; i++) {
            if (is_prime[i]) {
                for (ll j = i; j * i <= N; j++) {
                    is_prime[j * i] = false;
                }
            }
        }
    }

    bool __primes_generated__ = false;
    std::vector<ll> primelist;

    void genprimes(int N) {
        __primes_generated__ = true;
        just_sieve(N + 10);

        for (ll i = 2; i <= N; i++) {
            if (is_prime[i]) {
                primelist.push_back(i);
            }
        }
    }

    void factors(ll N, map<ll, ll> &res) {
        for (ll i = 0; primelist[i] * primelist[i] <= N; i++) {
            // if (is_prime[N]) break;
            if (N % primelist[i] == 0) {
                ll times = 0;
                while (N % primelist[i] == 0) {
                    N /= primelist[i];
                    times++;
                }
                res[primelist[i]] = times;
            }
        }
        if (N > 1) {
            res[N] = 1;
        }
    }
}
using namespace _Number_Theory;

void combine(map<ll, ll> &pa, map<ll, ll> &pb, map<ll, ll> &res) {
    for (auto [i, j] : pa) {
        res[i] += j;
    }
    for (auto [i, j] : pb) {
        res[i] += j;
    }
}


mpll get_req(mpll &base, mpll &have) {
    mpll ans;
    for (auto &[prime, times] : base) {
        ans[prime] = max(0LL, times - have[prime]);
    }
    return ans;
}

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll check(ll wehave, ll b, ll d) {
    if (wehave == 0) wehave = 1;
    ll q = d / wehave;
    ll num = wehave * q;
    return (num > b and num <= d) ? num : -1;
}


void solve() {
    ll a, b, c, d;
    in(a, b, c, d);
    // out(a,b,c,d);

    map<ll, ll> pa, pb;
    map<ll, ll> comb;

    factors(a, pa); factors(b, pb);
    combine(pa, pb, comb);

    map<ll, ll> px, py, req;

    pll final_ans = { -1,-1 };

    for (ll x = a + 1; x <= c; x++) {
        px.clear(); py.clear();
        factors(x, px);

        req = get_req(comb, px);

        ll wehave = 0;
        for (auto [prime, times] : req) {
            if (wehave == 0) wehave = binpow(prime, times);
            else wehave *= binpow(prime, times);
        }
        ll num = check(wehave, b, d);
        if (num != -1) {
            final_ans = { x,num };
            break;
        }
    }
    cout << final_ans.first << " " << final_ans.second << endl;
}
int main() {
    genprimes(1e6);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
}