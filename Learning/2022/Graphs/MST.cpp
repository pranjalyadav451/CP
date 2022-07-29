//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

typedef pair<int, int> pii;
class Solution
{


public:
    //Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        const int INF = 1e9;
        int S = 0;
        int total = 0;

        set<pii> nodes;
        vector<int> visited(V, 0);

        nodes.insert({0, 0});

        while (nodes.size()) {
            auto now = *nodes.begin();
            nodes.erase(nodes.begin());
            int weight = now.first, to = now.second;

            if (visited[to]) continue;
            visited[to] = true;
            total += weight;

            for (auto near : adj[to]) {
                if (!visited[near[0]]) nodes.insert({near[1], near[0]});
            }
        }
        return total;
    }
};

//{ Driver Code Starts.


int main()
{
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


// } Driver Code Ends