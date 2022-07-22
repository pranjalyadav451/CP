// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int isValid(vector<vector<int>> mat) {
        // code here
        int valid = 0;
        vector<vector<int>> horizon, vertical;
        for (int i = 0; i < 9; i++) {
            horizon.push_back(mat[i]);
            vector<int> temp;
            for (int j = 0; j < 9; j++) {
                temp.push_back(mat[j][i]);
            }
            vertical.push_back(temp);
        }

        vector<int> subgrid(9);
        for (int times = 0; times < 9; times++) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {

                }
            }
        }

        return valid ;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for (int i = 0; i < 81; i++)
            cin >> mat[i / 9][i % 9];

        Solution ob;
        cout << ob.isValid(mat) << "\n";
    }
    return 0;
}