#include <bits/stdc++.h>
using namespace std;
double frandom() {
	int v = 32768>>2;
	return (double)(rand()%20) / v;
}
double mrandom() {
	return (rand() * rand())%500;
}
int main() {
	freopen("in.txt", "w", stdout);
//	FILE *fout = fopen("out.txt", "w");
    srand(time(NULL));
    int testcase = 10;
    while (testcase--) {
    	int m = rand()%5+1;
    	int n = min(rand()%(m*m) + 1, 100);
    	int score[128];
    	printf("%d %d\n", n, m);
    	for (int i = 0; i < m; i++)
    		score[i] = rand()%100;
    	for (int i = 0; i < n; i++) {
    		int s = 0;
    		for (int j = 0; j < m; j++) {
    			int has = rand()%2;
    			printf("%d ", has);
    			s += has * score[j];
			}
			if (rand()%n == 0)	s++;
			printf(" %d\n", s);
		}
		for (int i = 0; i < m; i++)
			printf("%d%c", rand()%2, i == m-1 ? '\n' : ' ');
    	if (testcase)
    		puts("");
	}
	
//    fclose(fout);
    return 0;
}
