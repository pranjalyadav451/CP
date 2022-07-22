#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
	int n;
	cin >> n;
	vector<ll > arr(n);
	for (ll &a : arr) {
		cin >> a;
	}

	/* Solution */
	set<ll> uniq;
	for (int i = 0; i < n; i++) {
		uniq.insert(arr[i]);
	}

	/**
	 * read the question wrong
	 * I can pick any integer 'x' (not limited to the integers contained in the array).
	**/

	if (uniq.size() <= 2 ) {
		cout << "YES" << endl;
	}
	else if (uniq.size() != 3) {
		cout << "NO" << endl;
		return 0;
	}
	else {
		vector<ll> three;
		for (auto a : uniq) {
			three.push_back(a);
		}
		if (three[1] - three[0] == three[2] - three[1]) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}