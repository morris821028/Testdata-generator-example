#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("in.txt", "w", stdout);
    srand(time(NULL));
    int testcase = 10, cases = 0;
    while (testcase--) {
    	cases ++;
		int n = rand()%(2*cases) + 1;
//		n = cases;
		n = 6;
		n = n * 2 + 1;
		int ext = 0;
		printf("%d\n", n);
		for (int i = 0; i < n; i++) {
			if (rand()%10 || ext >= 3)
				printf("%d%c", rand()*rand()%1000 + 1024, i == n-1 ? '\n' : ' ');
			else
				printf("%d%c", rand()*rand()%1000 + 2048, i == n-1 ? '\n' : ' '), ext++;
		}
	}
    return 0;
}

