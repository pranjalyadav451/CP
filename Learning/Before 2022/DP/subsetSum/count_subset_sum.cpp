#include <bits/stdc++.h>
#define ll long long
using namespace std;
int countSubsetSum(int n, int arr[], int target) {
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        int target;
        cin >> target;
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << countSubsetSum(n, arr, target) << endl;
    }
    return 0;
}
