## **Questions**
-- -
## **D**
- Problem based on lexicographical order of strings containing two characters.
- Learnt how to generate all the possible combinations of C(n, r) effectively.
```cpp
/**
 * Using the formula C(n,r) = C(n-1,r) + C(n-1,r-1)
**/
for (int i = 0; i <= 60; i++) {
	for (int j = 0; j <= i; j++) {
		if (j == 0) {
			dp[i][j] = 1;
		}
		else {
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
		}
	}
}
```
- Learnt how to apply Combinatorics to determine at which position (lexicographically) some string (containing two characters) is going to be.
```cpp
/** n = number of total characters in string.
    a - Number of a's
    b - Number of b's
**/
ll n = a + b;
while (n > 0) {
	if (grid[n - 1][b] >= k) {
		cout << 'a' ;
	}
	else {
		k = k - grid[n - 1][b];
		cout << 'b';
		b--;
	}
	n--;
}
cout << endl;
```

