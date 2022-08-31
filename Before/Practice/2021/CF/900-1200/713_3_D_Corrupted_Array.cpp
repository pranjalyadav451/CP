#include <bits/stdc++.h>
#define ll long long
#define vec vector
#define MOD 1000000007
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ff first
#define ss second
#define read(x) cin >> x
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define deb(x) cout << #x << ": " << x << endl
#define deb2(x, y) cout << #x << ": " << x << ", " << #y << ": " << y << endl

using namespace std;

void solve(vec<ll> &arr, int n, ll sum)
{
    sort(arr.begin(), arr.end());
    vec<ll> res;

    int len = n + 2;

    ll bn = len - 1;
    ll sa = sum - arr[bn];
    int idx = -1;

    int count = 1;

    rep(i, 0, len)
    {
        if (i != bn)
        {
            if (sa - arr[i] == arr[bn])
            {
                idx = i;
                break;
            }
        }
        if (idx == -1 and i == len - 1 and count)
        {
            i = -1;
            bn = len - 2;
            sa = sum - arr[bn];
            count--;
        }
    }

    if (idx != -1)
        rep(i, 0, len)
        {
            if (i != idx and i != bn)
            {
                cout << arr[i] << " ";
            }
        }
    else
        cout << -1;
    cout << endl;
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
        int n, len;
        cin >> n;
        len = n + 2;

        vec<ll> arr(len);
        ll sum = 0;
        rep(i, 0, len)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        solve(arr, n, sum);
    }
}