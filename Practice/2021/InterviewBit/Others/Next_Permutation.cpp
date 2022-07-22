#include<bits/stdc++.h>
using namespace std;
template<typename T>                ostream &operator<<(ostream &os, const vector<T> &v) {
	os << "["; string sep = ""; for (auto e : v) os << sep << e, sep = ", "; return os << "]";
}
// good question

vector<int> nextPermutation(vector<int> &num) {
	int len = num.size();
	int i, j;
	for (i = len - 2; i >= 0 ; i--)
		if (num[i] < num[i + 1]) break;

	if (i == -1) {
		reverse(num.begin(), num.end());
		return num;
	}
	cout << i << endl;
	for (j = len - 1; j > i; j--)
		if (num[j] > num[i]) break;

	swap(num[i], num[j]);
	reverse(num.begin() + i + 1, num.end());
	return num;;
}


int main() {
	int N ; cin >> N;
	vector<int> A(N);
	for (auto &a : A) {
		cin >> a;
	}
	vector<int> ans = nextPermutation(A);
	for (auto a : ans) {
		cout << a << " ";
	}
}