#include <bits/stdc++.h>
#define ll long long
#define vii vector<int>
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
ll nC2(ll n)
{
    return n>=2?n * (n - 1) / 2:0;
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
        int a, b, k;
        cin >> a >> b >> k;
        vii boys(a,0);
        vii girls(b,0);
        vector<pair<int, int>> pairs(k);
        // int temp = k;
        fo(i, k)
                cin >>
            pairs[i].f;
        fo(i, k)
                cin >>
            pairs[i].s;

        // I have taken the input
        // Now what do I have to do?
        ll ans = nC2(k);

        for (auto &element : pairs)
        {
            element.f--;
            element.s--;
            boys[element.f]++;
            girls[element.s]++;
        }
        fo(i, a) ans -= nC2(boys[i]);
        fo(i, b) ans -= nC2(girls[i]);
        cout << ans << endl;
    }
}