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
string damage(vector<pair<int, int>> &sp, ll s, ll d)
{
    bool flag = false;
    for (int i = 0; i < sp.size(); i++)
    {
        if (sp[i].first < s and sp[i].second > d)
            {
                flag = true;
                break;
            }
    }

    if (flag == true)
    {
        return "Yes";
    }
    else
    {
        return "No";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        ll n, s, d;
        cin >> n >> s >> d;

        ll t, p;
        vector<pair<int, int>> sp(n);
        for (int i = 0; i < n; i++)
        {
            cin >> t;
            cin >> p;
            sp[i] = mp(t, p);
        }

        cout << damage(sp, s, d)<<endl;
    }
}
