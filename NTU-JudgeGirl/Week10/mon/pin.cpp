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
    int testcase = 1;
    // printf("%d\n", testcase);
    while (testcase--) {
    	int n, m;
    	n = 20;
    	m = 850;
    	for (int i = 0; i < n; i++)
    		printf("%c", rand()%26+'a');
    	puts("");
    	printf("%d\n", m);
    	for (int i = 0; i < m; i++) {
    		printf("%c%c\n", rand()%26+'a', rand()%26+'a');
		}
	}
    return 0;
}
