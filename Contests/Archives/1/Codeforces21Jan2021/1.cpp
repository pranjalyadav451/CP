#include <bits/stdc++.h>
using namespace std;
#define e19_7 (1000000000 + 7)
#define ll long long
int gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b % a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}
ll int C(int n, int i)
{
    int ans = 1;
    for (int k = i; k <= n; k++)
    {
        ans = (ans * i) % e19_7;
    }
}
ll int ans(int n)
{
    long long int ans = 1;
    for (int i = n; i > n / 2; i--)
    {
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        //cout << t;
    }
    return 0;
}