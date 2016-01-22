#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("in.txt", "w", stdout);
    srand(time(NULL));
    int testcase = 50;
    while (testcase--) {
		int n, m;
		n = 100, m = rand()%(n/5)+1;
		if (n < 5)	n = 5;
		if (m < 2)	m = 2;
		printf("%d %d\n", n, rand()%(n/5)+1);
		
		int solution[128];
		for (int i = 0; i < n; i++)
			solution[i] = i;
		random_shuffle(solution, solution + n);
		
		int ban[128][128] = {}, be = m*(m-1)/2;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++)
				ban[solution[i]][solution[j]] = 1;
		}
		int g[128][128] = {};
		int e = rand()%(n*n/2) + n*n/8;
		for (int i = 0; i < e; i++) {
			int x, y;
			x = rand()%n, y = rand()%n;
			while (x == y)
				x = rand()%n, y = rand()%n;
			if (ban[x][y])
				continue;
			g[x][y] = g[y][x] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				printf("%d%c", g[i][j], j == n-1 ? '\n' : ' ');
		}
	}
    return 0;
}

