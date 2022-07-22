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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt;
    cin >> tt;
    while (tt--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        ll maxa = max(a, max(b, c));
        if (maxa == a and b + c == a)
            cout << "Yes" << endl;
        else if (maxa == b and b == a + c)
            cout << "Yes" << endl;
        else if (maxa == c and c == a + b)
        {
            cout << "Yes" << endl;
        }
        else
            cout << "No" << endl;
    }
}
