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
int totalPath = 0;
void mazePath(int n, int m, int i = 0, int j = 0, string osf = "")
{
    if (i == n - 1 and j == m - 1)
    {
        cout << osf << endl
             << endl;
        totalPath++;
        return;
    }
    if (i >= n or j >= m)
    {
        return;
    }
    if (i < n and j < m)
    {
        mazePath(n, m, i + 1, j, osf + " ⬇");
        mazePath(n, m, i, j + 1, osf + " ➡");
        mazePath(n, m, i + 1, j + 1, osf + " ↘");
    }
}
//osf ->output so far , good variable name
/* 
constraints of the problem - you can either move right or down and
you start at top left
*/
/* 
modified problem -> you can either move down, right or diagonally
but you still start at top left
*/
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        int n, m;
        cin >> n >> m;
        mazePath(n, m);
        deb(totalPath);
    }
}