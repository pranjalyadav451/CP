#include<bits/stdc++.h>
#include <utility>
using namespace std;

/***
 ! ...................
 ? How does this work.
 * Ans : Same logic as DFS, i.e. if a visited node other than the parent node is being
 * visited again, then the graph has cycles.
*/


class Solution {
public:
	bool visited[10001] ;
	bool bfs_check(int node, vector<int> adj[]) {
		queue<pair<int, int>> q;
		q.push({node, -1});
		visited[node] = true;

		while (q.empty() == false) {
			auto a = q.front();
			q.pop();
			for (int ele : adj[a.first]) {

				if (ele == a.second) continue;

				if (visited[ele]) return true;
				else {
					visited[ele] = true;
					q.push({ele, a.first});
				}
			}
		}
		return false;
	}

	bool isCycle(int V, vector<int>adj[])
	{
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < V; i++) {
			if (visited[i] == false) {
				if (bfs_check(i, adj))
					return true;
			}
		}
		return false;
	}
};

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for (int i = 0; i < E; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if (ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}

/**
 * BFS - visiting the adjacent nodes.
 * If any of the adjacent nodes to a given unvisited node are visited then the graph contains a cycle.
*/