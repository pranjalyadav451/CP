#include <bits/stdc++.h>
using i64 = long long;
constexpr int P = 1000000007;
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n), c(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            b[i]--;
        }
        for (int i = 0; i < n; i++) {
            c[a[i]] = b[i];
        }
        int ans = 1;
        vector<int> vis(n);
        for (int i = 0; i < n; i++) {
            if (vis[i]) {
                continue;
            }
            int j = i;
            while (!vis[j]) {
                vis[j] = 1;
                j = c[j];
            }
            ans = 2 * ans % P;
        }
        cout << ans << "\n";
    }
    return 0;
}
