#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } int __fastio = fastio();

/** *** GLOBALS *** **/

const int mxn = 2e5;
const int inf = 1e9;
vector<int> adj[mxn];

void printPath(vector<int> &parent, int j)
{
	if (parent[j] == -1)
		return;
	printPath(parent, parent[j]);
	cout << j << " ";
}

/** *** FUNCTIONS *** **/
void dijkstra(int V, int S, vector<int> &parent) {

	vector<int>res(V + 1, inf);
	parent.assign(V + 1, -1);
	vector<bool> visited(V + 1, false);

	set<pair<int, int>> s;
	s.insert({ 0, S });

	while (s.empty() == false) {

		int d = s.begin()->first, node = s.begin()->second;
		s.erase(s.begin());

		if (visited[node]) continue;
		visited[node] = true;
		res[node] = d;

		for (auto tmp : adj[node]) {
			if (!visited[tmp]) {
				s.insert({ d + 1, tmp});
				if (res[tmp] > 1 + d) {
					parent[tmp] = node;
					res[tmp] = d + 1;
				}
			}
		}
	}
}

void solve(int nodes, int m, int n, int s) {
	vector<int> parent;
	dijkstra(nodes, s, parent);
	vector<int> to_print = {1, n, m*n - n + 1, m * n};
	for (int a : to_print) {
		cout << s << " ";
		printPath(parent, a);
		cout << endl;
	}
}

int main() {
	/** *** INPUT *** **/
	int m, n, s;
	cin >> m >> n >> s;
	int nodes = m * n;

	/** Input **/
	for (int i = 1; i <= nodes; i++) {
		int node ;
		cin >> node;
		vector<int> can(8);
		for (int i = 0; i < 8; i++) {
			cin >> can[i];
		}
		for (int i = 0; i < 8; i++) {
			if (can[i] == 1) {
				switch (i + 1) {
				case 1:
					adj[node].push_back({node - n});
					break;
				case 2:
					adj[node].push_back({node - n + 1});
					break;
				case 3:
					adj[node].push_back(node + 1);
					break;
				case 4:
					adj[node].push_back(node + n + 1);
					break;
				case 5:
					adj[node].push_back(node + n);
					break;
				case 6:
					adj[node].push_back(node + n - 1);
					break;
				case 7:
					adj[node].push_back(node - 1);
					break;
				case 8:
					adj[node].push_back(node - n - 1);
					break;
				}
			}
		}
	}

	/** Solution **/
	solve(nodes, m, n, s);
}
