#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &arr) {
	vector<int> ans;
	int left = 0 , right = arr.size() - 1;
	while(left <= right){
		int left_val = abs(arr[left]) , right_val = abs(arr[right]);
		int val_to_push = 0;
		if(left_val > right_val){
			left++;
			val_to_push = left_val * left_val;
		}else{
			right--;
			val_to_push = right_val * right_val;
		}
		ans.push_back(val_to_push);
	}
    reverse(ans.begin(),ans.end());
	return ans;
}

int main() {
	int N; cin >> N;
	vector<int> arr(N);
	for (auto &a : arr) cin >> a;
	vector<int> ans = solve(arr);
	for (auto &a : ans) {
		cout << a << " ";
	}
}