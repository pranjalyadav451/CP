/*
 ID: bradyawn
 PROG: contest
 LANG: C++11
 */

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
	//ifstream inf("");
	//ofstream outf("");
	//cout << setprecision(10);

	int n;
	cin >> n;

	//vector<int> time(n+1);

	vector<int> room(n + 1, -1); //room at time i

	room[0] = 1;

	int ret = 1;

	for (int i = 1; i <= n; i++)
	{
		int time;
		cin >> time;

		// If a previous room at the noted time exists, then the rooms can be same.
		if (room[time] != -1) {
			room[i] = room[time];
			room[time] = -1;
			// the room at notedTime is destroyed as it's the same previous room.
		}
		else {
			// Create a new room at 'i' and increase the number of rooms.
			ret++;
			room[i] = ret;
		}
	}
	cout << ret << endl;
	return 0;
}
/**
 * This is a good approach.
*/