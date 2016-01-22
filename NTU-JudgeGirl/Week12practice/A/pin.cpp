#include <bits/stdc++.h>
#include <random>
using namespace std;
int main() {
	ifstream fin("dict/dict2.txt");
	set<string> dict;
	string word;
	while (fin >> word)
		dict.insert(word);
	freopen("in.txt", "w", stdout);
    srand(time(NULL));
    int testcase = 1;
    while (testcase--) {
    	int n = 4, A[128], B[128] = {};
    	printf("%d\n", n);
    	for (int i = 0; i < n; i++) {
    		A[i] = rand()%128+1;
    		A[0] = 2;
    		printf("%d%c", A[i], i == n-1 ? '\n' : ' ');
    	}
    	int q = 1024;
    	printf("%d\n", q);
    	for (int i = 0; i < q; i++) {
    		int cmd = rand()%2+1, tid = rand()%n;
    		printf("%d %d", cmd, tid);
    		if (B[tid] == 256)
    			cmd = 2;
    		if (cmd == 1) {
    			set<string>::iterator it = dict.begin();
    			advance(it, rand()%dict.size());
    			printf(" %s", it->c_str());
    			for (int j = 0; j < A[tid]; j++)
    				printf(" %d", rand()%3);
    			puts("");
    			B[tid]++;
			} else {
				int order[128];
				for (int j = 0; j < A[tid]; j++)
					order[j] = j;
				random_shuffle(order, order+A[tid]);
				for (int j = 0; j < A[tid]; j++)
					printf(" %d", order[j]);
				puts("");
			}
		}
	}
    return 0;
}
