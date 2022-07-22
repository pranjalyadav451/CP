#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
class Solution {
private:
    bool helper(int arr[], int n, int target, int pos)
    {

        int i = 0;
        int j = n - 1;
        while (i < j)
        {

            if (i == pos) i++;
            if (j == pos) j--;

            if (arr[i] + arr[j] == target)
                return true;
            else if (arr[i] + arr[j] > target)
                j--;
            else
                i++;
        }
        return false;
    }

public:
    bool findTriplets(int arr[], int n)
    {
        if (n == 0)
            return 0;
        sort(arr, arr + n);
        for (int i = 0; i < n; ++i)
        {
            if (helper(arr, n, -arr[i], i))
                return true;
        }
        return false;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n] = {0};
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        if (obj.findTriplets(arr, n))
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }
    return 0;
}