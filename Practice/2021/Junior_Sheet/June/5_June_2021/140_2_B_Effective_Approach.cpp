#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int n;
	cin >> n;
	// vector<long long > arr(n);
	map<ll , ll > marr;
	for (int i = 0; i < n; i++) {
		ll t;
		cin >> t;
		marr[t] = i;
	}

	int m;
	cin >> m;
	ll vasya = 0 , petya = 0;
	while (m--) {
		ll b;
		cin >> b;
		auto pos = (marr.find(b));
		if (pos == marr.end()) {
			vasya += n;
			petya += n;
		}
		else {
			vasya += pos->second + 1;
			petya += n - pos->second;
		}
	}
	cout << vasya << " " <<  petya << endl;
}