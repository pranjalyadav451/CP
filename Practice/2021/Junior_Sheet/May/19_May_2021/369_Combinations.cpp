#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/**
 * * UVA Online Judge
 * * Started at : 2:46 pm
 * * Paused at : 2:58 pm
 * ********************************
 * * Resumed : 5:50 pm
 * * Completed at 5:57 pm
 * * Status -: AC.
*/

ll exact_choice(ll N, ll M) {
    ll res = 1;
    for (int i = M - 1; i >= 0; i--) {
        res = res * (N - i);
        res = res / (M - i);
    }
    return res;
}

int main() {
    ll N, M;
    while (cin >> N >> M) {
        if (N == 0 and M == 0) {
            return 0;
        }
        ll ans = exact_choice(N, M);
        cout << N << " things taken " << M << " at a time is " << ans << " exactly." << endl;
    }
}
