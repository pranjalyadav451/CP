#include<bits/stdc++.h>
using namespace std;




bitset<1000>visited; set<pair<int, int>>s;
class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {

        visited.reset();
        s.clear();

        s.insert({ 0, 0 });
        int node, weight, ans = 0;

        while (s.empty() == false) {
            weight = s.begin()->first, node = s.begin()->second;
            s.erase(s.begin());
            if (visited[node]) continue;
            visited[node] = true;
            ans += weight;

            for (auto a : adj[node]) {
                s.insert({ a[1], a[0] });
            }
        }
        return ans;

    }
};



int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}
