#include <bits/stdc++.h>
//didn't completely get this I don't know why
using namespace std;
using ll = long long;
using ld = long double;

void solve()
{
    int A, B, k;
    cin >> A >> B >> k;
    vector<int> a(A), b(B);
    vector<pair<int, int>> edges(k);
    for (auto &[x, y] : edges)
    {
        cin >> x;
    }
    for (auto &[x, y] : edges)
    {
        cin >> y;
    }
    for (auto &[x, y] : edges)
    {
        x--;
        y--;
        a[x]++;
        b[y]++;
    }
    ll ans = 0;
    for (auto &[x, y] : edges)
    {
        // cout << "degree - boys" << a[x] << endl;
        // cout << "edges being blocked _>" << +a[x] + b[y] - 1 << endl;
        ans += k - a[x] - b[y] + 1;
        cout << "ans ->" << ans << endl;
    }
    cout << ans / 2 << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}