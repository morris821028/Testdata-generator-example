#include <bits/stdc++.h>
#include <random>
using namespace std;
double frandom() {
	return (double)(rand()%10) / 2;
}
double mrandom() {
	return (rand() * rand())%10;
}
char randletter() {
	return rand()%26 + 'a';
}
int main() {
	freopen("in.txt", "w", stdout);
    srand(time(NULL));
    int testcase = 1;
//    printf("%d\n", testcase);
    while (testcase--) {
    	int n, m;
    	n = rand()%50 + 10000;
    	m = 300000;
    	for (int i = 0; i < n; i++)
    		printf("%c", randletter());
    	puts("");
    	for (int i = 0; i < m; i++) {
    		int cmd = rand()%5;
    		if (rand()%2)	
				cmd = rand()%2 ? 2 : 3;
			else if (rand()%2)
				cmd = 0;
			if (cmd == 1 && rand()%100)
				cmd = 0;
    		if (cmd == 0) {
    			printf("replace %c %c\n", randletter(), randletter());
			} else if (cmd == 1) {
				printf("remove %c\n", randletter());
			} else if (cmd == 2) {
				printf("addtail %c\n", randletter());
			} else if (cmd == 3) {
				printf("addhead %c\n", randletter());
			}
			if (rand()%32767 == 0)
				printf("addteid\n");
		}
		puts("end");
	}
    return 0;
}
