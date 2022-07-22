/**
 * Kruskal's and Prim's Algo works with
 	- negative edges.
 	- negative cycles.
 * Dijsktra's Algorithms
*/
#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	// vector<pair<int, int>> edgeList;
	set<pair<int, int>>edges;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		// edgeList.push_back({u, v});
		edges.insert({min(u, v), max(u, v)});
	}
	int Q;
	cin >> Q;
	set<pair<int, int>> dup_edges = edges;
	vector<pair<int, int>> queries;

	while (Q--) {
		int u, v;
		cin >> u >> v;
		/**
		 * If there is an edge between u and v remove it.
		*/
		queries.push_back({u, v});
		dup_edges.erase({min(u, v), max(u, v)});
	}
}