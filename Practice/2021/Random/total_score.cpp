#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;

		int arr[k];
		for (int i = 0; i < k; i++)
			cin >> arr[i];

		string temp = "";
		for (int i = 0; i < n; i++) {
			cin >> temp;
			long long sum = 0;

			for (int j = 0; j < k; j++) {
				if (temp[j] == '1')
					sum += arr[j];
			}
			cout << sum << endl;
		}
	}
	return 0;
}