#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define dbg(x) cout << #x << ": " << x << endl
#define dbgg(x, y) cout << #x << ": " << x << "," << #y << ": " << y << endl

/*
 * Given a 'n x m' grid with blocked and unblocked cells,find the number of ways
 * to move from top-left to bottom-right.
 * **/

ll count(vector<string > &arr, int n, int m) {
    vector<vector<int>> grid(n, vector<int>(m, 0));
    // Initialization
    for (int i = 0; i < n; i++) {
        if (arr[i][0] != '#')
            grid[i][0] = 1;
        else break;
    }
    for (int i = 0; i < m; i++) {
        if (arr[0][i] != '#')
            grid[0][i] = 1;
        else break;
    }

    /* Building up the solution */
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            grid[i][j] = 0;
            if (arr[i][j] != '#')
                grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
        }
    }
    ll ans = grid[n - 1][m - 1];

    // for(int i = 0 ; i < n ;i++){
    //     for(int j = 0 ;j < m;j++){
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string >arr(n, string(m, '_'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    ll ans = count(arr, n, m);
    dbg(ans);
}