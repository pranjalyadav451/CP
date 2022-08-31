#include <bits/stdc++.h>
using namespace std;
void dfs(int node, stack<int> &st, vector<int> &vis, vector<int> adj[]) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfs(it, st, vis, adj);
        }
    }

    st.push(node);
}
void revDfs(int node, vector<int> &vis, vector<int> transpose[]) {
    cout << node << " ";
    vis[node] = 1;
    for (auto it : transpose[node]) {
        if (!vis[it]) {
            revDfs(it, vis, transpose);
        }
    }
}

void print(vector<int> transpose[], int n) {
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (int a : transpose[i]) {
            cout << a << " ";
        }
        cout << endl;
    }
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    stack<int> st;
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, st, vis, adj);
        }
    }

    vector<int> transpose[n];

    for (int i = 0; i < n; i++) {
        vis[i] = 0;
        for (auto it : adj[i]) {
            transpose[it].push_back(i);
        }
    }

    //
    cout << "Original: " << endl;
    print(adj, n);
    cout << "Transpose: " << endl;
    print(transpose, n);
    cout << endl;
    //

    vector<int>tops;
    while (!st.empty()) {
        int node = st.top();
        tops.push_back(node);
        st.pop();
        if (!vis[node]) {
            cout << "SCC: ";
            revDfs(node, vis, transpose);
            cout << endl;
        }
    }

    reverse(tops.begin(), tops.end());
    cout << "Toposort: " << endl;
    for (int i : tops) {
        cout << i << " ";
    }
    cout << endl;


    return 0;
}

/*
5 5
0 1
1 2
2 0
1 3
3 4
*/