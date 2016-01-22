#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAXN 262144
#define MAXD 2
#define INF INT_MAX
int min(int x, int y) {return x < y ? x : y;}
int A[MAXN][MAXD], B[MAXN][MAXD];
int solve(int A[][MAXD], int n, int B[]) {
	int mndist = INT_MAX, dist;
	for (int i = 0; i < n; i++) {
		dist = abs(A[i][0] - B[0]) + abs(A[i][1] - B[1]);
		mndist = min(mndist, dist);
	}
	return mndist;
}
int main() {
	int N;
	while (scanf("%d", &N) == 1) {
		for (int i = 0; i < N; i++) {
			scanf("%d %d", &A[i][0], &A[i][1]);
			if (i)
				printf("%d\n", solve(B, i, A[i]));
			scanf("%d %d", &B[i][0], &B[i][1]);
			printf("%d\n", solve(A, i+1, B[i]));
		}
	}
	return 0;
}

