#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("in.txt", "w", stdout);
    srand(time(NULL));
    int testcase = 1;
    while (testcase--) {
		int spec = 3, n = 6, cmds = 100;
		int A[16] = {};
		memset(A, -1, sizeof(A));
		printf("%d\n", spec);
		printf("%d\n", n);
		printf("%d\n", cmds);
		for (int i = 0; i < cmds; i++) {
			int cmd = rand()%3+1, lid = rand()%n;
//			if (A[lid] != -1)
//				cmd = 1;
			if (cmd == 1) {
				printf("%d %d\n", cmd, lid);
			} else if (cmd == 2) {
				int pwd = rand()%30000 - 15000;
				printf("%d %d %d\n", cmd, lid, pwd);
				if (pwd >= 0 && pwd < 10000)
					A[lid] = pwd;
			} else if (cmd == 3) {
				if (rand()%2) {
					printf("%d %d %d\n", cmd, lid, A[lid]);
					A[lid] = -1;
				} else {
					int pwd = rand()%30000 - 15000;
					printf("%d %d %d\n", cmd, lid, pwd);
				}
			}
		}
	}
    return 0;
}

