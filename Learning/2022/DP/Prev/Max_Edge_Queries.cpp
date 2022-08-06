#include<bits/stdc++.h>
using namespace std;


typedef vector<pair<int, int>> vpi;

vector<vpi> graph;
#define outt(x,y) cout << #x << " : " << x << " , " << #y << " : " << y << endl

struct lift {
    const int LOG = 20;
    int N;

    vector<int> parent;
    vector<int> depth;
    vector<vector<int>> dp, mx;
    map<pair<int, int>, int> weight;


    void dfs(int node , int pnode) {
        for (auto child : graph[node]) {
            int a = child.first , w = child.second;
            if (a == pnode) continue;

            weight[ {node, a}] = w;
            parent[a] = node;
            depth[a] = depth[node] + 1;

            dfs(a, node);
        }
    }


    lift(int __n) {
        N = __n;
        dp.assign(N + 1, vector<int>(LOG));
        mx = dp;
        parent.assign(N + 1, 1);
        depth.assign(N + 1, 0);

        dfs(1, -1);
        build_ancestor();

        build_max_queries();
    }

    void build_ancestor() {
        for (int i = 0; i < LOG; i++) {
            for (int node = 1; node <= N; node++) {
                if (i == 0) dp[node][i] = parent[node];
                else
                    dp[node][i] = dp[dp[node][i - 1]][i - 1];
            }
        }
    }
    void build_max_queries() {
        for (int i = 0; i < LOG; i++) {
            for (int node = 1; node <= N; node++) {
                if (i == 0)
                    mx[node][i] = weight[ {dp[node][0], node}];
                else
                    mx[node][i] = max(mx[node][i - 1], mx[dp[node][i - 1]][i - 1]);
            }
        }
        /*
        cout << weight.size() << " weight" << endl;
        for(int i=0; i < 5;i++){
          for(int node = 1;node<=N;node++){
            outt(node,i);
            outt(mx[node][i],i);
          }
          cout << endl;
        }
        */
    }
    int get_max(int a, int b) {
        if (depth[b] > depth[a]) swap(a, b);

        /*
        outt(a,b);
        outt(depth[a],depth[b]);
        */

        int diff = depth[a] - depth[b];
        int ans = -1;

        for (int j = LOG - 1; j >= 0; j--) {
            if (diff > 0 and diff & (1 << j)) {
                //       outt(ans,mx[a][j]);
                ans = max(ans, mx[a][j]);
                a = dp[a][j];
                diff -= (1 << j);
            }
        }

        if (a == b) return ans;
        // outt(ans,0);

        for (int j = LOG - 1; j >= 0; j--) {
            if (dp[a][j] != dp[b][j]) {
                //     outt(mx[a][j],mx[b][j]);
                ans = max({ans, mx[a][j], mx[b][j]});
                a = dp[a][j];
                b = dp[b][j];
            }
        }
        ans = max(ans, mx[a][0]);
        return ans;
    }
};


vector<int> max_queries(vector<vector<int> > &A, vector<vector<int> > &B) {
    int N = A.size() + 1;
    graph.assign(N + 1, vpi());

    for (int i = 0; i < A.size(); i++) {
        graph[A[i][0]].push_back({A[i][1], A[i][2]});
        graph[A[i][1]].push_back({A[i][0], A[i][2]});
    }

    vector<int> res;

    lift bin_lift(N);

    for (int i = 0 ; i < B.size(); i++) {
        int mx = bin_lift.get_max(B[i][0], B[i][1]);
        res.push_back(mx);
    }

    return res;
}

void solve() {
    int n , m; cin >> n >> m;
    vector<vector<int>> edges(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> edges[i][j];
        }
    }

    cin >> n >> m;
    vector<vector<int>> queries(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0 ; j < m; j++) {
            cin >> queries[i][j];
        }
    }


    vector<int> ans = max_queries(edges, queries);
    for (auto a : ans) cout << a << " ";
    cout << endl;
}

int main() {
    int tt = 1;
    while (tt--) {
        solve();
    }
}
