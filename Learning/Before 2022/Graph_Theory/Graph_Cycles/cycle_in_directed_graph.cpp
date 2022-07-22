#include<bits/stdc++.h>
using namespace std;
/**
	# This is a good problem.
	# TODO : Try to prove it's correctness. [Done]
*/
#define debug(x) cout<< #x << ": "<< x<< " " ;

const int N = 1e5 + 10;
bool visited[N];
bool dfs_visit[N];
class Solution
{
public:
	bool dfs_check(int node , vector<int> adj[]) {
		dfs_visit[node] = visited[node] = true;
		for (int a : adj[node]) {
			/** If the node is NOT visited in any of the previous dfs visits then the node must also not be visited in the current visit till now.**/
			if (visited[a] == false) {
				// debug(visited[a]);
				// debug(dfs_visit[a]);
				// cout << endl;
				if (dfs_check(a, adj))
					return true;
			}
			/** If the node has been visited in the previous dfs visits, we need not do dfs on that node.
				But, we have to check if the node has been visited in the current visit.
				If that's the case we have found a cycle.
			*/
			else {
				if (dfs_visit[a])
					return true;
			}

			/**
				Alternate logic:
				----------------------------
				if(dfs_visit[a])
			    	return true;
			    else if(visited[a]==false){
			        if(dfs_check(a,adj))
			            return true;
			    }
			    ----------------------------
			*/


		}
		dfs_visit[node] = false;
		return false;
	}

	bool isCyclic(int V, vector<int> adj[])
	{
		memset(visited, 0, sizeof(visited));
		memset(dfs_visit, 0, sizeof(dfs_visit));
		for (int i = 0; i < V; i++) {
			if (visited[i] == false) {
				if (dfs_check(i, adj))
					return true;
			}
		}
		return false;
	}
};



int main()
{

	int t;
	cin >> t;
	while (t--)
	{
		int V, E;
		cin >> V >> E;

		vector<int> adj[V];

		for (int i = 0; i < E; i++)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}

		Solution obj;
		cout << obj.isCyclic(V, adj) << "\n";
	}

	return 0;
}

