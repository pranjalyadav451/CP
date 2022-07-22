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
int times(string s, char a)
{
    int time = 0;
    for (auto i : s)
    {
        if (i == a)
            time++;
    }
    return time;
}

string solve(string a)
{

    int len = a.size();

    if (a[0] == a[len - 1])
        return "NO";

    int timesOpen = times(a, a[0]);
    int timesClose = times(a, a[len - 1]);

    if (len - timesClose == len / 2 or timesOpen == len / 2)
    {
        stack<char> reg;

        for (int i = 0; i < len; i++)
        {
            if (timesOpen == len / 2)
            {
                if (reg.empty() or a[i] == a[0])
                    reg.push(a[i]);
                else if (reg.empty() == false and (reg.top() == a[0] and a[i] != a[0]))
                    reg.pop();
            }
            else
            {
                if (reg.empty() or a[i] != a[len - 1])
                    reg.push(a[i]);
                else if (!reg.empty() and (reg.top() != a[len - 1] and a[i] == a[len - 1]))
                    reg.pop();
            }
        }
        return reg.empty() ? "Yes" : "NO";
    }
    else
        return "NO";
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
        string a;
        cin >> a;
        cout << solve(a) << endl;
    }
}