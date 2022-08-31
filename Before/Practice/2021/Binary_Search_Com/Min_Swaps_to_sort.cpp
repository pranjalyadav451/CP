#include<bits/stdc++.h>
using namespace std;



void output(vector<int> &nums) {
	for (auto a : nums)cout << a << " ";
	cout << endl;
}
#define dbg(x) cout << #x << ": " << x << endl
#define dbgg(x, y) cout << #x << ": " << x << ", " << #y << ": " << y << endl

class Solution
{
public:
	int dfs(vector<int> adj[], vector<bool> &visited, int node) {
		if (visited[node]) return 0 ;
		visited[node] = 1;
		int cnt = 1;
		for (auto a : adj[node]) {
			cnt += dfs(adj, visited, a);
		}
		return cnt;
	}
	int minSwaps(vector<int>&arr) {
		// how to find the minimum steps to sort the array.
		vector<int> other = arr;
		sort(other.begin(), other.end());
		map<int, int> final;
		int N = arr.size();
		vector<int> connections(N);

		for (int i = 0; i < N; i++) {
			final[other[i]] = i;
		}
		for (int i = 0; i < N; i++) {
			connections[i] = (final[arr[i]]);
		}

		int ans = 0;
		vector<bool> visited(N, 0);

		for (int i = 0; i < N; i++) {
			int temp = i , swaps = 0;
			while (visited[temp] == false) {
				visited[temp] = true;
				temp = connections[temp];
				swaps++;
			}
			ans += swaps > 0 ? swaps - 1 : 0;
		}
		return ans;
	}
};

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int>nums(n);
		for (int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans << "\n";
	}
	return 0;
}