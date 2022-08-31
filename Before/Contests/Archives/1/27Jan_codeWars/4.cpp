#include <bits/stdc++.h>
#define ll long long
#define vec vector
#define MOD 1000000007
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

#define sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define trav(a, x) for (auto &a : x)
#define fo(i, n) for (ll i = 0; i < n; i++)
#define deb(x) cout << #x << " => " << x << endl
#define deb2(x, y) cout << #x << "=> " << x << "," << #y << "=" << y << endl

using namespace std;
bool comp(std::pair<ll, ll> a, std::pair<ll, ll> b)
{
    ll mina = min(a.f, a.s);
    ll minb = min(b.f, b.s);
    return mina < minb;
}
std::pair<ll,ll> solve(ll arr[], ll n, ll x)
{
    unordered_set<ll> toSearch;
    vec<pair<ll, ll>> res;
    for (ll i = 0; i < n; i++)
    {
        if (toSearch.count(x ^ arr[i]) == 0)
            toSearch.insert(arr[i]);
        else
        {
            res.push_back(make_pair(arr[i], arr[i] ^ x));
        }
    }
    return *min_element(all(res), comp);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll testCase;
    cin >> testCase;
    while (testCase--)
    {
        ll n;
        ll x;
        cin>>n>>x;
        ll a[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        pair<ll,ll>result = solve(a,n,x);
        ll mini = min(result.f,result.s);
        ll maxi = max(result.f,result.s);
        cout<<mini<<" "<<maxi<<endl;
    }
}