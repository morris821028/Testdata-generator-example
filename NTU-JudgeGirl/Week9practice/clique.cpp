#include <stdio.h>

#define MAXS (1<<24)
#define MAXN (MAXS>>5)+1
#define GET(x) (mark[(x)>>5]>>((x)&31)&1)
#define SET(x) (mark[(x)>>5] |= 1<<((x)&31))
int mark[MAXN];
int main() {
	int n, m, g[32] = {};
	int ret = 1;
	char s[32];
	scanf("%d",  &n);
	for (int i = 0; i < n; i++)  {
		scanf("%s", s);
		for (int j = 0; j < n; j++)
			if (s[j] == '1')
				g[i] |= 1<<j;
		g[i] |= 1<<i;
		SET(1<<i);
	}
	m = 1<<n;
	int p, q, r;
	for (int i = 1; i < m; i++) {
		p = __builtin_ffs(i) - 1;
		q = 1<<p;
		if (GET(i^q) && (i&g[p]) == i) {
			SET(i);
			r = __builtin_popcount(i);
			if (r > ret)
				ret = r;
		}
	}
	printf("%d\n", ret);
	return 0;
}
/*
7
0100110
1010110
0101000
0000100
1101011
1100101
0000110

5
01101
10111
11011
01101
11110
*/

