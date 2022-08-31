// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int M[MAX][MAX];
//the problem in this code was the large size of the array declared
//inside main
//and it should have been declared on the heap for the program to work
// on my local machine.
int maxArea(int M[MAX][MAX], int n, int m);
int main()
{

	int T;
	cin >> T;
	while (T--)
	{
		int n, m;
		cin >> n >> m;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> M[i][j];
			}
		}
		cout << maxArea(M, n, m) << endl;
	}
}
// } Driver Code Ends

/*You are required to complete this method*/
int getMaxArea(int arr[], int len)
{

	stack<int> load;
	int hIndex = 0;
	int currentArea = 0;
	int largestArea = 0;
	for (int i = 0; i < len; i++)
	{
		while (!load.empty() and arr[i] < arr[load.top()])
		{
			hIndex = load.top();
			load.pop();
			if (!load.empty())
			{
				currentArea = arr[hIndex] * (i - load.top() - 1);
			}
			else
			{
				currentArea = arr[hIndex] * (i);
			}
			largestArea = max(largestArea, currentArea);
		}
		load.push(i);
		largestArea = max(largestArea, currentArea);
	}
	while (not load.empty())
	{
		hIndex = load.top();
		load.pop();
		if (load.empty() == false)
		{
			currentArea = (len - load.top() - 1) * arr[hIndex];
		}
		else
		{
			currentArea = (len)*arr[hIndex];
		}
		largestArea = max(largestArea, currentArea);
	}
	return largestArea;
}
int maxArea(int M[MAX][MAX], int n, int m)
{

	int array[MAX];
	for (int i = 0; i < m; i++)
		array[i] = 0;
	long long int large = 0;
	long long int curr = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (M[i][j] == 0)
				array[j] = 0;
			else
				array[j] += M[i][j];
		}
		curr = getMaxArea(array, m);
		if (curr > large)
			large = curr;
	}

	return large;
}

// } Driver Code Ends