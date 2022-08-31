#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        ll n, tmp;
        cin >> n;
        vector<ll> d;
        for (ll i = 0; i < n; i++) {
            cin >> tmp;
            d.push_back(tmp);
        }
        sort(d.begin(), d.end());
        ll ind = 0;
        for (ll i = 0; i < n - 1; i++) {
            if ((d[ind + 1] - d[ind]) > (d[i + 1] - d[i]))
                ind = i;
        }
        vector<ll> ans;
        ans.push_back(d[ind]);
        for (ll i = ind + 2; i < n; i++)
            ans.push_back(d[i]);
        for (ll i = 0; i < ind; i++)
            ans.push_back(d[i]);
        ans.push_back(d[ind + 1]);

        for (auto a : ans) cout << a << " ";
        cout << endl;
    }
}
