#include <bits/stdc++.h>
#include <limits.h>
#include <utility>
#define deb(x) cout << #x << ": " << x << endl
#define deb2(x, y) cout << #x << ": " << x << ", " << #y << ": " << y << endl
using namespace std;


const int N = 1e5 + 10;
int indegree[N];
class Solution {
public:
    vector<int> topoSort(int V, vector<int> adj[]) {
        memset(indegree, 0, sizeof(indegree));
        queue<int> q;
        vector<int>res;

        for (int i = 0; i < V; i++) {
            for (int a : adj[i]) {
                indegree[a]++;
            }
        }

        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        int temp = 0;
        /**
        * Top sort is only valid for directed acyclic graphs, that's why we do not need a visited array to keep track of elements' visited state.
        */
        while (q.empty() == false) {
            temp = q.front();
            q.pop();
            res.push_back(temp);
            for (int a : adj[temp]) {
                indegree[a]--;
                if (indegree[a] == 0)
                    q.push(a);
            }
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