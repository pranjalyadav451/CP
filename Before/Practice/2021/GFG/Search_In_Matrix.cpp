// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bin(vector<int> &arr, int x) {
        int left = 0 , right = arr.size() - 1, mid = 0 , ans = -1;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (arr[mid] <= x) {
                ans = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1 ;
            }
        }
        return ans;
    }
    int matSearch (vector <vector <int>> &mat, int N, int M, int X)
    {
        int find_col = bin(mat[0], X);
        if (find_col == -1) return 0;
        for (int i = 0; i < N; i++) {
            if (mat[i][find_col] == X) return true;
        }
        return false;
    }
};


int main ()
{
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];

        int x; cin >> x;
        Solution ob;
        cout << ob.matSearch (arr, n, m, x) << endl;
    }
}