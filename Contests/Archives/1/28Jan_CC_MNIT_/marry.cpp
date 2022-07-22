#include <iostream>
#include <string>
#include <algorithm>
#define ll long long
#define vec vector
#define MOD 1000000007
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define trav(a, x) for (auto &a : x)
#define fo(i, n) for (int i = 0; i < n; i++)
#define deb(x) cout << #x << " => " << x << endl
#define deb2(x, y) cout << #x << "=> " << x << "," << #y << "=" << y << endl

using namespace std;
void shifted(string &temp, int i)
{
    // string temp = s;
    reverse(temp.end() - i, temp.end());
    reverse(temp.begin(), temp.end() - i);
    reverse(all(temp));
    // return temp;
}
int solve(string &s)
{
    int shift = s.length() - 1;
    int count = 0;
    string t = "";
    string rev = "";
    for (int i = 0; i <= shift; i++)
    {
        t = s;
        shifted(t, i);
        rev = t;
        reverse(all(rev));
        if (rev == t)
            count++;
    }
    return count;
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
        string s;
        cin >> s;
        cout << solve(s) << "\n";
    }
}