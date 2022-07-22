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
ll sol(ll a[], int n)
{
    ll count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] != a[i + 1] and i != 0 and a[i] == a[i - 1])
            count += 2;
        else if (i != 0 and a[i] != a[i - 1] and a[i] != a[i + 1])
        {
            count += 1;
        }
        else if (i == 0 and a[i] != a[i + 1])
            count += 1;
    }
    return count;
    // this question is really asking number of consecutive mismatchs in the array
}
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
        ll a[n];
        fo(i, n)
        {
            cin >> a[i];
        }
        cout << sol(a, n) << endl;
    }
}