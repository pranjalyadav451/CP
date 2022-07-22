#include <bits/stdc++.h>
#include <limits.h>
#include <unordered_set>
using namespace std;
int fastio() {
    ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0;
} int __fastio = fastio();
template<typename A, typename B> ostream &operator<<(ostream &os, const pair<A, B> &p);
template<typename A> ostream &operator<<(ostream &os, const set<A> &m) {
    os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}";
}
template<typename A> ostream &operator<<(ostream &os, const multiset<A> &m) {
    os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}";
}
template<typename A, typename B> ostream &operator<<(ostream &os, const map<A, B> &m) {
    os << "{"; string sep = ""; for (auto e : m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}";
}
template<typename T>ostream &operator<<(ostream &os, const vector<T> &v) {
    os << "["; string sep = ""; for (auto e : v) os << sep << e, sep = ", "; return os << "]";
}
template<typename T, size_t L>ostream &operator<<(ostream &os, const array<T, L> &v) {
    os << "["; string sep = ""; for (int i = 0; i < L; ++i) os << sep << v[i], sep = ", "; return os << "]";
}
template<typename A, typename B> ostream &operator<<(ostream &os, const pair<A, B> &p) {
    os << '(' << p.first << ", " << p.second << ')'; return os;
}
void dbg_out() {
    cerr << endl;
}
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {cerr << ' ' << H; dbg_out(T...);}
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef long double ld;
#define all(x) (x).begin(),(x).end()
#define rep(i, a, b) for (int i = (a); i <= (b); (i)++)
#define rrep(i, a, b) for (int i = (a); i >= (b); (i)--)
#define deb(x) cout << #x << ": " << x << endl
#define deb2(x, y) cout << #x << ": " << x << "  " << #y << ": " << y << endl

int justLarge(int x, vector<ll> &arr) {
    int hi = arr.size() - 1, lo = 0, mid = 0, ans = arr.size();
    while (lo <= hi) {
        mid = lo + (hi - lo) / 2;
        if (arr[mid] <= x) {
            lo = mid + 1;
        }
        else {
            ans = mid;
            hi = mid - 1;
        }
    }
    return ans;
}
void solve(ll N, ll M) {
    ll cnt = 0, extra = 0;
    ll lim = 0;

    if (N > M) {
        lim = M;
        extra += (N - M) * (M);
        ll nums = N - M - 1;
        extra += (nums) * (nums + 1) / 2;
    }
    else {
        lim = N;
    }

    ll low = INT_MAX, hi = INT_MIN;
    unordered_map<ll, vector<ll>>possible;

    for (int i = 2; i <= lim; i++) {
        ll F = M - M % i;
        low = min(low, F);
        hi = max(hi, F);
        possible[F].push_back(i);
    }


    for (ll i = 2; i <= lim; i++) {
        ll searchAfter = (low / i) * i;
        for (int j = searchAfter; j <= hi; j += i) {
            ll index =  j;
            if (possible.find(index) != possible.end())
                cnt += possible[index].size() - justLarge(i, possible[index]);
        }
    }
    cnt += extra + lim - 1;
    cout << cnt << endl;
}

int main() {
    clock_t begin = clock();

    int tt;
    cin >> tt;
    while (tt--) {
        int N, M;
        cin >> N >> M;
        solve(N, M);
    }


#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
}
