#include "matrix.h"
#define LOOP_UNROLL 8
void transpose(int N, UINT A[][2048]) {
	UINT t;
	for (int i = 0; i < N; i++)
        for (int j = i+1; j < N; j++)
        	t = A[i][j], A[i][j] = A[j][i], A[j][i] = t;
}
void multiply(int N, UINT A[][2048], UINT B[][2048], UINT C[][2048]) {
	transpose(N, B);
	int chunk = 8;
	#pragma omp parallel for schedule(dynamic, chunk) shared(A, B, C)
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			register UINT sum = 0;
			UINT *a = &A[i][0], *b = &B[j][0];
			int k;
			for (k = 0; k+LOOP_UNROLL < N; k += LOOP_UNROLL) {
				sum += *a * *b, a++, b++;
				sum += *a * *b, a++, b++;
				sum += *a * *b, a++, b++;
				sum += *a * *b, a++, b++;
				sum += *a * *b, a++, b++;
				sum += *a * *b, a++, b++;
				sum += *a * *b, a++, b++;
				sum += *a * *b, a++, b++;
			}
			for (; k < N; k++)
				sum += *a * *b, a++, b++;
			C[i][j] = sum;
		}
	}
}
