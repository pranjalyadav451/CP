#include<bits/stdc++.h>
using namespace std;

vector<int> KMaxCombinations(vector<int> &A, vector<int> &B, int K) {
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int N = A.size();

	priority_queue<pair<int, pair<int, int> > > pq;
	set<pair<int, int> > my_set;
	vector<int>res;

	pq.push(make_pair(A[N - 1] + B[N - 1], make_pair(N - 1, N - 1)));
	my_set.insert(make_pair(N - 1, N - 1));

	for (int count = 0; count < K; count++) {

		pair<int, pair<int, int> > temp = pq.top();
		pq.pop();

		res.push_back(temp.first);

		int i = temp.second.first;
		int j = temp.second.second;

		int sum = A[i - 1] + B[j];

		pair<int, int> temp1 = make_pair(i - 1, j);

		if (my_set.find(temp1) == my_set.end()) {
			pq.push(make_pair(sum, temp1));
			my_set.insert(temp1);
		}

		sum = A[i] + B[j - 1];
		temp1 = make_pair(i, j - 1);

		if (my_set.find(temp1) == my_set.end()) {
			pq.push(make_pair(sum, temp1));
			my_set.insert(temp1);
		}
	}
	return res;
}

int main() {
	int n, c;
	cin >> n;
	cin >> c;


	vector<int>arr(n), brr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> brr[i];
	}

	vector<int>res = KMaxCombinations(arr, brr, c);

	for (int elem : res)
		cout << elem << " ";
	cout << endl;
}






