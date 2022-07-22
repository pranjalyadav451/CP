#include <bits/stdc++.h>

using namespace std;

int solve(string a) {
	// cout << a << endl;
	int n = a.size();
	int left = 0, right = n - 1;
	int count = 0;
	while (left <= right) {
		if (a[left] == a[right]) {
			left++;
			right--;
		}
		else {
			count++;
			if (left < right) {
				if (a[left + 1] == a[right]) {
					left += 2;
					right--;
				}
				else if (a[right - 1] == a[left]) {
					right -= 2;
					left++;
				}
				else {
					return 0;
				}
			}
		}
		if (count == 2) {
			return 0;
		}
	}
	return 1;
}



int main()
{

	int tt;
	cin >> tt;
	while (tt--) {
		string a;
		cin >> a ;
		// cout << a << endl;
		cout << solve(a) << endl ;
	}
}

/*
    Notes -:
*/