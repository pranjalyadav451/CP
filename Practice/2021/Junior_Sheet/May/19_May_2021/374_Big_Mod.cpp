#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll binpow_mod(ll a, ll b, ll m) {
    ll res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (res % m * a % m) % m;
        }
        a = (a % m * a % m) % m;
        b = b >> 1;
    }
    return res;
}
int main() {
    ll b, p, m;
    while (cin >> b >> p >> m) {
        ll ans = binpow_mod(b, p, m);
        cout << ans << endl;
    }
}