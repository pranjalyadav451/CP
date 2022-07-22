#include <bits/stdc++.h>
#define ll long long
#define vec vector
#define MOD 1000000007
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ff first
#define ss second
#define read(x) cin>>x
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define deb(x) cout << #x << ": " << x << endl
#define deb2(x, y) cout << #x << ": " << x << ", " << #y << ": " << y << endl

using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	ll prev = -1, current, mx = 0, len = 0;

	for (int i = 0; i < n; i++) {
		cin >> current;

		// deb2(current, prev);
		if (current >= prev) {
			len++;
		}
		else {
			len = 1;
		}
		// deb2(mx, len);
		mx = max(mx, len);
		// cout << endl;
		prev = current;
	}
	cout << mx << endl;

}

/*
	Notes -:
*/