#include "activity.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int select(Activity A[], int n) {
	if (n == 0)	return 0;
	int ret = 0, r = INT_MIN;
	
	for (; ;) {
		int tmp = INT_MAX, idx = -1;
		for (int i = 0; i < n; i++) {
			if (A[i].start >= r) {
				if (A[i].end <= tmp)
					tmp = A[i].end, idx = i;
			}
		}
		if (idx == -1)
			break;
#ifdef PRINT
		printf("%d %d\n", A[idx].start, A[idx].end);
#endif
		r = tmp, ret++;
	}
	return ret;
}
