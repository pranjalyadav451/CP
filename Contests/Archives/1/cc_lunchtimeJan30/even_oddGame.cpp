#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define deb(x) cout << #x << " => " << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

#define MOD 1000000007
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        int temp = 0;
        int ec = 0, oc = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            if (temp % 2 == 0)
                ec++;
            else
                oc++;
        }
        if(oc%2==1)
        cout<<"2"<<endl;
        else
        cout<<"1"<<endl;
    }
}
