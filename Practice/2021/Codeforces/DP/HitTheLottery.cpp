#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int t;
    cin >> t;
    // int bill = 100;
    long long int count = 0;
    while (t > 0)
    {
        // cout << "value of t" << t << endl;
        // cout << "inside this loop" << endl;
        if (t >= 100)
        {
            // cout << "inside 1" << endl;
            count += t / 100;
            t = t % 100;
        }
        else if (t >= 20)
        {
            // cout << "inside 2" << endl;
            count += t / 20;
            t = t % 20;
        }
        else if (t >= 10)
        {
            // cout << "inside 3" << endl;
            count += t / 10;
            t = t % 10;
        }
        else if (t >= 5)
        {
            // cout << "inside 4" << endl;
            count += t / 5;
            t = t % 5;
        }
        else if (t < 5)
        {
            // cout << "inside the break one" << endl;
            count += t ;
            break;
        }
        // else
        // {
        //     break;
        // }
        // cout << count << endl;
        // cout << endl;
        // cout << endl;
    }
    cout << count  << endl;

    return 0;
}