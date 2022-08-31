#include <bits/stdc++.h>
#define deb(x) cout << #x << ": " << x << endl
#define deb2(x, y) cout << #x << ": " << x << ", " << #y << ": " << y << endl
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n , k;
		cin >> n >> k;

		int ifOdd = n - k + 1, ifEven = n - 2 * (k - 1);
		// deb2(ifOdd, ifEven);
		if (ifOdd > 0 and (ifOdd & 1)) {
			cout << "YES" << endl;
			for (int i = 0; i < k - 1; i++) {
				cout << 1 << " ";
			}
			cout << ifOdd << endl;
		}
		else if (ifEven > 0 and not (ifEven & 1)) {
			cout << "YES" << endl;
			for (int i = 0; i < k - 1 ; i++) {
				cout << 2 << " ";
			}
			cout << ifEven << endl;
		}
		else cout << "NO" << endl;
	}
}