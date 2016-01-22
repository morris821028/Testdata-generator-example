#include <bits/stdc++.h>
using namespace std;


int A[262144] = {5, 6, 7, 8};
int main() {
	freopen("in.txt", "w", stdout);
    srand(time(NULL));
    int testcase = 1;
    while (testcase--) {
		int n = 100000;
		set<int> S;
		for (int i = 0; i < n; i++) {
			int x;
			do {
				x = rand() * rand() % 100000000;
				if (S.count(x) == 0)
					break;
			} while (true);
			S.insert(x);
			A[i] = x;
		}
		random_shuffle(A, A+n);
		printf("%d\n", n);
		for (int i = 0; i < n; i++) {
			printf("%d%c", A[i], i == n-1 ? '\n' : ' ');
		}
		if (testcase)
			puts("");
	}
    return 0;
}
