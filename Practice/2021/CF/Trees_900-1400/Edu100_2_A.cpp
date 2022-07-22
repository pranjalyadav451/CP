#include<bits/stdc++.h>
using namespace std;
#define ll long long

string solve(ll a, ll b, ll c) {

	ll sum = a + b + c;
	ll mn = min({ a, b, c });

	if (mn < sum / 9)
		return "NO";
	else {
		if (sum % 9 == 0)
			return "YES";
		else return "NO";
	}
}


int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		ll a, b, c;
		cin >> a >> b >> c;
		cout << solve(a, b, c) << endl;
	}
}

/**
 * I have to practice more of MATHS and CONSTRUCTIVES problems.
*/