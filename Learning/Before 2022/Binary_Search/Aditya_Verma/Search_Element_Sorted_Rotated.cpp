#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl
#define dbgg(x, y) cout << #x << ": " << x << ", " << #y << ": " << y << endl
class Solution {
public:
    int search(int arr[], int left, int right, int key) {
        int n = right + 1;
        int mid = 0 , ans = - 1;
        while (left <= right) {
            mid = left + (right - left) / 2;
            int pre = (mid - 1 + n) % n, next = (mid + 1) % n;
            if (arr[mid] < arr[pre] and arr[mid] < arr[next]) {
                ans = mid;
                break;
            }
            if (arr[mid] < arr[right]) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        right = n - 1; left = 0;
        if (key <= arr[right]) {
            left = ans;
        }
        else {
            right = ans - 1;
        }

        while (left <= right) {
            mid = left + (right - left) / 2;
            if (arr[mid] == key) {
                return mid;
            }
            else if (arr[mid] > key) { right = mid - 1;}
            else if (arr[mid] < key) { left = mid + 1;}
        }
        return - 1;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
    return 0;
}