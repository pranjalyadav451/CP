#include <bits/stdc++.h>
#include <vcruntime_string.h>
using namespace std;


class Solution {
public:
    int distinct(vector<vector<int>> arr, int n) {
        map<int, int> cnt;
        set<int>visited;
        for (int i = 0; i < n; i++) {
            visited.clear();
            for (int j = 0; j < n; j++) {
                if (visited.count(arr[i][j]) == 0) {
                    visited.insert(arr[i][j]);
                    cnt[arr[i][j]]++;
                }
            }
        }
        int ans = 0;
        for (auto a : cnt) {
            if (a.second == n) ans++;
        }
        return ans;
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> M(N, vector<int>(N, 0));
        for (int i = 0; i < N * N; i++)
            cin >> M[i / N][i % N];

        Solution ob;
        cout << ob.distinct(M, N) << "\n";
    }
    return 0;
}
