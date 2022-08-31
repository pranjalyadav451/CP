#include <bits/stdc++.h>
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

using namespace std;

ll solve(vector<pair<ll, ll>> items, ll N, ll W)
{
    int wt ,val;

    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll N, W;
    cin >> N >> W;

    vector<pair<ll, ll>> items(N);

    for (ll i = 0; i < N; i++)
    {
        ll wt, val;
        cin >> wt >> val;
        items[i] = {wt, val};
    }

    cout << solve(items, N, W) << endl;
}