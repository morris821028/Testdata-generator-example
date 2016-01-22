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
	freopen("10.in", "w", stdout);
    srand(time(NULL));
    int testcase = 1;
    while (testcase--) {
    	int N, M, K, D;
//    	N = rand()%10 + 1, M = 1, K = 0, D = 0;
//    	N = rand()%6 + 5, M = rand()%N+1, K = rand()%(M*M)+1, D = 0x3f3f3f3f;
//    	N = rand()%6 + 5, M = rand()%N+1, K = rand()%(M*M)+1, D = rand()%(M*M)+1;
		N = 10, M = 5, K = rand()%(M*M)+1, D = rand()%(M*M)+1;
    	printf("%d %d %d %d\n", N, M, K, D);
    	for (int i = 0; i < N; i++) {
    		for (int j = 0; j < N; j++) {
    			printf("%d%c", rand()%5, " \n"[j==N-1]);
    		}
		}
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < M; j++) {
				printf("%d%c", rand()%5, " \n"[j==M-1]);
			}
		}
	}
    return 0;
}
