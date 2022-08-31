#include <bits/stdc++.h>
using namespace std;
struct Heater {
	int x, y, r;
	Heater() {
		x = 0, y = 0 , r = 0;
	}
};
int dist(int x, int y, int a, int b) {
	return (x - a) * (x - a) + (y - b) * (y - b);
}
int main() {
	int xa, ya, xb, yb;
	cin >> xa >> ya >> xb >> yb;
	int n;
	cin >> n;
	vector<Heater> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].x >> arr[i].y >> arr[i].r;
	}
	if (xa > xb) swap(xa, xb);
	if (ya > yb) swap(ya, yb);

	int total_generals = 2 * ( - ya + yb + 1) + 2 * (xb - xa - 1);
	map<pair<int, int>, int> m;

	for (int i = 0; i < n; i++) {
		for (int xx = xa; xx <= xb; xx++) {
			if (dist(xx, ya, arr[i].x, arr[i].y) <= arr[i].r * arr[i].r) m[ {xx, ya}] = 1;
			if (dist(xx, yb, arr[i].x, arr[i].y) <= arr[i].r * arr[i].r) m[ {xx, yb}] = 1;
		}
		for (int yy = ya + 1; yy < yb; yy++) {
			if (dist(xa, yy, arr[i].x, arr[i].y) <= arr[i].r * arr[i].r) m[ {xa, yy}] = 1;
			if (dist(xb, yy, arr[i].x, arr[i].y) <= arr[i].r * arr[i].r) m[ {xb, yy}] = 1;
		}
	}

	cout << total_generals - m.size() << endl;
}
