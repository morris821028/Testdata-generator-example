#include <bits/stdc++.h>
using namespace std;

int main() {
	srand(time(NULL));
	int testcase = 1;
	while (testcase--) {
		int N = 100000, K = 3;	
		printf("%d\n", K);
		for (int i = 0; i < N; i++) {
			int x = rand()%1+1;
			if (rand()%10000 == 0)
				printf("%d ", rand()*rand()%1000000+1);
			else if (i/K%2 == 0)
				printf("%d ", abs(x));
			else
				printf("%d ", -abs(x));
		}
		printf("%d\n", 0);
	}
	return 0;
}

