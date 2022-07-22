#include<bits/stdc++.h>
using namespace std;
int main() {
	srand(time(0));
	int tt = 1;

	cout << "Number of arrays: "; cin >> tt;
	cout << endl;
	while (tt--) {
		int n, pos = 1, up = 20;
		cout << "Size, Signed, UpperLimit : ";
		cin >> n >> pos >> up;
		cout << endl;
		for (int i = 0; i < n; i++) {
			int num = rand() % up;
			if (!pos) {
				cout << ((rand() % 2 == 0) ? -num : num) << " ";
			}
			else {
				cout << num << " ";
			}
		}
		cout << endl;
	}
	return 0;
}