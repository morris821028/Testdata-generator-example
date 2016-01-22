#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int cmp(const void *a, const void *b) {
	int *x = (int *) a;
	int *y = (int *) b;
	if (x < y)	return -1;
	if (x > y)	return 1;
	return 0;
}

#define MAXN 1024
#define iswap(x, y) {int t = x; x = y, y = t;}
int n, ndiv2, A[MAXN];
int used[MAXN], path[MAXN];

int dfs(int idx) {
	if (idx == n-1) {
		int lw = 0, rw = 0;
		for (int i = 0, j = 1; i < ndiv2; i++, j++)
			lw += j * path[i];
		for (int i = ndiv2, j = 1; i < idx; i++, j++)
			rw += j * path[i];
		if (lw == rw) {
			for (int i = ndiv2-1; i >= 0; i--)
				printf("%d ", path[i]);
			printf("_^_");
			for (int i = ndiv2; i < idx; i++)
				printf(" %d", path[i]);
			puts("");
			return 1;
		}
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if (used[i])	continue;
		used[i] = 1;
		path[idx] = A[i];
		if (dfs(idx+1))
			return 1;
		used[i] = 0;
	}
	return 0;
}
int main() {
	while (scanf("%d", &n) == 1) {
		for (int i = 0; i < n; i++)
			scanf("%d", &A[i]);
			
		ndiv2 = n/2;
//		qsort(A, n, sizeof(int), cmp);
		memset(used, 0, sizeof(used));
		int ret = dfs(0);
		if (ret == 0)
			puts("N");
	}
	return 0;
}
