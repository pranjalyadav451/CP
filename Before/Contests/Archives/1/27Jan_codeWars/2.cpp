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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        int n;
        cin >> n;

        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll left, right;
        ll ans = 1;
        cin >> left >> right;
        bool flag = true;
        for (int i = left; i < right; i++)
        {
            if (a[i] != 0)
            {
                ans = ans * a[i] % MOD;
            }
            else
            {
                flag = false;
                break;
            }
        }
        if (flag == false)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }
}