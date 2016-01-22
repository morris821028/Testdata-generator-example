#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("in.txt", "w", stdout);
    srand(time(NULL));
    int testcase = 10;
    while (testcase--) {
		int n = 12;
		int m = rand()%(n*n);
		int k = rand()%(n);
		if (m < n)	m = n;
		printf("%d %d %d\n", n, m, k);
	}
    return 0;
}

