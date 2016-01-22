#include <stdio.h>
#include "snake.h"

int simulate(int **score, int ***towhere, int step) {
	int sum = 0;
	int **pos = score;
	for (int it = 0; it < step; it++) {
		if (*pos == NULL)
			return sum;
		sum += **pos;
		int offset = pos - score;
		printf("%d\n", **pos);
		if (towhere[offset] != NULL) {
			pos = towhere[offset];
		} else {
			pos++;
		}
	}
}
