#include <bits/stdc++.h>
using namespace std;
void swap(char &a, char &b)
{
    char t = a;
    a = b;
    b = t;
}
//What if the element has duplicate characters
/*
    Two Solutions -
    -> Use a set on the result that you obtain
        ->problems with this approach 
            ->we will still have to work the same amount of operations
    ->instead, use a set on the characters of the string
        ->How?
            ->one distinct character should be selected at a position only once
            and then we find all the permutations keeping that character set at that position.
            ->we do the above step at each instance of 
            recursion.
*/
void allPermutations(string s, string osf = "")
{
    if (s.size() == 0)
    {
        cout << osf << endl;
        return;
    }
    unordered_set<char> nodup;
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        if (nodup.count(ch) == 0)
        {
            string sub = s.substr(0, i) + s.substr(i + 1);
            nodup.insert(ch);
            allPermutations(sub, osf + ch);
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        //cout << t;
        string s;
        cin >> s;
        allPermutations(s);
    }
    return 0;
}