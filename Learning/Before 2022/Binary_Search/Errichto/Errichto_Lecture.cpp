#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll binarySquareRoot(ll n) {
	ll lo = 1, hi = n, mid;

	while (lo <= hi) {
		mid = lo + (hi - lo) / 2;

		if (mid * mid == n)	return mid;
		else if (mid * mid < n) lo = mid + 1;
		else hi = mid - 1;
	}
	return -1;
}
ll firstElementGreaterThanX(vector<ll> &arr, ll x) {
	ll lo = 0, hi = arr.size() - 1, mid;
	ll ans = -1;
	while (lo <= hi) {
		mid = lo + (hi - lo) / 2;

		if (arr[mid] >= x) {
			ans = arr[mid];
			hi = mid - 1;
		}
		else lo = mid + 1;
	}
	return ans;
}


int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		// int n;
		// cin >> n;

		// ll num = 0;
		// for (int i = 0; i < n; i++) {
		// 	cin >> num;
		// 	cout << binarySquareRoot(num) << " ";
		// }
		ll n, x;
		cin >> n >> x;
		vector<ll>arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		cout << firstElementGreaterThanX(arr, x);

		cout << endl;
	}
}