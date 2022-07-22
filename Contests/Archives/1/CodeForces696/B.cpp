#include <bits/stdc++.h>
using namespace std;
vector<bool> isPrime(1000000, true);
void sieveWithDifference()
{
    int n = 1000000;
    //cout<<"max ->"<<isPrime.max_size()<<endl;
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (int j = 2; j * i <= n; j++)
            {
                isPrime[j * i] = false;
            }
        }
    }
}
void result(int d)
{
    long long int ans = 1;
    int count = 0;
    // cout << d << endl;
    // cout << isPrime[2] << endl;
    for (int i = 0; i <= 1000000; i++)
    {
        // cou
        //cout << isPrime[i] << endl;
        //cout << i << endl;
        if (i - 1 >= d and isPrime[i] == true and count == 0)
        {
            //  cout << i << endl;
            //cout<<ans<<endl;
            ans = i;
            //cout << ans << endl;
            count++;
        }
        else if (i >= ans + d && isPrime[i] == true)
        {
            cout << ans * i << endl;
            break;
        }
    }
    // vector<int> ans;
    // for (int i = 0; i <= n; i++)
    // {
    //     if (i - 1 >= d && ans.empty() and isPrime[i]==true)
    //     {
    //         cout<<i<<endl;
    //         ans.push_back(i);
    //     }
    //     else if (i - ans[0] >= d and isPrime[i])
    //     {
    //         cout<<i<<endl;
    //         ans.push_back(i);
    //         break;
    //     }
    // }
    // cout << ans[0] * ans[1] << endl;
}
int main()
{
    int t;
    cin >> t;
    sieveWithDifference();
    while (t--)
    {
        int d;
        cin >> d;
        // int n = 10 * d;

        result(d);
    }
    return 0;
}