#include <bits/stdc++.h>
using namespace std;
int count = 0;
void lex(int n, int i = 0)
{
    if (i > n)
    {
        return;
    }
    cout << i << endl;
    for (int j = (i == 0) ? 1 : 0; j <= 9; j++)
    {
        lex(n, i * 10 + j);
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        lex(n);
    }
    return 0;
}