#include <bits/stdc++.h>
using namespace std;
#define dbg(x)                              cout << #x << ": " << x << endl
#define dbgg(x, y)                          cout << #x << ": " << x << "  " << #y << ": " << y << endl



int searchMatrix(vector<vector<int> > &mat, int B) {
	int rows = mat.size() , cols = mat[0].size();
	int N = rows * cols;
	int left = 0, right = N - 1, mid = 0, ans = -1;
	while (left <= right) {
		mid = left + (right - left) / 2;
		int pos_x = mid / cols , pos_y = mid % cols;

		if (B == mat[pos_x][pos_y]) return 1;
		else {
			if (mat[pos_x][pos_y] < B) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
	}
	return 0;
}

int main() {
	int N, M, B; cin >> N >> M >> B;
	vector<vector<int>> arr(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	int ans = searchMatrix(arr, B);
	cout << ans << endl;
}