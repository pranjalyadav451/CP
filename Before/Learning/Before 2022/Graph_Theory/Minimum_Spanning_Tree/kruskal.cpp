#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e4 + 1;
int parent[N];
int cap[N];

struct edge {
	int u, v, w;
} edges[10000];

bool compare(edge a, edge b) {
	return a.w < b.w;
}

int get_root(int u) {
	if (parent[u] == -1) return u;
	return parent[u] = get_root(parent[u]);
}

void do_union(int v, int u) {
	if (rand() % 2 == 1) {
		parent[u] = v;
		return;
	}
	parent[v] = u;
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> edges[i].u >> edges[i].v >> edges[i].w;
	}

	for (int i = 1; i <= n; i++) {
		parent[i] = -1;
	}

	sort(edges, edges, compare);
	vector<edge>mst;

	ll totalCost = 0;

	cout << "The MST is as follows : " << endl;

	for (int i = 0; i < m; ++i) {
		const edge &e = edges[i];
		int u_root = get_root(e.u), v_root = get_root(e.v);

		if (v_root == u_root) {
			continue;
		}
		do_union(u_root, v_root);
		mst.push_back(e);
		totalCost += e.w;
		cout << e.u << " ---- " << e.v << " weight: " << e.w << endl;

	}
	cout << "The Total Cost of the Spanning Tree is: " << totalCost << endl;

}


/**
 * Sort all the edges in ascending order of their edge weights.
 * If the incoming edge has both the vertices in the same tree in the forest then skip this edge.
 * Else, add the incoming edge to the forest.
*/