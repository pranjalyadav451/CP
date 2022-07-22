#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


class Solution
{
public:
	void merge(int arr[], int l, int m, int r)
	{
		int L[m - l + 1], R[r - m];
		for (int i = l; i <= m; i++) {
			L[i] = arr[i];
		}
		for (int i = m + 1; i <= r; i++) {
			R[i] = arr[i];
		}

		int left = l , right = m + 1, final = l;
		for (int i = l; i <= r; i++) {
			if (L[left] < R[right]) {
				arr[i] = L[left];
				left++;
			}
			else {
				arr[i] = R[right];
				right++;
			}
			final++;
			if (left > m or right > r) break;
		}

		while (left <= m) {
			arr[final++] = L[left++];
		}
		while (right <= r) {
			arr[final++] = R[right++];
		}
	}
public:
	void mergeSort(int arr[], int l, int r)
	{
		if (l < r) {
			int mid = l + (r - l) / 2;
			mergeSort(arr, l, mid);
			mergeSort(arr, mid + 1, r);
			merge(arr, l, mid, r);
		}

	}
};



int main()
{
	int n, T, i;

	scanf("%d", &T);

	while (T--) {

		scanf("%d", &n);
		int arr[n + 1];
		for (i = 0; i < n; i++)
			scanf("%d", &arr[i]);

		Solution ob;
		ob.mergeSort(arr, 0, n - 1);
		printArray(arr, n);
	}
	return 0;
}