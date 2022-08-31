#include <bits/stdc++.h>
#define ll long long
using namespace std;

string findSum(string str1, string str2)
{
    // Before proceeding further, make sure length
    if (str1.length() > str2.length())
        swap(str1, str2);

    // Take an empty string for storing result
    string str = "";

    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();
    int diff = n2 - n1;

    // Initially take carry zero
    int carry = 0;

    // Traverse from end of both strings
    for (int i = n1 - 1; i >= 0; i--)
    {
        // Do school mathematics, compute sum of
        // current digits and carry
        int sum = ((str1[i] - '0') +
                   (str2[i + diff] - '0') +
                   carry);
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    // Add remaining digits of str2[]
    for (int i = n2 - n1 - 1; i >= 0; i--)
    {
        int sum = ((str2[i] - '0') + carry);
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    // Add remaining carry
    if (carry)
        str.push_back(carry + '0');

    // reverse resultant string
    reverse(str.begin(), str.end());

    return str;
}
// 1717227171 1234321 234590353095432 3489053553509843 12344321 8459341439548 12344321 99098189099 4567557654 9609047409069

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        string str;
        cin >> str;
        int left = 0, right = str.size() - 1;
        int no_so_far = 0;

        if (str.compare("9") == 0)
        {
            cout << 11 << endl;
            continue;
        }
        while (left <= right)
        {
            if (str[left] < str[right])
                no_so_far = -1;
            else if (str[left] > str[right])
                no_so_far = 1;

            left++;
            right--;

            //cout<<" -> "<<no_so_far<<endl;
        }
        int endp = (str.size() + 1) / 2;
        //cout<<str<<" "<<endp<<endl;

        string Left = str.substr(0, endp);

        if (no_so_far != 1)
            Left = findSum(Left, "1");

        // cout<<no_so_far<<endl;
        cout << Left;

        int remainLength = str.size() / 2;

        for (int i = remainLength - 1; i >= 0; i--)
            cout << Left[i];

        cout << endl;
    }
    return 0;
}