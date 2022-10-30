
#include<bits/stdc++.h>
//iamnehalchandra

#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define goog(tno) cout << "Case #" << tno <<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define read(x) int x; cin>>x
#define ll long long 
using namespace std;




int main() {
    fast_io;
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        string s;
        cin >> s;
        vector<vector<int>> m(26);
        vector<int> numberarray(10, 0);

        bool flag = true;
        for (int i = 0; i < n; i++) {
            int target = s[i] - 97;
            int numbertarget = a[i];
            if (flag == false) {
                break;
            }
            if (m[target].size() > 0) {
                bool flag2 = false;
                for (int j = 0; j < m[target].size(); j++) {
                    if (numbertarget == m[target][j]) {
                        flag2 = true;

                        break;

                    }
                }
                if (flag2 == false) {
                    if (numberarray[numbertarget] == 1) {
                        flag = false;

                        break;
                    }
                    else {
                        m[target].push_back(numbertarget);
                        numberarray[numbertarget] = 1;
                    }
                }


            }


            else {
                if (numberarray[numbertarget] == 1) {

                    flag = false;

                    break;
                }
                else {
                    m[target].push_back(numbertarget);
                    numberarray[numbertarget] = 1;

                }
            }
            if (flag == true)cout << "Yes";
            else cout << "No";

        }

        cout << "" << endl;
    }

}


