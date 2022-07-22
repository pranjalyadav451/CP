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
typedef vector<vector<int>>                 vvi;
typedef vector<pll>                         vpl;
typedef pair<int, int>                      pii;
typedef long double                         ld;
typedef vector<int>                          vii;

#define all(x)                              (x).begin(),(x).end()
#define REP(i, a, b)                        for (int i = (a); i <= (b); (i)++)
#define RREP(i, a, b)                       for (int i = (a); i >= (b); (i)--)
#define dbg(x)                              cout << #x << ": " << x << endl
#define dbgg(x, y)                          cout << #x << ": " << x << "  " << #y << ": " << y << endl
#define log_all(...)                        logger(#__VA_ARGS__, __VA_ARGS__)

bool visited[101][101];
vector<pair<int, int>> moves = {{1, 0}, { -1, 0}, {0, 1}, {0, -1}, { -1, -1}, {1, 1}, { -1, 1}, {1, -1}};

int bfs(vector<vector<int>> &A, int i , int j) {
    int N = A.size() , M = A[0].size();
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = 1;

    auto isvalid = [] (int i, int j, int N , int M) {
        return i < N and i >= 0 and j <M and j >= 0;
    };
    int nodes = 0;
    while (q.empty() == false) {
        pair<int, int> temp = q.front();
        // cout << temp << endl;
        q.pop();
        for (auto move : moves) {
            pair<int, int> cc = {move.first + temp.first, move.second + temp.second};
            if (isvalid(cc.first , cc.second, N , M) == false or visited[cc.first][cc.second] or A[cc.first][cc.second] == 0)
                continue;
            visited[cc.first][cc.second] = 1;
            q.push(cc);
        }
        nodes++;
    }
    return nodes;
}

int region(vector<vector<int> > &A) {
    // we can move right , left , top , and bottom

    memset(visited, 0, sizeof(visited));
    int N = A.size(), M = A[0].size() , mx = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0 ; j < M; j++) {
            if (A[i][j] == 1 and visited[i][j] == false) {
                mx = max(mx, bfs(A, i, j));
            }
        }
    }
    return mx;
}


void solve() {
    int N , M;
    cin >> N >> M;
    vvi arr(N, vii(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    int ans = region(arr);
    cout << ans << endl;
}

int main() {
    int tt = 1;
    // cin >> tt; // "UN-COMMENT THIS FOR TESTCASES"
    while (tt--) {
        solve();
    }
}


