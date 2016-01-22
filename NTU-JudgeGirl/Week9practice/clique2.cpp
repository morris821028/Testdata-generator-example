#include <stdio.h>
#define MAXN 64
#define uint64_t unsigned long long
int n, cnt, mxcli;
uint64_t ng[MAXN] = {};

void dfs(int u, uint64_t used) {
	if (u == n) {
		if (cnt > mxcli) 
			mxcli = cnt;
    	return;
    }
    if ((used&ng[u]) == ng[u]) {
    	cnt++;
    	dfs(u+1, used);
    	cnt--;
	}
    if (cnt + n - u - 1 > mxcli) 
		dfs(u+1, used|(1LLU<<u));
}
int main() {
	char s[64];
	int x;
	while (scanf("%d", &n) == 1 && n) {
		for (int i = 0; i < n; i++)  {
			for (int j = 0; j < n; j++)
				scanf("%d", &x), s[j] = x + '0';
//			scanf("%s", s);
			ng[i] = 0;
			for (int j = 0; j < i; j++)
				if (s[j] == '0')
					ng[i] |= 1LLU<<j;
		}
		cnt = 0, mxcli = 0;
		dfs(0, 0);
		printf("%d\n", mxcli);
	}
	return 0;
}

