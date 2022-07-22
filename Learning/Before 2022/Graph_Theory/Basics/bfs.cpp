// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    vector<int>res;
    bool visited[10001];
    void bfs(int V, vector<int> adj[])
    {
        queue<int>q;
        q.push(0);
        int i = 0;
        visited[0] = true;

        while (q.empty() == false)
        {
            i = q.front();
            res.push_back(i);
            q.pop();

            for (int a : adj[i])
            {
                if (visited[a] == false)
                {
                    visited[a] = true;
                    q.push(a);
                }
            }
        }
    }
    vector<int>bfsOfGraph(int V, vector<int> adj[])
    {
        res.clear();
        memset(visited, 0, sizeof(visited));
        bfs(V, adj);
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
            //      adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends