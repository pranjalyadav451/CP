#include <bits/stdc++.h>
using namespace std;

#define inf (1<<30)
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define MAX 1000010

int m, k, l;
int dp[MAX];
bool f(int a) {
    if (a <= 0)
        return 0;
    if (dp[a] != -1)
        return dp[a];
    else {
        int arr[] = { a - l,a - k,a - 1 };
        for (int i = 0; i < 3; i++)
            if (arr[i] >= 0 and !f(arr[i]))
                return dp[a] = 1;
        return dp[a] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k >> l >> m;
    string str;
    int a;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < m; i++) {
        cin >> a;
        if (f(a))
            str += 'A';
        else
            str += 'B';
    }
    cout << str << endl;
    //cout<<"Execution time : "<<tick();
    return 0;
}
