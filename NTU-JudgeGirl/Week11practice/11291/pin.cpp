#include <bits/stdc++.h>
#include <random>
using namespace std;
double frandom() {
	return (double) rand() / RAND_MAX;
}
double mrandom() {
	return (rand() * rand())%10;
}
void dfs(int dep) {
	if (dep > 0 || (dep && rand()%3 == 0)) {
		printf("%d", rand()%10-5);
		return ;
	}
	printf("(%.2lf ", frandom());
	dfs(dep+1);
	putchar(' ');
	dfs(dep+1);
	printf(")");
}
int main() {
	freopen("in.txt", "w", stdout);
    srand(time(NULL));
    int testcase = 10;
    while (testcase--) {
    	dfs(0);
    	puts("");
	}
    return 0;
}
