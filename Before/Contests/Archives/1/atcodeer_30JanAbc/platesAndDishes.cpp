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
int solve(vector<pair<int, int>> &con, vector<pair<int, int>> &choice)
{

    int m = con.size();
    int k = choice.size();
    map<int, int> f;

    for (int i = 0; i < m; i++)
    {
        if (f.count(con[i].first) == 0)
            f[con[i].first] = 1;
        else
        {
            f[con[i].first]++;
        }

        if (f.count(con[i].second) == 0)
            f[con[i].second] = 1;
        else if
        {
            f[con[i].second]++;
        }
    }
    for (int i = 0; i < k; i++)
    {
        if (f[choice[i].first] > f[choice[i].second])
        {
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int m;
    cin >> m;

    vector<pair<int, int>> con(m);
    ll p1,
        llp2;
    for (int i = 0; i < m; i++)
    {
        cin >> p1 >> p2;
        con[i] = mp(p1, p2);
    }
    int k;
    cin >> k;
    vector<pair<int, int>> choice(k);
    {
        cin >> p1 >> p2;
        choice[i] = mp(p1, p2);
    }

    cout << solve(con, choice) << endl;
}
