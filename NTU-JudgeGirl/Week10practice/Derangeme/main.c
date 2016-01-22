#include <stdio.h>

int g[32][32] = {}, used[32] = {};
int n, m, x, y;
char path[32];
void dfs(int u) {
	if (u == n) {
		path[u] = '\0';
		puts(path);
		return ;
	}
	for (int i = 0; i < n; i++) {
		if (used[i] || g[i][u])
			continue;
		used[i] = 1;
		path[u] = i+'A';
		dfs(u+1);
		used[i] = 0;
	}
}
int main() {
	while (scanf("%d %d", &n, &m) == 2) {
		memset(g, 0, sizeof(g));
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &x, &y), x--, y--;
			g[x][y] = 1;
		}
		dfs(0);
	}
	return 0;
}
