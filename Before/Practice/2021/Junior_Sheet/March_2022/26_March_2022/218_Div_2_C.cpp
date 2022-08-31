#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int amount[3];
int prices[3];
int recipe[3];
ll coins;


// very good question of binary search
// I would not have guessed that this question is of binary search

/*
	Ye sochne se acha ki number of burgers kaise maximize karen
	ye socha jae ki ek given amount of burgers banana possible hai ki nahi.
*/


bool test(ll m) {
	ll spend = 0;
	for (int i = 0; i < 3; i++)
		spend += 1LL * prices[i] * max(0LL, 1LL * m * recipe[i] - amount[i]);

	if (spend <= coins) return true;
	else return false;
}

int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'B') recipe[0]++;
		if (s[i] == 'S') recipe[1]++;
		if (s[i] == 'C') recipe[2]++;
	}

	for (int i = 0; i < 3; i++) cin >> amount[i];
	for (int i = 0; i < 3; i++) cin >> prices[i];
	cin >> coins;

	ll lo = 0;
	ll hi = (1LL << 45);
	ll ans = 0;

	while (lo <= hi) {
		ll me = lo + (hi - lo) / 2;
		if (test(me)) {
			ans = me;
			lo = me + 1;
		}
		else hi = me - 1;
	}

	cout << ans << '\n';
	return 0;
}