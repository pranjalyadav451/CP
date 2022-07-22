
#include<cstdio>
#include<math.h>
#include<string.h>
#define N 10000000
bool P[10000001];
void makePrime() {
	memset(P, false, sizeof(P));
	int limit = sqrt((double)N);
	for (int i = 2; i <= limit; i++) {
		if (!P[i]) {
			for (long long j = i; j * i < N; j++)
				P[j * i] = true;
		}
	}
}
void Goldbach(int n) {
	for (int i = 2;; i++) {
		if (!P[i] && !P[n - i]) {
			printf("%d %d", i, n - i);
			return;
		}
	}
}
int main() {
	makePrime();
	int n;
	while (scanf("%d", &n) == 1) {
		if (n < 8)
			puts("Impossible.");
		else {
			if (n % 2 == 0)
				printf("%d %d ", 2, 2), n -= 4;
			else
				printf("%d %d ", 2, 3), n -= 5;

			/* ^^ if the Number is odd we subtract odd from
			it to make the remaining number even and then apply goldbach conjecture.
			 for an even number the ans is straight forward.
			 any number less than 8 cannot be broken into four
			 prime parts because we need the number to be greater than or equal to 4 for it
			 so that it can be broken into two prime parts.
			 and since 4 + 4 = 8, we need the number to be atleast 8.
			*/
			Goldbach(n);
			putchar('\n');
		}
	}
	return 0;
}