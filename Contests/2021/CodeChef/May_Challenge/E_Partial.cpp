#include <bits/stdc++.h>
#include <cstdlib>
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
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
    cerr << ' ' << H; dbg_out(T...);
}
#ifdef LOCAL
#define pp(...) cerr << "\t[" << #__VA_ARGS__ << "]:\t", dbg_out(__VA_ARGS__)
#define ppp(x) cerr << x << "\n"
#else
#define pp(...)
#define ppp(...)
#endif
template<class Fun> class y_combinator_result {
Fun fun_; public: template<class T> explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {} template<class ...Args> decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
}
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
#define yc y_combinator

typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef long double ld;
#define all(x) (x).begin(),(x).end()
#define rep(i, a, b) for (int i = (a); i <= (b); (i)++)
#define rrep(i, a, b) for (int i = (a); i >= (b); (i)--)
#define deb(x) cout << #x << ": " << x << endl
#define deb2(x, y) cout << #x << ": " << x << "  " << #y << ": " << y << endl

ll brute(ll N, ll M) {
    ll cnt = 0;
    vector<vector<int>> numbers;
    vector<int> temp;

    for (int i = 1; i <= N; i++) {
        temp.clear();
        for (int j = i + 1; j <= N; j++) {
            ll F = M % i, S = (M % j);
            if ((S - F) % i == 0) {
                cnt++;
                temp.push_back(j);
            }
        }
        numbers.push_back(temp);
    }

    // for (int i = 0; i < N; i++) {
    // 	cout << "i : " << i + 1 << "\t" << numbers[i] << endl;
    // 	cnt += numbers[i].size();
    // }

    // cout << endl;

    return cnt;
}

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


void optimal(ll N, ll M) {

    ll count = 0;

    map<ll, vector<ll> > mod_b;

    for (int b = 1; b <= N; b++) {
        mod_b[M % b].push_back(b);
    }
    for (int i = 1; i <= N; i++) {

        ll F = M % i;
        // deb(i);
        for (auto ele : mod_b) {
            if ((abs(F - ele.first)) % i == 0) {
                int ele_greater = ele.second.size() - justLarge(i, ele.second);
                // deb(F);
                // deb(ele.second);
                // deb(ele_greater);
                count += ele_greater;
                // deb(count);
                // cout << "----------" << endl;
            }
        }
        // cout << "=========================================" << endl;
    }
    cout << count << endl;
}


void run_case(ll N, ll M) {

}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        ll N, M;
        cin >> N >> M;

        // cout << brute(N, M) << endl;
        optimal(N, M);
    }
}
