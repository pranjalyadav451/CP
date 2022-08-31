#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(vector<vector<int>>& arr, vector<int>& cuts) {
    vector<vector<int>> res;
    int N = arr.size();
    for(int i=0; i < N;i++){
		if(cuts[0] < arr[i][0] and cuts[1] > arr[i][1]){
			continue;
		}	    	
		else{
			if(arr[i][0] <= cuts[0] and arr[i][1] >= cuts[1]){
				res.push_back({arr[i][0], cuts[0]});
				res.push_back({cuts[1],arr[i][1]});
			}
			else{
				if(cuts[0] <= arr[i][1] and cuts[0] >=arr[i][0]){
					res.push_back({arr[i][0],cuts[0]});
				}
				else if(cuts[1] >= arr[i][0] and cuts[1] <=arr[i][1]){
					res.push_back({cuts[1],arr[i][1]});
				}
			}
		}
    }
    return res;
}

int main(){
	int n;
	cin >> n;
	vector<vector<int>> intervals(n,vector<int>(2));
	vector<int> cuts(2);
	cin >> cuts[0] >> cuts[1];
	for(int i=0; i < n;i++){
		cin >> intervals[i][0] >> intervals[i][1];
	}
	vector<vector<int>> res = solve(intervals,cuts);

	for(auto &vec:res){
		for(auto ele:vec){
			cout << ele << " ";
		}
		cout << endl;
	}
}