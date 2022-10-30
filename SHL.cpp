#include<bits/stdc++.h>
using namespace std;


vector<pair<int, int>> moves = { {-1,0},{1,0},{0,1},{0,-1} };
bool is_valid(int i, int j, int m, int n) {
    return i >= 0 && i < m &&j >= 0 && j < n;
}

vector<vector<int>> closest_distance(vector<vector<int>> arr) {
    int m = arr.size(), n = arr[0].size();

    vector<vector<int>> ans(m, vector<int>(n, INT_MAX));

    queue<pair<int, int>> nodes;
    vector<vector<bool>> visited(m, vector<bool>(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 1) {
                nodes.push({ i,j });
                visited[i][j] = true;
                ans[i][j] = 0;
            }
        }
    }

    while (nodes.size()) {
        auto now = nodes.front();
        nodes.pop();
        for (auto move : moves) {
            int x = now.first + move.first, y = now.second + move.second;
            if (is_valid(x, y, m, n) and !visited[x][y]) {
                visited[x][y] = true;
                ans[x][y] = ans[now.first][now.second] + 1;
            }
        }
    }
    return ans;
}

int main() {
    int m, n;
    cin >> n >> m;

    vector<vector<int>> arr(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
}