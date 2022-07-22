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
#define fo(i, n) for (i = 0; i < n; i++)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

using namespace std;

string solve(ll x)
{
    string ans = "";

    if (x > 45)
        return "-1";
    else
    {
        int i = 9;

        while (x > 0)
        {
            if (i < x)
                ans.push_back(i + '0');
            else
            {
                ans.push_back(x + '0');
                i = x;
            }
            x -= i;
            i--;
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
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
        ll x;
        cin >> x;
        cout << solve(x) << endl;
    }
}