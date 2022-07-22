#include <bits/stdc++.h>
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

using namespace std;

string solve(string s, int start, int end)
{
    bool is_present = false;

    for (int i = 0; i < start - 1 and !is_present; i++)
        if (s[i] == s[start - 1])
            is_present = true;

    for (size_t i = end; i < s.size() and !is_present; i++)
        if (s[i] == s[end - 1])
            is_present = true;

    return is_present ? "YES" : "NO";
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
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;

        int start, end;
        for (int i = 0; i < q; i++)
        {
            cin >> start >> end;
            cout << solve(s, start, end) << endl;
        }
    }
}