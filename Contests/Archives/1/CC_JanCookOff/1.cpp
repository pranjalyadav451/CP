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
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

using namespace std;
void solve(string s)
{
    //     1) Password must contain at least one lower case letter [a−z];

    // 2) Password must contain at least one upper case letter [A−Z] strictly inside, i.e. not as the first or the last character;

    // 3) Password must contain at least one digit [0−9] strictly inside;

    // 4) Password must contain at least one special character from the set { '@', '#', '%', '&', '?' } strictly inside;

    // 5) Password must be at least 10 characters in length, but it can be longer.
    int len = s.size();
    vector<bool> arr(4, false);
    int count = 0;
    if (len >= 10)
    {
        fo(i, len)
        {
            if ((s[i] <= 90 and s[i] >= 65) and arr[0] == false and (i != len - 1 and i != 0))
            {
                count++;
                arr[0] = true;
            }
            else if (s[i] <= 122 and s[i] >= 97 and arr[1] == false)
            {
                count++;
                arr[1] = true;
            }
            else if (s[i] >= 48 and s[i] <= 57 and arr[2] == false and (i != len - 1 and i != 0))
            {
                count++;
                arr[2] = true;
            }
            else if ((s[i] == '@' or s[i] == '#' or (s[i]) == '%' or s[i] == '&' or s[i] == '?') and arr[3] == false and (i != len - 1 and i != 0))
            {
                count++;
                arr[3] = true;
            }
            if (count == 4)
            {
                break;
            }
        }
    }
    if (count == 4)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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
        string s;
        cin >> s;
        solve(s);
    }
}