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


    bool test_prime(ll N) {
        if (N <= 1)
            return false;
        if (N <= 3)
            return true;

        if (N % 2 == 0 or N % 3 == 0)
            return false;
        for (ll i = 5; i * i <= N; i += 6) {
            if (N % (i + 2) == 0 or N % i == 0)
                return false;
        }
        return true;
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

    std::vector<ll> factors(ll N) {
        if (!__primes_generated__) {
            std::cerr << "Just DO IT , (Call genprimes)" << std::endl;
            exit(1);
        }
        std::vector<ll> facs;
        for (ll i = 0; primelist[i] * primelist[i] <= N; i++) {
            if (N % primelist[i] == 0) {
                while (N % primelist[i] == 0) {
                    N /= primelist[i];
                    facs.push_back(primelist[i]);
                }
            }
        }
        if (N > 1) {
            facs.push_back(N);
        }
        sort(facs.begin(), facs.end());
        return facs;
    }
    std::vector<ll> getdivs(ll N) {
        std::vector<ll> divs;
        for (ll i = 1; i * i <= N; i++) {
            if (N % i == 0) {
                if (N / i == i)
                    divs.push_back(i);
                else
                    divs.push_back(i), divs.push_back(N / i);
            }
        }
        return divs;
    }
}
using namespace _Number_Theory;


void solve() {
    ll a, b, c, d;
    in(a, b, c, d);

    vll diva = getdivs(a), divb = getdivs(b);
    pll ans = { -1,-1 };
    for (int i = 0; i < diva.size(); i++) {
        for (int j = 0; j < divb.size(); j++) {
            ll can1 = diva[i] * divb[j];
            ll x = (can1) * (c / can1);
            ll can2 = (a * b) / can1;
            ll y = can2 * (d / can2);
            if (x > a and x <= c and y > b and y <= d) {
                ans = { x,y };
                goto done;
            }
        }
    }
done:
    cout << ans.first << " " << ans.second << endl;
}
int main() {
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
}