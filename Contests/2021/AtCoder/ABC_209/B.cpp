#include<bits/stdc++.h>
using namespace std;
int main() {
	int N , X;
	cin >> N >> X;
	vector<int> arr(N);
	for (auto &it : arr) cin >> it;
	long long sum = 0;
	for (int i = 0; i < N; i++) {
		if (i % 2 == 1) {
			sum += arr[i] - 1;
		}
		else {
			sum += arr[i];
		}
	}
	cout << (sum <= X ? "Yes" : "No") << endl;
}