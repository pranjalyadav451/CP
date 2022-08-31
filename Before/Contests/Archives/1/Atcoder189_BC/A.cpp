#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    char c = s[0];
    bool flag = true;
    for (int i = 1; i < 3; i++)
    {
        if (c != s[i] and isupper(s[i]))
        {
            flag = false;
        }
    }
        
    if (flag)
        cout << "Won" << endl;
    else
        cout << "Lost" << endl;
    return 0;
}