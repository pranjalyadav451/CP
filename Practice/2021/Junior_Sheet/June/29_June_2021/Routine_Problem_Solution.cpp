#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int a, b, c, d, ans;

int main() {
	cin >> a >> b >> c >> d;
	a *= d;
	b *= c;
	ans = gcd(a, b);
	cout << abs(a - b) / ans << '/';
	if (a > b) {
		cout << a / ans;
	}
	else {
		cout << b / ans;
	}
}
