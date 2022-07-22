#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

void dfs(vector<int> adj[], stack<int> &tops, bool visited[], int i = 0) {
    if (visited[i] == 1)
        return;
    visited[i] = 1;

    for (int a : adj[i]) {
        if (visited[a] == false) {
            dfs(adj, tops, visited, a);
        }
    }
    tops.push(i);
}
void kosaraju(vector<int> transpose[], vector<int> adj[], int n) {
    stack<int>tops;
    bool visited[n];
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < n; i++) {
        if (visited[i] == false) {
            dfs(adj, tops, visited, i);
        }
    }

    // Getting the topologically sorted graph
    vector<int> sorted;

    while (tops.empty() == false) {
        sorted.push_back(tops.top());
        tops.pop();
    }
    // reverse(sorted.begin(), sorted.end());
    cout << "Toposort: " << endl;
    for (int i : sorted) {
        cout << i << " ";
    }
    cout << endl;

    // Traversing the transpose of the graph in order of the topological sorting.
    memset(visited, 0, sizeof(visited));
    for (int a : sorted) {
        if (visited[a] == false) {
            dfs(transpose, tops, visited, a);
            cout << "SCC: ";
            while (tops.empty() == false) {
                cout << tops.top() << " ";
                tops.pop();
            }
            cout << endl;
        }
    }
}
void print_graph(vector<int> transpose[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << i << ": ";
        for (int a : transpose[i]) {
            cout << a << " ";
        }
        cout << endl;
    }
}
vector<int>hello;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    vector<int>transpose[n];

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        transpose[v].push_back(u);
        adj[u].push_back(v);
    }

    //
    cout << "Original: " << endl;
    print_graph(adj, n);
    cout << "Transpose: " << endl;
    print_graph(transpose, n);
    cout << endl;
    //
    kosaraju(transpose, adj, n);
}
/**
5 5
0 1
1 2
2 0
1 3
3 4
*/