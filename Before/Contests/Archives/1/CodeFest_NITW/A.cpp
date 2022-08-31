#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vec vector
#define e19 1000000000
ll process(vec<string> &all, int len)
{
    unordered_set<int> s;
    int eachSize = all[0].size();
    ll int count = 0;
    for (int col = 0; col < eachSize; col++)
    {
        for (int row = 0; row < len - 1; row++)
        {
            // cout<<all[row][col]<<endl;
            if (all[row + 1][col] != all[row][col])
            {
                // cout<<"col ->"<<row<<endl;
                // cout<<"row->"<<col<<endl;
                // cout << all[row][col] <<"  "<< all[row+1][col] << endl;
                s.insert(col);
                // break;
            }
        }
    }
    count = s.size();
    if (count == 0)
        return 0;
    // cout << count << endl;
    else
    {
        ll ans = 1;
        for (int k = 0; k < count; k++)
        {
            ans = (ans * 2) % (e19 + 7);
        }
        return ans;
    }
}

int main()
{
    int n;
    cin >> n;
    vec<string> all(n, "");
    for (size_t i = 0; i < n; i++)
    {
        cin >> all[i];
        // cout << all[i] << endl;
    }
    cout << process(all, n) << endl;
    return 0;
}