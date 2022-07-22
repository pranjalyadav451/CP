#include <bits/stdc++.h>
#define ll long long
#define vec vector
#define MOD 1000000007
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

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
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        sort(arr.rbegin(), arr.rend());
        ll ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                if (arr[i] % 2 == 0)
                    ans += arr[i];
            }
            else if (arr[i] % 2 == 1)
                ans -= arr[i];
        }

        if (ans > 0)
            cout << "Alice" << endl;
        else if (ans == 0)
            cout << "Tie" << endl;
        else
            cout << "Bob" << endl;
    }
}