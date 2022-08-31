#include<bits/stdc++.h>
using namespace std;

vector<int> bday(int X, vector<int> &B) {
    int N = B.size();
    int least = *min_element(B.begin(),B.end());
    int times = X / least;
    
    vector<int> res;
    for(int i = 0; i < N ;i++){
        // do binary search to find out max. how many of current elements we can take without worsening the answer
        auto bin = [&](){
            int lo = 0, hi = X/ B[i];
            int ans = 0;
            while(lo<=hi){
                int mid = lo + (hi - lo)/2;
                int rem = X - mid * B[i];
                if(mid + rem / least >= times){
                    ans = mid;
                    lo = mid + 1;
                }
                else{
                    hi = mid - 1;
                }
            }
            return ans;
        };
        int m = bin();
        X -= m * B[i];
        times -= m;
        for(int j =0; j < m;j++) res.push_back(i);
    }
    return res;
}
void solve(){
    int limit; cin >> limit;
    int N; cin >> N;

    vector<int> arr(N);
    for(int i =0; i < N;i++){
        cin >> arr[i];
    }

    vector<int> ans = bday(limit,arr);
    for(auto a:ans) cout << a << " ";
    cout << endl;
}

int main(){
    int tt = 1;
    while(tt--) solve();
}
