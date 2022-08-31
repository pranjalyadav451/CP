#include<bits/stdc++.h>
using namespace std;
int arr[1000][1000];

int solve(int n) {

    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for (int i = n - 1; i >= 1; i--) {
        for (int j = n - 1; j >= 1; j--) {
            if (i == n - 1) {
                dp[i][j] = arr[i][j];
            }
            else {
                dp[i][j] = max(dp[i + 1][j], arr[i][j]);
            }
        }
    }

    for (int i = n - 1; i >= 1; i--) {
        for (int j = n - 1; j >= 1; j--) {
            if (j == n - 1) {
                continue;
            }
            else {
                dp[i][j] = max({ dp[i][j + 1], dp[i][j],arr[i][j] });
            }
        }
    }
    int mx = INT_MIN;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            mx = max(dp[i + 1][j + 1] - arr[i][j], mx);
        }
    }

    return mx;

}


int main() {
    int n;
    cin >> n;
    memset(arr, -1, sizeof(arr));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    cout << solve(n) << endl;
}