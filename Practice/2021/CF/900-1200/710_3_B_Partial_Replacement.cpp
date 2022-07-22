#include <bits/stdc++.h>
#define ll long long
#define vec vector
#define MOD 1000000007
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ff first
#define ss second
#define read(x) cin >> x
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define deb(x) cout << #x << ": " << x << endl
#define deb2(x, y) cout << #x << ": " << x << ", " << #y << ": " << y << endl

using namespace std;
int solve(string &arr, int n, int k)
{
    int fi = arr.find_first_of('*');
    int last = arr.find_last_of('*');

    int count = fi == last ? 1 : 2;
    if (last - fi <= k)
        return count;

    // bool can = false;
    int idx = -1;
    for (int i = fi; i < last; i++)
    {
        for (int j = i + 1; j <= last; j++)
        {
            if (j - i <= k and arr[j] == arr[i] and arr[j] == '*')
                idx = j;
            else if (j - i > k)
                break;
            if (j == last)
                return count;
        }
        i = idx - 1;
        count++;
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt;
    cin >> tt;
    while (tt--)
    {
        int n, k;
        cin >> n >> k;
        string arr;
        cin >> arr;

        cout << solve(arr, n, k) << endl;
    }
}