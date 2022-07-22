/*Template By Parth Sharma */
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repa(s) for (auto &i : s)
#define repr(i, a, b) for (int i = a; i > b; i--)
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define F first
#define S second
#define ub(x, k) upper_bound(x.begin(), x.end(), k)
#define lb(x, k) lower_bound(x.begin(), x.end(), k)
#define pb push_back
#define pob pop_back
#define mp make_pair
#define sz(s) s.size()
#define mod 1000000007
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
typedef map<int, int> mii;
typedef map<int, vi> mivi;
int sod(int n)
{
    int sum = 0;
    while (n != 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
bool isprime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int gcd(int a, int b)
{
    if (!b)
        return a;

    return gcd(b, a % b);
}
int ncr(int n, int r)
{
    int p = 1, d = 1;
    while (r)
    {
        p *= n;
        d *= r;
        int x = gcd(p, d);
        p /= x;
        d /= x;
        n--;
        r--;
    }
    return p;
}
int fact(int n)
{
    if (!n)
        return 1;

    return n * fact(n - 1);
}
class comp
{
public:
    bool operator()(pii a, pii b)
    {
        if (a.first == b.first)
            return a.second > b.second;

        return a.first < b.first;
    }
};
int dp[11][95];
int solve(int *a, int n, int sum)
{
    if (n == 0 && sum != 0)
        return dp[n][sum] = 0;

    if (sum == 0)
        return dp[n][sum] = 1;

    if (a[n - 1] <= sum)
        return dp[n][sum] = max(solve(a, n, sum - a[n - 1]), solve(a, n - 1, sum));

    return dp[n][sum] = solve(a, n - 1, sum);
}
signed main()
{
    IOS;
    int t = 1, el = 0;
    cin >> t;
    while (t--)
    {
        int q, d;
        cin >> q >> d;
        int a[10];
        a[0] = d;
        rep(i, 1, 10)
            a[i] = a[i - 1] + 10;
        memset(dp, -1, sizeof(dp));
        while (q--)
        {
            cin >> el;
            if (el > 10 * d)
            {
                cout << "YES\n";
                continue;
            }
            if (dp[10][el] == -1)
                solve(a, 10, el);
            dp[10][el] == 1 ? cout << "YES\n" : cout << "NO\n";
        }
    }
    return 0;
}