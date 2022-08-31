#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;

class Solution
{
public:
    string printLcs(int x, int y, string s1, string s2)
    {
        if (x == 0 or y == 0)
            return "";

        else
        {
            string res;
            if (s1[x - 1] == s2[y - 1])
                return printLcs(x - 1, y - 1, s1, s2) + s1[x - 1];
            else
            {
                string temp1 = printLcs(x - 1, y, s1, s2);
                string temp2 = printLcs(x, y - 1, s1, s2);

                if (temp1.size() > temp2.size())
                    return temp1;
                else
                    return temp2;
            }
            // return res;
        }
    }
};

int main()
{
    int t, x, y;
    cin >> t;
    while (t--)
    {
        cin >> x >> y;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;
        cout << ob.printLcs(x, y, s1, s2) << endl;
    }
    return 0;
}