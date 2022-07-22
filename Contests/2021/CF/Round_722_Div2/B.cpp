#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } int __fastio = fastio();

typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef long double ld;
#define ALL(x) (x).begin(),(x).end()
#define REP(i, a, b) for (int i = (a); i <= (b); (i)++)
#define RREP(i, a, b) for (int i = (a); i >= (b); (i)--)
#define dbg(x) cout << #x << ": " << x << endl
#define dbgg(x, y) cout << #x << ": " << x << "  " << #y << ": " << y << endl

void len_longest_ss(vector<ll> &arr, int n) {
	sort(ALL(arr));
	int neg_cnt = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] <= 0) {
			neg_cnt++;
		}
	}

	if (neg_cnt == n) {
		cout << n << endl;
		return;
	}

	int min_pos = arr[neg_cnt];
	bool can_pos = true;
	for (int i = 0; i < neg_cnt; i++) {
		if (abs(arr[i] - arr[i - 1]) < min_pos) {
			can_pos = false;
			break;
		}
	}
	if (can_pos) {
		cout << neg_cnt + 1 << endl;
	}
	else {
		cout << neg_cnt << endl;
	}
}

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<ll> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		len_longest_ss(arr, n);
	}
}
