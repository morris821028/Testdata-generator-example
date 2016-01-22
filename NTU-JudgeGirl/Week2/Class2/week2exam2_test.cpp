#include <stdio.h> 
#include <stdlib.h>
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))
#define MAXN 1000005
int A[MAXN];
int main() {
	int N, K;
	while (scanf("%d", &K) == 1) {
		N = 0;
		while (scanf("%d", &A[N]) == 1 && A[N])
			N++;
		int ret = 0;
		for (int i = 0; i < N; i++) {
			if (A[i] > 0) {
				int alt = 1, seg = 0, j = i;
				while (j < N && A[j]) {
					if (alt == 1) {
						int cnt = 0;
						for (; j < N && A[j] > 0; j++)
							cnt++;
						if (cnt >= K) {
							if (seg+1 >= 3)
								ret = max(ret, seg+1);
						} else {
							break;
						}
						if (cnt > K)
							break;
						seg++;
					} else {
						int cnt = 0;
						for (; j < N && A[j] < 0; j++)
							cnt++;
						if (cnt != K)
							break;
						seg++;
					}
					alt = -alt;
				}
			}
		}
		printf("%d\n", ret*K);
	}
	return 0;
}
/*
2
-3 4 6 -5 -3 10 7 -1 -1 3 -7 3 0

*/

