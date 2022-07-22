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
#define LIMIT 1000000
using namespace std;

bool isPrime[1000000+1];
int ans[LIMIT+1] = {0};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int testCase = 1;
    cin >> testCase;

    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i*i <= LIMIT; i++)
    {
        if (isPrime[i])
            for (int j = i; j * i <= LIMIT; j++)
            {
                isPrime[j * i] = false;
            }
    }
    // deb(isPrime[5]);
    int count = 0;
    int a = 2;
    for (int j = 5; j <= LIMIT; j++)
    {
        if (isPrime[j] and isPrime[j - a])
            count++;
        ans[j] = count;
    }

    while (testCase--)
    {
        int n;
        cin >> n;

        cout << ans[n] << endl;
    }
}