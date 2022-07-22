// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends

void print(std::vector<int> v)
{
	for (int a : v)
		cout << a << "  ";
	cout << endl;
}
vector<int> greatestInRight(int arr[], int len)
{
	int rightM = -1;
	std::vector<int> res;
	for (int i = len - 1; i >= 0; --i)
	{
		if (arr[i] > rightM)
		{
			rightM = arr[i];
			res.push_back(-1);
		}
		else {
			res.push_back(rightM);
		}
	}
	reverse(res.begin(), res.end());
	return res;
}
vector<int> greatestInLeft(int arr[], int len)
{
	int leftM = -1;
	std::vector<int> res;
	for (int i = 0; i < len; ++i)
	{
		if (arr[i] > leftM)
		{
			leftM = arr[i];
			res.push_back(-1);
		}
		else {
			res.push_back(leftM);
		}
	}
	return res;
}
int trappingWater(int height[], int n)
{
	vector<int>right = greatestInRight(height, n);
	vector<int>left = greatestInLeft(height, n);
	// print(left);
	// print(right);

	int effective = 0;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (right[i] != -1 and left[i] != -1)
		{
			// cout << "right ->" << right[i] << endl;
			// cout << "left ->" << left[i] << endl;
			effective = min(right[i], left[i]);
			sum += effective - height[i];
		}
	}
	return sum;
}


// { Driver Code Starts.

int main() {

	int t;
	//testcases
	cin >> t;

	while (t--) {
		int n;

		//size of array
		cin >> n;

		int a[n];

		//adding elements to the array
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		//calling trappingWater() function
		cout << trappingWater(a, n) << endl;

	}

	return 0;
}  // } Driver Code Ends