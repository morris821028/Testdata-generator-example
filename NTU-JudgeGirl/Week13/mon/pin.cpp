#include <bits/stdc++.h>
#include <random>
using namespace std;

int main() {
	freopen("in.txt", "w", stdout);
    srand(time(NULL));
    int testcase = 1;
    while (testcase--) {
		int spec = 4, n = 10, cmds = 10000;
		int L[16], R[16];
		set<int> S[16];
		printf("%d\n", spec);
		printf("%d\n", n);
		for (int i = 0; i < n; i++) {
			int l = (rand() * rand())%1048576 - 524288;
			int r = l + rand()%1024;
			L[i] = l, R[i] = r;
			printf("%d %d\n", l, r);
		}
		printf("%d\n", cmds);
		for (int i = 0; i < cmds; i++) {
			int cmd = rand()%4 + 1, aid = rand()%n;
			if (cmd == 3 && S[aid].size() == 0)
				cmd = 2;
			if (cmd == 1 && (spec == 1 || spec == 2))
				cmd = 2;
			if (rand()%20 && cmd == 1)
				cmd = 2;
			if (cmd == 1) {
				printf("%d %d\n", cmd, aid);
			} else if (cmd == 2) {
				if (rand()%2) {
					int index = rand()%(R[aid] - L[aid] + 1) + L[aid];
					int value = rand()*rand()%100000000 - 50000000;
					printf("%d %d %d %d\n", cmd, aid, index, value);
					S[aid].insert(index);
				} else {
					int index = (rand() * rand())%1048576 - 524288;
					int value = rand()*rand()%100000000 - 50000000;
					printf("%d %d %d %d\n", cmd, aid, index, value);
				}
			} else if (cmd == 3) {
				if (rand()%2) {
					set<int>::iterator it = S[aid].begin();
					int v = rand()%S[aid].size();
					advance(it, v);
					int index = *it;
					printf("%d %d %d\n", cmd, aid, index);
				} else {
					int index = (rand() * rand())%1048576 - 524288;
					printf("%d %d %d\n", cmd, aid, index);
				}
			} else if (cmd == 4) {
				printf("%d %d\n", cmd, aid);
			}
		}
	}
    return 0;
}
