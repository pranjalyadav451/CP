#include<bits/stdc++.h>

using namespace std;
int minSwaps(int arr[], int n)
{
    pair<int, int> arrPos[n];
    for (int i = 0; i < n; i++)
    {
        arrPos[i].first = arr[i];
        arrPos[i].second = i;
    }
    sort(arrPos, arrPos + n);

    vector<bool> vis(n, false);

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (vis[i] || arrPos[i].second == i)
            continue;

        int cycle_size = 0;
        int j = i;
        while (!vis[j])
        {
            vis[j] = 1;

            j = arrPos[j].second;
            cycle_size++;
        }
        cout << "cycle_size : " << cycle_size << endl;

        if (cycle_size > 0)
        {
            ans += (cycle_size - 1);
        }
    }

    return ans;
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << minSwaps(arr, n) << endl;
    }
    return 0;
}
