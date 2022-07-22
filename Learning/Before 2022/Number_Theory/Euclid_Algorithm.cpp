#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int euclid_gcd(int a, int b) {
	if (a == 0) return b;
	return euclid_gcd(b % a, a);
}

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int a, b;
		cin >> a >> b;
		cout << "GCD(" << a << ", " << b << ") : " << euclid_gcd(a, b) << endl;
	}
}