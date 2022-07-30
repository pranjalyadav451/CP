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



/**
 * Segment Tree by Sanket Singh
 * Source -: https://www.youtube.com/watch?v=oOufBRAEnUA&ab_channel=CodeChef
 *

 * Properties of Segment Tree
    * It is a binary tree.
    * Type of Binary Tree - Full
    * * What is a full binary tree ?
    *   * A binary tree in which every node has exactly either 2 or 0 children.
    * * Heap is a complete binary tree but segment tree is a 'full' binary tree.
    *
*/

class Segment_Tree {
public:
    static const ll INF = 1e18;
    long long N;
    vector<ll> arr;
    vector<ll> tree;
private:
    void build(ll node, ll start, ll end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        ll mid = (start + end) >> 1LL,
           left_child = (node << 1LL),
           right_child = (left_child | 1LL);

        build(left_child, start, mid);
        build(right_child, mid + 1, end);
        tree[node] = min(tree[left_child], tree[right_child]);
    }

    // point update
    void update(ll node, ll idx, long long val, ll start, ll end) {
        if (start == end) {
            tree[node] = arr[start] = val;
            return;
        }

        ll mid = (start + end) >> 1LL,
           left_child = (node << 1LL),
           right_child = (left_child | 1LL);

        if (idx <= mid) update(left_child, idx, val, start, mid);
        else update(right_child, idx, val, mid + 1, end);
        tree[node] = min(tree[left_child], tree[right_child]);
    }
    long long query(ll node, ll q_start, ll q_end, ll start, ll end) {
        if (end < q_start or start > q_end) return INF;
        if (q_start <= start and q_end >= end) {
            return tree[node];
        }

        ll mid = (start + end) >> 1LL,
           left_child = (node << 1LL),
           right_child = (left_child | 1LL);

        ll get_from_left = query(left_child, q_start, q_end, start, mid);
        ll get_from_right = query(right_child, q_start, q_end, mid + 1, end);

        return min(get_from_right, get_from_left);
    }
public:
    Segment_Tree(vll &elements, ll number_ele) {
        const ll INF = 1e18;
        this->N = number_ele;
        arr = elements;
        tree.assign(4 * N, INF);
        build(1, 0, N - 1);
    }
    long long find_query(ll start, ll end) {
        assert(start <= end);
        return query(1, start, end, 0, N - 1);
    }
    void update_idx(ll idx, ll val) {
        assert(idx >= 0 and idx < N);
        update(1, idx, val, 0, N - 1);
    }
};

void solve() {
    ll n, q; in(n, q);
    vll arr(n); in_arr(n, arr);

    Segment_Tree seg (arr, n);

    while (q--) {
        char type;
        int a, b; in(type, a, b);
        if (type == 'q') {
            ll ans = seg.find_query(a - 1, b - 1);
            cout << ans << endl;
        }
        else if (type == 'u') {
            seg.update_idx(a - 1, b);
        }
    }
}
int main() {
    solve();
}