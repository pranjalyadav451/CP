#include <bits/stdc++.h>
using namespace std;




class Solution {
public:
    void dfs(vector<int> adj[], bool visited[], stack<int> &tops, int i = 0) {
        if (visited[i])
            return;
        visited[i] = true;
        for (int a : adj[i]) {
            if (visited[a] == false) {
                dfs(adj, visited, tops, a);
            }
        }
        tops.push(i);
    }
    vector<int> topoSort(int V, vector<int> adj[]) {
        bool visited[V] = {};
        stack<int>tops;
        for (int i = 0; i < V; i++) {
            if (visited[i] == false) {
                dfs(adj, visited, tops, i);
            }
        }
        vector<int>res;
        while (tops.empty() == false) {
            res.push_back(tops.top());
            tops.pop();
        }
        return res;
    }
};


/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }

    return 0;
}