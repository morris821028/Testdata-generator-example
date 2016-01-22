#include <bits/stdc++.h>
using namespace std;

class GAUSSIAN { // Gaussian Elimination
public:
    static const int MAXN = 16;
    double mtx[MAXN][MAXN+1], varx[MAXN];
    int exist[MAXN];
    void compute(int n, int m) {
        const double eps = 1e-12;
        int var = n, equ = m;
        int row = 0, col = 0, arb = 0;
        while (row < equ && col < var) {
        	int c = row;
        	for (int j = row; j < equ; j++)
                if (fabs(mtx[c][col]) < fabs(mtx[j][col]))
                    c = j;
            for (int j = 0; j <= var; j++)
            	swap(mtx[c][j], mtx[row][j]);
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
        for (int i = 0; i < var; i++)
            exist[i] = 1;
        for (int i = equ-1; i >= 0; i--) {
        	int id = -1;
        	for (int j = 0; j < var; j++) {
        		if (fabs(mtx[i][j]) > eps) {
        			id = j;
        			break;
				}
			}
			if (id < 0)	continue;
            if (fabs(mtx[i][id]) < eps) {
                exist[id] = 0;
                continue;
            }
            if (fabs(mtx[i][var]) < eps)
                varx[id] = 0;
            else
                varx[id] = mtx[i][var]/mtx[i][id];
            for (int j = i+1; j < var; j++)
                if (fabs(mtx[i][j]) > eps && exist[j])
                    exist[i] = 0;
        }
    }
} tool;
#define eps 1e-6
#define MAXN 128
double A[MAXN], S[MAXN], g[MAXN][MAXN];
char s[128];
int test_single(int id, int n, int m, double &score) {
	double v[128] = {};
	for (int j = 0; j < m; j++) {
		if (fabs(v[j]-g[id][j]) < eps)
			continue;
		for (int p = 0; p < n; p++) {
			int c = -1;
			for (int q = 0; q < m; q++) {
				if (fabs(tool.mtx[p][q]) > eps) {
					c = q;
					break;
				}
			}
			if (c == j) {
				double multi = -(g[id][j] - v[j]) / tool.mtx[p][c];
				for (int q = 0; q <= m; q++)
					v[q] += tool.mtx[p][q] * multi;
			}
		}
	}
	for (int j = 0; j < m; j++) {
		if (fabs(g[id][j] - v[j]) > eps) {
			printf("%g %g %d - %d\n", g[id][j], v[j], id, j);
			return 1;
		}
	}
	score = v[m];
	return 0;
}
int test_input(int n, int m) {
	for (int i = 0; i < n; i++) {
		double score;
		if (test_single(i, n, m, score))
			return 1;
		if (fabs(score - S[i]) > eps) {
			printf("%g %g %d\n", score, S[i], i);
			return 1;
		}
	}
	return 0;
}
void solve(int n, int m) {
	double score;
	if (test_single(n, n, m, score))
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
				tool.mtx[i][j] = g[i][j];
			}
			S[i] = g[i][m];
		}
		tool.compute(m, n);
		
		for (int i = 0; i < m; i++)
			scanf("%lf", &g[n][i]);
		if (test_input(n, m))
			puts("contradictory");
		else
			solve(n, m);
	}
	return 0;
}
/*
// 10pt 20pt 30pt 40pt 0pt
3 5
1 0 1 0 0 40
0 1 0 1 0 60
1 0 1 1 0 80
0 1 0 0 0

3 5
1 0 1 0 0 40
0 1 0 1 0 60
1 0 1 1 0 80
0 0 0 0 0

3 5
1 0 1 0 0 40
0 1 0 1 0 60
1 0 1 1 0 80
0 0 1 0 0

3 2
1 0 50
0 1 50
1 0 40
1 1


*/

