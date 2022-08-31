#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
class Solution {
public:
    ull getNthUglyNo(int n)
    {
        if (n == 1 or n == 2 or n == 3 or n == 4 or n == 5 )
            return n;

        ull uglyNum[n];
        uglyNum[0] = 1;

        ull two = 2, three = 3, five = 5;

        ull i2 = 0, i3 = 0, i5 = 0;



        ull choice = 1;
        for (int i = 1; i < n; i++)
        {

            choice = min(two, min(three, five));
            cout << two << "\t" << three << "\t" << five << endl;
            uglyNum[i] = choice;

            if (choice == two)
            {
                i2++;
                two = uglyNum[i2] * 2;
            }
            if (choice == three)
            {
                i3++;
                three = uglyNum[i3] * 3;
            }
            if (choice == five)
            {
                i5++;
                five = uglyNum[i5] * 5;
            }

        }

        return choice;
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
        cout << endl;
        cout << endl;
    }
    return 0;
}