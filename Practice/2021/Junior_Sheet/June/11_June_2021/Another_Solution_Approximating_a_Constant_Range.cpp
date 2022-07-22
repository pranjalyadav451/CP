#include <bits/stdc++.h>
using namespace std;

int N, a[100010], ans;
multiset <int> S;

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &a[i]);

	for (int i = 1, j = 1; i <= N; i++)
	{
		for (; j <= N; j++)
		{
			S.insert(a[j]);
			if (*(--S.end()) - *S.begin() > 1)
			{
				S.erase(S.find(a[j]));
				break;
			}
		}
		ans = max(ans, j - i);
		S.erase(S.find(a[i]));
	}

	printf("%d", ans);
}
