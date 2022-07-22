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
ll solve(ll n, ll k)
{
    if (n == 1 || k == 1)
        return k;
    if (n > k)
    {
        if (n % k == 0)
            return 1;
        else
            return 2;
    }
    else if (k >= n)
    {
        if (k % n == 0)
            return k / n;
        else
            return k / n + 1;
    }
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
        ll n;
        ll k;
        cin >> n;
        cin >> k;
        cout << solve(n, k) << endl;
    }
}