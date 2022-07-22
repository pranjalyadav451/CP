#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int val[], int n)
{
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