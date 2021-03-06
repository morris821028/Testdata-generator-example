#include <stdio.h>
#include <stdlib.h>
#define MAXN 32
int N, M, K, D;
int A[MAXN][MAXN], B[MAXN][MAXN];
int match(int lx, int ly) {
	int s1 = 0, s2 = 0, miss = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			s1 += A[i+lx][j+ly], s2 += B[i][j];
			miss += B[i][j] != A[i+lx][j+ly];
		}
	}
	return abs(s1-s2) <= D && miss <= K;
}
int main() {
	while (scanf("%d %d", &N, &M) == 2) {
		scanf("%d %d", &K, &D);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				scanf("%d", &A[i][j]);
		for (int i = 0; i < M; i++)
			for (int j = 0; j < M; j++)
				scanf("%d", &B[i][j]);
		int rx = -1, ry = -1;
		for (int i = 0; i <= N-M; i++)
			for (int j = 0; j <= N-M; j++)
				if (match(i, j))
					rx = i, ry = j;
		printf("%d %d\n", rx, ry);
	}
	return 0;
}
/*
3 3 1 1
1 2 3
4 5 6
7 8 9
1 2 3
4 7 6
7 8 5

3 3 2 2
1 2 3
4 5 6
7 8 9
1 2 3
4 7 6
7 8 5

5 2 0 0
1 1 0 0 0
1 1 1 0 0
0 1 1 0 0
0 0 1 1 0
0 0 1 1 0
1 1
1 1

5 2 2 0
1 1 0 0 0
1 1 1 0 0
0 1 1 0 0
0 0 1 1 3
0 0 1 1 -1
1 1
1 1
*/
