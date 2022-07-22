#include <bits/stdc++.h>
using namespace std;
string add(string s, int n = 1)
{
    int sum = 0;
    int carry = 0;
    int len = s.size();

    reverse(s.begin(), s.end());
    string res = "";
    sum = s[0] + n - 48;

    carry = sum / 10;
    sum = sum % 10;

    res.push_back(char(sum + 48));
    // cout << res[0] << endl;
    for (int i = 1; i < len; i++)
    {
        sum = s[i] + carry - 48;
        carry = sum / 10;
        sum = sum % 10;
        res.push_back(char(sum) + 48);
    }
    if (carry != 0)
    {
        res.push_back(char(carry) + 48);
    }
    reverse(res.begin(), res.end());
    return res;
}
bool isGreater(string &right, string &left)
{
    bool ans = false;
    // cout<<"inside isGreater ->"<<endl;
    // cout<<right<<endl;
    // cout<<left<<endl;
    // cout<<" ------------------"<<endl;
    if(right.size()<left.size())
    return false;
    for (int i = 0; i < right.size(); i++)
    {
        if (right[i] > left[i])
        {
            ans = true;
            break;
        }
        else if (left[i] > right[i])
        {
            ans = false;
            break;
        }
    }
    return ans;
}
string next(string s)
{
    int len = s.length();
    
    if(s=="9")
    return "11";

    if (len % 2 == 0)
    {
        string left = "";

        left = s.substr(0, len / 2);

        string original_right = s.substr(len / 2, len / 2);

        string right = left;

        // cout<<"left  "<<left<<endl;
        // cout<<"original_right  "<<original_right<<endl;
        // cout<<"right ->"<<right<<endl;

        reverse(right.begin(), right.end());

        if (isGreater(right, original_right))
        {
            // cout<<"control"<<endl;
            return left + right;
        }
        else
        {
            int prev_size = left.size();
            left = add(left, 1);
            if (prev_size != left.size())
            {
                right = left.substr(0, left.size() - 1);
            }
            else
            {
                right = left;
            }
            reverse(right.begin(), right.end());
            return left + right;
        }
    }
    else
    {
        string left = "";
        left = s.substr(0, len / 2 + 1);
        string original_right = s.substr(len / 2 + 1, len / 2);
        string right = left.substr(0, left.size() - 1);
        reverse(right.begin(), right.end());
        if (isGreater(right, original_right))
        {
            return left + right;
        }
        else
        {
            int prev_size = left.size();
            left = add(left, 1);
            if (prev_size != left.size())
            {
                right = left.substr(0, left.size() - 2);
            }
            else
            {
                right = left.substr(0, left.size() - 1);
            }
            reverse(right.begin(), right.end());
            return left + right;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << next(s) << endl;
    }
    return 0;
}