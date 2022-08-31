#include<bits/stdc++.h>
using namespace std;
int main() {

    string s;
    cin >> s;

    unordered_set<string>ans;
    int len = s.size();
    int p = 0, k = 0, h = 0, t = 0;
    string temp = "";
    bool flag = true;

    for (int i = 0; i < len; i += 3)
    {
        temp = s.substr(i, 3);
        // cout << temp << endl;
        if (ans.count(temp) == 0)
        {

            ans.insert(temp);
            if (s[i] == 'P')
                p++;
            if (s[i] == 'K')
                k++;
            if (s[i] == 'H')
                h++;
            if (s[i] == 'T')
                t++;

        }
        else
        {
            flag = false;
            cout << "ERROR" << endl;
            break;
        }
    }
    // cout << flag << endl;
    if (flag)
    {
        cout << 13 - p << " " << 13 - k << " " << 13 - h << " " << 13 - t << endl;
    }

    // Write your code here
}