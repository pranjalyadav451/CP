#include <bits/stdc++.h>
using namespace std;
int jumps(int n, int i = 0, string osf = "")
{
    if (i >= n)
        return 0;
    if (i == n - 1)
    {
        cout << osf << endl;
        return 1;
    }

    int count = 0;
    if (i < n - 1)
    {
        count += jumps(n, i + 1, osf + "1|-> ") +
                 jumps(n, i + 2, osf + "2|-> ") +
                 jumps(n, i + 3, osf + "3|-> ") +
                 jumps(n, i + 4, osf + "4|-> ") +
                 jumps(n, i + 5, osf + "5|-> ") +
                 jumps(n, i + 6, osf + "6|-> ");
    }
    return count;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        //cout << t;
        int n;
        cin >> n;
        cout << jumps(n) << endl;
    }
    return 0;
}