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
	freopen("in.txt", "w", stdout);
    srand(time(NULL));
    int testcase = 1000;
    // printf("%d\n", testcase);
    while (testcase--) {
    	int N, K, S, A[128];
 	  	int sum = 0;
    	N = 10;
    	K = 1;
    	S = 5;
    	if (rand()%2)
    		S = N - S + 1;
    	for (int i = 0; i < N; ) {
    		A[i] = (rand()*rand()%1000 + 1);
			sum += A[i];
    		int copy = rand()%2;
    		i++;
    		for (; copy > 0 && i < N; copy--, i++)
    			A[i] = A[i-1],
				sum += A[i];
    	}
    	random_shuffle(A, A+N);
    	if (rand()%5 == 0) {
    		K = rand()%sum + 1;
    	} else {
    		K = 0;
    		int used[128] = {};
    		for (int i = 0; i < S; i++) {
    			int x;
    			do {
    				x = rand()%N;
    				if (used[x] == 0)
    					break;
				} while (1);
				used[x] = 1;
    			K += A[x];
    		}
    	}
    	printf("%d %d %d\n", N, K, S);
    	for (int i = 0; i < N; i++)
    		printf("%d%c", A[i], i == N-1 ? '\n' : ' ');
	}
    return 0;
}
