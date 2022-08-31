#include <bits/stdc++.h>
using namespace std;
#define ll long long
string solve(ll n)
{
    string tomax = "989";
    string after = "0123456789";
    string res = "";
    if(n<=3)
    {
        return tomax.substr(0,n);
    }
    else
    {
        res+=tomax;
        int times = (n-3)/10;
        int rem = (n-3)%10;

        for(int i=0;i<times;i++)
        {
            res+=after;
        }
        res+=after.substr(0,rem);
    }
    return res;

}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}