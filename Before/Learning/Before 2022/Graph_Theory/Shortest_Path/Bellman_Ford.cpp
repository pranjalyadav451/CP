#include<bits/stdc++.h>
using namespace std;


const int inf = 1e8;
class Solution {
public:
    /*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {

        vector<int>res(V, inf);
        res[S] = 0;
        bool any = false;
        int E = adj.size();

        for (int i = 0; i < V - 1; i++) {
            any = false;

            for (int i = 0; i < E; i++) {
                vector<int> edge = adj[i];
                if (res[edge[0]] != inf and res[edge[1]] > res[edge[0]] + edge[2]) {
                    any = true;
                    res[edge[1]] = res[edge[0]] + edge[2];
                }
            }

            if (not any)
                return res;
        }
        return res;
    }
};




int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj;
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1;
            t1.push_back(u);
            t1.push_back(v);
            t1.push_back(w);
            adj.push_back(t1);
        }
        int S;
        cin >> S;

        Solution obj;
        vector<int> res = obj.bellman_ford(V, adj, S);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
