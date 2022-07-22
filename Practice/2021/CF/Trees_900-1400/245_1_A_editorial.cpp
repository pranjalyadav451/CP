#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<int>adj[100001];
int toChange[100001];
vector<int>ans;
void dfs(int node, int parent, int odd, int even, int depth) {
    if (depth % 2 == 0) {
        if (odd != toChange[node]) {
            odd ^= 1;
            ans.push_back(node);
        }
    }

    else {
        if (even != toChange[node]) {
            even ^= 1;
            ans.push_back(node);
        }
    }
    for (auto cur : adj[node]) {
        if (cur == parent) continue;
        dfs(cur, node, odd, even, depth + 1);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        cin >> toChange[i];
    }
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        toChange[i] ^= x;
    }
    dfs(1, 0, 0, 0, 0);
    cout << ans.size() << '\n';
    for (auto cur : ans) {
        cout << cur << '\n';
    }
}
