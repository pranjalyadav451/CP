#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll knapSack(int w, int wt[], int val[], int n)
{
    // recursive approach
    // => base condition

    // base condition can also just be :
    // if(n==0) return 0;
    if (n == 0 or w == 0)
        return 0;
    else
    {
        if (wt[n - 1] <= w)        {
            return max(knapSack(w - wt[n - 1], wt, val, n - 1) + val[n - 1], knapSack(w, wt, val, n - 1));
        }
        else
        {
            return knapSack(w, wt, val, n - 1);
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;
        int val[n];
        int wt[n];
        for (int i = 0; i < n; i++)
            cin >> val[i];
        for (int i = 0; i < n; i++)
            cin >> wt[i];
        cout << knapSack(w, wt, val, n) << endl;
    }
    return 0;
}