#include <bits/stdc++.h>
#include <random>
using namespace std;

int main() {
	freopen("in.txt", "w", stdout);
    srand(time(NULL));
    int testcase = 40;
    while (testcase--) {
    	int n = rand()%3 + 1, m = rand()%3+1;
//    	if (rand()%2)	n = 1;
//    	else			m = 1; 
    	
//    	n = 3, m = 2;

		n = rand()%16 + 1, m = rand()%16+1;
		while (n * m > 16)
			n = rand()%16 + 1, m = rand()%16+1;
			
    	printf("%d %d\n", n, m);
    	
    	int A[128];
    	for (int i = 1; i <= n*m; i++)
    		A[i-1] = i;
    	int R[128] = {}, C[128] = {};
    	random_shuffle(A, A+(n*m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				R[i] += A[i*m+j], C[j] += A[i*m+j];
			}
		}
		
		if (rand()%2) {
			for (int i = 0; i < 10; i++) {
				int x, y;
					x = rand()%n, y = rand()%n;
				while (R[x] < 1)
					x = rand()%n, y = rand()%n;
				R[x]--, R[y]++;
			}
			for (int i = 0; i < 10; i++) {
				int x, y;
					x = rand()%m, y = rand()%m;
				while (C[x] < 1)
					x = rand()%m, y = rand()%m;
				C[x]--, C[y]++;
			}
		}		
		for (int i = 0; i < n; i++)
			printf("%d%c", R[i], i == n-1 ? '\n' : ' ');
		for (int i = 0; i < m; i++)
			printf("%d%c", C[i], i == m-1 ? '\n' : ' ');
	}
    return 0;
}

