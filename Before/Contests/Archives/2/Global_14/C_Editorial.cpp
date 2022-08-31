#include <bits/stdc++.h>
using namespace std;

int N, M, X;
int H[100001];

/**
 * REAL COOL IMPLEMENTATION
*/

void solve()
{
    cin >> N >> M >> X;
    cout << "YES" << endl;

    set<pair<int, int>> s; //stores pairs of (height, index)

    for (int i = 1; i <= M; i++)
        s.insert({0, i});

    for (int i = 0; i < N; i++)
    {
        cin >> H[i];
        auto p = s.begin();

        s.erase(p);
        cout << p->second << ' ';

        s.insert({p->first + H[i], p->second});
    }

    cout << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
}

/**
	Greedily adding blocks to the current shortest tower will always give a valid solution. 
    Let's prove it with contradiction. If the towers weren't beautiful, then some two towers would have a height difference of more than x. Since a single block cannot exceed a height of x, the difference would be more than one block. 
    This is a contradiction with our solution because we always add to the shortest tower.

	To implement this, we can use a set-like structure and store pairs of (hi, i) for each i 
	(1≤i≤m), where hi is the current height of the i-th tower (initialized to 0). When adding a 
	block, we remove the first element of the sorted set, update the tower height, and add it 
	back into the set.

	Time complexity for each test case: O(nlogn)
*/