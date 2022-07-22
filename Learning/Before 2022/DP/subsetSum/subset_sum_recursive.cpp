#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
public:
    int subsetSum(int N, int arr[], int target)
    {
        if (target == 0)
            return true;
        else if (N == 0)
            return false;
        else
        {
            if (target >= arr[N - 1])
            {
                return subsetSum(N - 1, arr, target - arr[N - 1]) or subsetSum(N - 1, arr, target);
            }
            else
                return subsetSum(N - 1, arr, target);
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)

    {
        int target = 0;
        cin >> target;
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.subsetSum(N, arr, target))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
public:
    int subsetSum(int N, int arr[], int target)
    {
        if (target == 0)
            return true;
        else if (N == 0)
            return false;
        else
        {
            if (target >= arr[N - 1])
            {
                return subsetSum(N - 1, arr, target - arr[N - 1]) or subsetSum(N - 1, arr, target);
            }
            else
                return subsetSum(N - 1, arr, target);
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)

    {
        int target = 0;
        cin >> target;
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.subsetSum(N, arr, target))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}