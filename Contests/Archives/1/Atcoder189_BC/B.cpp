#include <bits/stdc++.h>
using namespace std;
// I got errors because we are dividing by 100 and the
// variables are int type so we are losing precision
// instead I multiplied 'x' to 100 and now we don't have
// to divide and that takes care of the precision loss in the
// earlier code
int main()
{
    int n;
    cin >> n;
    int x;
    cin >> x;
    x *= 100;
    //just multiplying x by 100 so that we don't have
    // to divide when calculating the volume of alcohol in
    // each glass
    int val, per;
    vector<pair<int, int>> alc;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        cin >> per;
        alc.push_back(make_pair(val, per));
    }
    vector<int> milli;
    long long int volume;
    for (int i = 0; i < n; i++)
    {
        // volume = alc[i].first * alc[i].second/100;
        // as we have multiplied x by 100
        volume = alc[i].first * alc[i].second;
        milli.push_back(volume);
    }
    // sort(milli.begin(), milli.end());
    // bool isDrunk = false;
    long long int sum = 0;
    // int count = 0;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (sum + milli[i] <= x)
        {
            sum += milli[i];
            flag = false;
        }
        else
        {
            cout << i + 1 << endl;
            flag = true;
            break;
        }
    }
    if (flag == false)
        cout << -1 << endl;

    return 0;
}