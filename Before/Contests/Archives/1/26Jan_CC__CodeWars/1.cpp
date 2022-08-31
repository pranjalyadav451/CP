#include <bits/stdc++.h>
#define ll long long
#define vec vector
#define MOD 1000000007
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define trav(a, x) for (auto &a : x)
#define fo(i, n) for (int i = 0; i < n; i++)
#define deb(x) cout << #x << " => " << x << endl
#define deb2(x, y) cout << #x << "=> " << x << "," << #y << "=" << y << endl

using namespace std;
int a[long(1e7) + 1];
void solve()
{
    int count = 0;
    int n = 0;
    for (int i = 0; i <= 1e7; i++)
    {
        n = i;
        while (n)
        {
            if (n % 10 == 7)
            {
                count++;
            }
            n /= 10;
        }
        a[i] = count;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int testCase;
    cin >> testCase;
    solve();
    while (testCase--)
    {
        // int n;
        // cin >> n;
        int left, right;
        cin >> left >> right;
        cout << abs(a[right] - a[left - 1]) << endl;
    }
}