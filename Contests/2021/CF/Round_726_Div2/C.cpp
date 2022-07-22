#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int N;
	cin >> N;
	vector<ll> arr(N);
	for(int i=0; i < N;i++){
		cin >> arr[i];
	}
	sort(arr.begin(),arr.end());
	ll min_diff = 1e12,idx = -1;
	for(int i=1; i < N;i++){
		if(llabs(arr[i] - arr[i - 1]) < min_diff){
			min_diff = llabs(arr[i] - arr[i- 1]);
			idx = i - 1;
		}
	}
	cout << arr[idx] << " ";
	for(int i=idx + 2;i < N;i++){
		cout << arr[i] << " ";
	}
	for(int i=0; i < idx;i++){
		cout << arr[i] << " ";
	}
	cout << arr[idx + 1] << " ";
	
	cout << endl;
}

int main() {
	int tt;
	cin >> tt;
	while(tt--){
		solve();
	}
}