#include<bits/stdc++.h>

using namespace std;

const int oo = 1e9 + 7, maxn = 1e5 + 100;
int p[maxn], cnt;

void init(int n) {
    for (int i = 0; i <= maxn; i++) p[i] = i;
    cnt = n;
}

int find (int x) {
    if (x == p[x]) return x;
    return p[x] = find(p[x]);
}

void uni(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return;

    p[a] = b;
    cnt--;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;

    cin >> n;
    init(n);

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        uni(x, i);
    }

    cout << cnt << endl;
}
