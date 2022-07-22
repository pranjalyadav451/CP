#include "bits/stdc++.h"
using namespace std;

#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;

#define X first
#define Y second
set<pair<int, int>> ok;
map<pair<int, int>, int> dist;
int main()
{
	int Xi, Yi, Xf, Yf, N;
	cin >> Xi >> Yi >> Xf >> Yf >> N;

	for (int i = 0; i < N; i++) {
		int r, a , b;
		cin >> r >> a >> b;
		for ( int i = a; i <= b; i++ ) ok.insert(make_pair(r, i));
	}

	queue<pair<int, int>> q;

	dist[make_pair(Xi, Yi)] = 0;
	q.push(make_pair(Xi, Yi));

	while ( !q.empty() ) {
		int x = q.front().X;
		int y = q.front().Y;
		int d = dist[make_pair(x, y)];
		q.pop();

		for ( int i = -1; i <= 1; i++ )
			for ( int j = -1; j <= 1; j++ ) {
				pair<int, int> np = make_pair(x + i, y + j);
				if (dist.count(np) || !ok.count(np) )
					continue;
				q.push(np);
				dist[np] = d + 1;
			}
	}
	int ans = dist.count({Xf, Yf}) == 0 ? -1 : dist[ {Xf, Yf}];
	cout << ans << endl;
	return 0;
}

