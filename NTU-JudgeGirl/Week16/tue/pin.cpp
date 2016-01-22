#include <bits/stdc++.h>
using namespace std;


int main() {
	freopen("in.txt", "w", stdout);
    srand(time(NULL));
    int testcase = 5, cases = 0;
    while (testcase--) {
    	int n = rand()%900 + 100;
    	printf("%d\n", n);
    	for (int i = 0; i < n; i++)
    		printf("%d ", rand()*rand());
    	puts("");
    	cases++;
	}
	puts("0\n");
	
	int A[1000];
	for (int i = 0; i < cases; i++)
		A[i] = i;
	random_shuffle(A, A+cases);
	for (int i = 0; i < cases; i++)
		printf("%d\n", A[i]);
    return 0;
}

