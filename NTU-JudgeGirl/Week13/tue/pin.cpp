#include <bits/stdc++.h>
#include <random>
using namespace std;

int main() {
	freopen("in.txt", "w", stdout);
    srand(time(NULL));
    int testcase = 1;
    while (testcase--) {
		int spec = 3, n = 32, cmds = 80;
		printf("%d\n", spec);
		printf("%d\n", n);
		for (int i = 0; i < n; i++) {
			int m = 2000;
			printf("%d", m);
			for (int j = 0; j < m; j++)
				printf(" %d", rand()%1000-500);
			puts("");
		}
		printf("%d\n", cmds);
		for (int i = 0; i < cmds; i++) {
			int cmd = rand()%3+1, pid = rand()%n, pid2 = rand()%n;
			if (rand()%10)	cmd = 3;
			if (cmd == 1) {
				printf("%d %d\n", cmd, pid);
			} else if (cmd == 2) {
				printf("%d %d %d\n", cmd, pid, pid2);
			} else if (cmd == 3) {
				printf("%d %d %d\n", cmd, pid, pid2);
			}
		}
	}
    return 0;
}
