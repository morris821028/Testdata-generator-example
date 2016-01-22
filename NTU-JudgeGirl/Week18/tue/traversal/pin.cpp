#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("in.txt", "w", stdout);
    srand(time(NULL));
    int testcase = 5, cases = 0;
    while (testcase--) {
    	cases ++;
		int n = 128, m = 500;
		printf("%d %d %d %d\n", n, m, rand()%n, rand()%m);
	}
    return 0;
}

