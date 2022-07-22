#include <iostream>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int x;
        cin>>n>>x;
        if (x == 1)
        {
            cout << "Yes" << endl;
        }

        else
        {
            if (x == n * n)
                cout << "Yes" << endl;
            else if (x % n == 0)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}
