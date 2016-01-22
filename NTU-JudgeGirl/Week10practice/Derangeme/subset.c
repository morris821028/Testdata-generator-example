#include "subset.h"
#include <stdlib.h>

static int dfs(int A[], int suf[], int n, int K, int S) {
	if (S == 0 && K == 0)
		return 1;
	if (K < 0 || S < 0 || n == 0 || K > suf[0])
		return 0;
	return dfs(A+1, suf+1, n-1, K-A[0], S-1) || dfs(A+1, suf+1, n-1, K, S);
}
static int cmp(const void *a, const void *b) {
	return *(int *) a - *(int *) b;
}
int subset(int A[], int n, int K, int S) {
	qsort(A, n, sizeof(int), cmp);
	static int suffix[128];
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += A[i], suffix[i] = sum;
	return dfs(A, n, K, S);
}
