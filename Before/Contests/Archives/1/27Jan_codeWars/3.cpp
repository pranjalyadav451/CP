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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout<<'a'-97<<endl;
    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        int n;
        cin >> n;
        string input;
        cin >> input;
        string res;
        for (int i = 0; i < input.size(); i++)
        {
            auto a = input[i];
            if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
            {
                res += a;
                input.erase(input.begin() + i);
                i--;
            }
        }
        sort(all(res));
        res += input;
        cout << res << endl;
    }
}