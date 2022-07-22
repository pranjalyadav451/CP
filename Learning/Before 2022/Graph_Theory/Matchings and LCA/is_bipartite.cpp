#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	static const int N = 1e5 + 5;
	int color[N];

	bool bfs(int src, vector<int> adj[])
	{
		queue<int>q;
		q.push(src);

		color[src] = 0;

		int temp = -1;
		while (q.empty() == false)
		{
			temp = q.front();
			q.pop();
			for (int a : adj[temp])
			{
				if (color[a] == -1)
				{
					color[a] = 1 - color[temp];
					q.push(temp);
				}
				else if (color[a] == color[temp])
					return false;
			}
		}
		return true;
	}

	bool isBipartite(int V, vector<int>adj[])
	{
		memset(color, -1, sizeof(color));
		for (int i = 0; i < V; i++)
		{
			if (color[i] == -1) {
				if (bfs(i, adj) == false)
					return false;
			}
		}
		return true;
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
		bool ans = obj.isBipartite(V, adj);
		if (ans)cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}