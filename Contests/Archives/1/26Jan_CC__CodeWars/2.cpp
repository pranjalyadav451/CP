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
#define deb(x) cout << #x << " => " << x << endl
#define deb2(x, y) cout << #x << "=> " << x << "," << #y << "=" << y << endl

using namespace std;

ll solve(int n, int a[])
{
    if (n <= 1)
        return 1;
    else if (a[0] == 0)
        return -1;
    if (a[0] >= n - 1)
        return 1;

    int max_pointer = 0;
    int count = 0;
    int t = 0;

    for (int i = 0; i < n; i++)
    {
        t = i + a[i];

        for (int j = i + 1; j <= t; j++)
        {
            if (max_pointer + a[max_pointer] < a[j] + j)
            {
                max_pointer = j;
            }
        }

        if (i == max_pointer)
            return -1;
        count++;
        if (max_pointer + a[max_pointer] >= n - 1)
        {

            return count + 1;
        }
        else
        {
            // count++;
            i = max_pointer - 1;
        }
    }
    return count + 1;
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
        int n;
        cin >> n;
        // deb(n);
        int P[n];
        fo(i, n)
        {
            cin >> P[i];
        }
        // deb(solve(n, P));
        cout << solve(n, P) << endl;
        // cout << "----------" << endl;
    }
}