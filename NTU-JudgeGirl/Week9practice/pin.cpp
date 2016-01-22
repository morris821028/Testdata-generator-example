#include <bits/stdc++.h>
#include <random>
using namespace std;
double frandom() {
	return (double)(rand()%10) / 2;
}
double mrandom() {
	return (rand() * rand())%10;
}
int main() {
	freopen("test.in", "w", stdout);
    srand(time(NULL));
    int testcase = 1;
//    printf("%d\n", testcase);
    while (testcase--) {
		int n = 60, m = 1024;
		int g[128][128] = {};
		printf("%d\n", n);
//		for (int i = 0; i < m; i++) {
//			while (1) {
//				int x = rand()%n, y = rand()%n;
//				if (x == y || g[x][y])
//					continue;
//				g[x][y] = g[y][x] = 1;
//				break;
//			}
//		}
		for (int i = 0, BASE = 0; i < 20 && BASE < n; i++) {
			int l = BASE, r = BASE + rand()%10 + 10;
			if (r > n)	r = n;
			for (int j = l; j < r; j++) {
				for (int k = j+1; k < r; k++)
					g[j][k] = g[k][j] = 1;
			}
			BASE = r;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d ", g[i][j]);
			}
			puts("");
		}
	}
    return 0;
}
