#include <bits/stdc++.h>
#define ll long long
#define vec vector
#define MOD 1000000007
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ff first
#define ss second
#define read(x) cin>>x
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define deb(x) cout << #x << ": " << x << endl
#define deb2(x, y) cout << #x << ": " << x << ", " << #y << ": " << y << endl

using namespace std;

string solve(vector<int>&arr, int n, int xa)
{

	if (xa == 0)
		return "YES";
	xa = 0;
	int other = 0;
	bool isMid = false;

	rep(i, 0, n - 1)
	{
		xa ^= arr[i];
		other = 0;	isMid = false;

		rep(j, i + 1, n)
		{
			other ^= arr[j];
			if (other == xa)
				isMid = true;
		}

		if (other == 0 and isMid == true)
			return "YES";
	}


	return "NO";
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int tt;
	cin >> tt;
	while (tt--)
	{
		int n;
		cin >> n;
		vector<int>arr(n);

		int xa = 0;

		rep(i, 0, n)
		{
			cin >> arr[i];
			xa ^= arr[i];
		}

		cout << solve(arr, n, xa) << endl;

	}
}

/*
    Editorial -:
		So let's try to understand what the final array looks like
		in terms of the initial array. The best way to see this is
		to look at the process backwards. Basically, start with the
		final array, and keep replacing an element with the 2
		elements that xor-ed down to it, until you get the initial
		array. You'll see that the first element turns into a
		prefix, the second element turns into a subarray that
		follows this prefix, and so on. Hence, the whole process of
		moving from the initial to the final array is like we
		divide the array into pieces, and then replace each piece
		with its xor, and we want these xors to be equal. A nice
		observation is: we need at most 3 pieces. That's because if
		we have 4 or more pieces, we can take 3 pieces and merge
		them into one. Its xor will be the same, but the total
		piece count will decrease by 2. Now, checking if you can
		divide it into 2 or 3 pieces is a simple task that can be
		done by bruteforce. You can iterate over the positions
		you'll split the array, and then check the xors are equal
		using a prefix-xor array or any other method you prefer.

		Additional idea: for 2 pieces, you don't even need bruteforce. It's sufficient to check the xor of the whole array is 0. Hint to see this: write the bruteforce.
*/