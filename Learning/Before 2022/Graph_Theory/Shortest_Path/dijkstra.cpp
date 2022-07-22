#include<bits/stdc++.h>
using namespace std;



bool visited[1001];
class Solution {
public:

	vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
		memset(visited, 0, sizeof(visited));
		vector<int>res(V);

		set<pair<int, int>> s;
		s.insert({ 0, S });

		while (s.empty() == false) {
			int d = s.begin()->first, node = s.begin()->second;
			s.erase(s.begin());
			if (visited[node]) continue;
			visited[node] = true;
			res[node] = d;
			for (auto tmp : adj[node]) {
				s.insert({ tmp[1] + d, tmp[0] });
			}
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
		int S;
		cin >> S;

		Solution obj;
		vector<int> res = obj.dijkstra(V, adj, S);

		for (int i = 0; i < V; i++)
			cout << res[i] << " ";
		cout << endl;
	}

	return 0;
}

