#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
	int search(string pat, string txt) {
		int M = pat.size() , N = txt.size();
		vector<int> pat_cnt(500) , temp(500);
		for (int i = 0; i < M; i++) {
			pat_cnt[pat[i]]++;
			temp[txt[i]]++;
		}
		int cnt = 0, prev = 0;
		for (int i = M; i < N; i++) {
			if (temp == pat_cnt) cnt++;
			temp[txt[prev]]--;
			prev++;
			temp[txt[i]]++;
		}
		if (temp == pat_cnt) cnt++;
		return cnt;
	}

};


int main() {
	int t;
	cin >> t;
	while (t--) {
		string pat, txt;
		cin >> txt >> pat;
		Solution ob;
		auto ans = ob.search(pat, txt);
		cout << ans << "\n";
	}
	return 0;
}