#include <bits/stdc++.h>
using namespace std;
int fastio() {
    cout << fixed << setprecision(6); return 0;
}
int __fastio = fastio();
typedef long long ll;
typedef long double ld;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

/**
 * * Started at : 6:00 pm
 * * Finished at : 6:16 pm
 * * Status : NA
*/



ll gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void estimating_pi(int N, vector<ll> arr) {

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (gcd(arr[i], arr[j]) == 1) {
                cnt++;
            }
        }
    }
    int total_pairs = N * (N - 1) / 2;

    // deb2(total_pairs,cnt);
    if (cnt == 0) {
        cout << "No estimate for this data set." << endl;
        return;
    }


    ld pi = (ld)6 * ((ld)total_pairs / (ld)cnt);
    pi = sqrt(pi);
    cout << pi << endl;
    return;
}

int main() {
    int N;
    while (cin >> N) {
        if (N == 0) return 0;

        vector<ll> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        estimating_pi(N, arr);
    }
}