// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int findNumberOfTriangles(int arr[], int n)
    {
        long long int count = 0;
        sort(arr, arr + n);
        for (size_t i = 0; i < n; i++)
        {
            int k = i + 2;
            for (size_t j = i + 1; j < n; j++)
            {
                while (k < n and arr[i] + arr[j] > arr[k])
                    k++;
                count += k - 1 - j;
            }
        }
        return count;
    }
};

// { Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.findNumberOfTriangles(arr, n) << endl;
    }
    return 0;
} // } Driver Code Ends