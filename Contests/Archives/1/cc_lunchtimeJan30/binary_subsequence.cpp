#include<bits/stdc++.h>
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
int solve(string &s, int n)
{
    std::vector<int> a(n, 1);
    int len = s.size();
    a[0] = 1;
    for (int i = 1; i < len; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if ((int)s[i] >= (int)s[j] and a[i] < a[j] + 1)
                a[i] = a[j] + 1;
        }
    }
    return len - *max_element(all(a));
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << solve(s, n);
    }
}
