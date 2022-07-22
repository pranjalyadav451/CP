#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define deb(x) cout << #x << " => " << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

#define MOD 1000000007
using namespace std;
string solve(int a[], int n, int k)
{
    int ntsolve = 0;
    int maxa = -20;
    bool slow = false;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == -1)
            ntsolve++;
        if (a[i] > k)
            slow = true;
        maxa = max(maxa, a[i]);
    }
    // deb(ntsolve);
    // deb(ceil((float)n/2));
    if (n - ntsolve < ceil((float)n / 2))
        return "Rejected";
    else if (slow == true)
        return "too slow";
    else if (maxa <= 1 and ntsolve==0)
        return "bot";
    else
        return "accepted";
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
        int n;
        cin >> n;
        int k;
        cin >> k;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        cout << solve(a, n, k) << endl;
    }
}
