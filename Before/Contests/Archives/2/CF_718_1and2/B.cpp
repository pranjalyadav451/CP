#include <bits/stdc++.h>
#define ll long long
#define vec vector
#define MOD 1000000007
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ff first
#define ss second
#define read(x) cin >> x
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define rev(i, a, b) for (int i = (a); i >= (b); i--)
#define deb(x) cout << #x << ": " << x << endl
#define deb2(x, y) cout << #x << ": " << x << ", " << #y << ": " << y << endl

using namespace std;
bool checked[101][101];

void solve()
{
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    rep(i, 0, n - 1)
    {
        rep(j, 0, m - 1)
        {
            cin >> arr[i][j];
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
}