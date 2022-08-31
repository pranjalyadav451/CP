#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    if (a == b)
    {
        if (c == 1)
            cout << "Takahashi" << endl;
        else
            cout << "Aoki" << endl;
        return 0;
    }
    else
    {
        if (a > b)
        cout << "Takahashi" << endl;
        else
        cout << "Aoki" << endl;
    }
    
}