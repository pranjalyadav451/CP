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
void printN(ll n)
{
    //    if(n>=1)
    //    {
    //        printN(n-1);
    //        cout<<n<<" ";
    //    }
    //    else
    //    return;

    // base case
    if (n == 1)
    {
        cout << n << " ";
    }
    else
    {
        // if we are able to print upto n -1 then we will just add n to end and our work is complete.
        printN(n - 1);
        cout << n << " ";
    }
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
        ll int n;
        cin >> n;
        printN(n);
        cout << endl;
    }
}