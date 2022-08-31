#include<bits/stdc++.h>
using namespace std;
int X, n, m, SUM, M = INT_MAX;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> X;
		M = min(abs(X), M);
		SUM += X;
		if (X < 0 && m)
			SUM -= X * 2, m--;
	}
	cout << SUM - (m % 2 ? M * 2 : 0);
}
// Best solution
/***
 * Keep making the negative elements positive until you have moves left.
 * If moves are exhausted then you are done
 * Else, remove the element with minimum absolute value.
 * */