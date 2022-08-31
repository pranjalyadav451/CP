// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:

    bool visited[10001] = {false};
    vector<int>res;

    void dfs(int V, vector<int>adj[], int i = 0)
    {
        if (visited[i] == false)
        {
            res.push_back(i);
            visited[i] = true;
            for (int a : adj[i])
            {
                dfs(V, adj, a);
            }
        }
        return ;
    }


    vector<int>dfsOfGraph(int V, vector<int> adj[])
    {
        res.clear();
        memset(visited, 0, sizeof(visited));
        dfs(V, adj);
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends