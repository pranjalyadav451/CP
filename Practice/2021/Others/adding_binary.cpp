#include <bits/stdc++.h>
using namespace std;
string addBinary(string a, string b)
{
    string res = "";
    int len = a.size() > b.size() ? a.size() : b.size();

//    cout<<"-----------------------------"<<endl;
//    cout<<static_cast<char>(1)-'0'<<endl;
//    cout<<a<<endl;
//    cout<<b<<endl;
//    cout<<len<<endl;
    // cout<<"-----------------------------"<<endl;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int sum = 0;
    int carry = 0;
    for (int i = 0; i <= len; i++)
    {
        if (i < a.size() && i < b.size())
            sum = carry + a[i] + b[i] - 96;
        else if (i < a.size())
            sum = carry + a[i] - 48;
        else
            sum = carry + b[i] - 48;
        cout << "sum ->" << sum << endl;
        carry = sum / 2;
        cout << "carry ->" << carry << endl;
        sum = sum % 2;
        // cout<<"sum is _> "<<sum<<endl;
        // cout<<"Value ->"<<static_cast<char>(sum+48)<<endl;
        res.push_back(static_cast<char>(sum + 48));
        // cout<<"resultant ->"<<res<<endl;
    }
    // cout<<"carry ->"<<carry<<endl;
    if (carry != 0)
    {
        res.push_back(static_cast<char>(carry + 48));
    }
    reverse(res.begin(), res.end());
    // cout<<res<<endl;
    return res;
}
int main()
{
    string a, b;
    cin >> a;
    cin >> b;
    cout << addBinary(a, b);
}