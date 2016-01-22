#include <stdio.h>
#include <math.h>

#define MAXN 128
#define eps 1e-6
double mtx[MAXN][MAXN+1];
void compute(int n, int m) {
    int var = n, equ = m;
    int row = 0, col = 0, arb = 0;
    while (row < equ && col < var) {
    	int c = row;
    	for (int j = row; j < equ; j++)
            if (fabs(mtx[c][col]) < fabs(mtx[j][col]))
                c = j;
        for (int j = 0; j <= var; j++) {
        	double t;
        	t = mtx[c][j], mtx[c][j] = mtx[row][j], mtx[row][j] = t;
		}
        if (fabs(mtx[row][col]) < eps) {
        	col++, arb++;
        	continue;
		}
		for (int j = 0; j < equ; j++) {
            if (row == j) continue;
            for (int k = var; k >= 0; k--)
                mtx[j][k] -= mtx[j][row]/mtx[row][col]*mtx[row][k];
        }
        row++, col++;
	}
}
double g[MAXN][MAXN];
int test_single(int id, int n, int m, double *score) {
	double v[MAXN] = {};
	for (int j = 0; j < m; j++) {
		if (fabs(v[j]-g[id][j]) < eps)
			continue;
		for (int p = 0; p < n; p++) {
			int c = -1;
			for (int q = 0; q < m; q++) {
				if (fabs(mtx[p][q]) > eps) {
					c = q;
					break;
				}
			}
			if (c == j) {
				double multi = (g[id][j] - v[j]) / mtx[p][c];
				for (int q = 0; q <= m; q++)
					v[q] += mtx[p][q] * multi;
				break;
			}
		}
	}
	for (int j = 0; j < m; j++) {
		if (fabs(g[id][j] - v[j]) > eps) {
			return 1;
		}
	}
	*score = v[m];
	return 0;
}
int test_input(int n, int m) {
	for (int i = 0; i < n; i++) {
		double score;
		if (test_single(i, n, m, &score))
			return 1;
		if (fabs(score - g[i][m]) > eps)
			return 1;
	}
	return 0;
}
void solve(int n, int m) {
	double score;
	if (test_single(n, n, m, &score))
		puts("not sure");
	else
		printf("%.0lf\n", score);
}
int main() {
	int n, m, x;
	while (scanf("%d %d", &n, &m) == 2) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= m; j++) {
				scanf("%lf", &g[i][j]);
				mtx[i][j] = g[i][j];
			}
		}
		compute(m, n);
		
		for (int i = 0; i < m; i++)
			scanf("%lf", &g[n][i]);
		if (test_input(n, m))
			puts("contradictory");
		else
			solve(n, m);
	}
	return 0;
}

