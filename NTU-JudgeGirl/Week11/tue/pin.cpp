#include <bits/stdc++.h>
#include <random>
using namespace std;
double frandom() {
	return (double)(rand()%10) / 2;
}
double mrandom() {
	return (rand() * rand())%10;
}
void rand_exp(int n, int dep) {
	if (n < 0) {
		putchar('-');
		rand_exp(-n, dep+1);
		return ;
	}
	if (n < 10) {
		putchar(n + '0');
		return ;
	}
	int factor = 0;
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			if (factor == 0 || rand()%2)
				factor = i;
		}
	}
	putchar('(');
	if (dep > 15 || n > 100) {
		int v = n/2;
		int a = v, b = n-v;
		if (rand()%2)
			swap(a, b);
		rand_exp(a, dep+1);
		putchar('+');
		rand_exp(b, dep+1);
	} else if (factor != 0 && rand()%3 == 0) {
		rand_exp(n / factor, dep+1);
		putchar('*');
		rand_exp(factor, dep+1);
	} else if (rand()%3 == 0) {
		int v = rand()%n + 1;
		int a = v, b = n-v;
		if (rand()%2)
			swap(a, b);
		rand_exp(a, dep+1);
		putchar('+');
		rand_exp(b, dep+1);
	} else if (rand()%3 == 0) {
		int v = rand()%20+1;
		int a = n+v, b = v;
		rand_exp(a, dep+1);
		putchar('-');
		rand_exp(b, dep+1);
	}  else if (n < 100) {
		int v = rand()%3+1;
		int a = n*v, b = v;
		rand_exp(a, dep+1);
		putchar('/');
		rand_exp(b, dep+1);
	} else {
		int v = rand()%4 + 1;
		int a = v, b = n-v;
		if (rand()%2)
			swap(a, b);
		rand_exp(a, dep+1);
		putchar('+');
		rand_exp(b, dep+1);
	}
	putchar(')');
}
int main() {
	freopen("in.txt", "w", stdout);
    srand(time(NULL));
    int testcase = 100, cases = 0;
    while (testcase--) {
    	int goal = rand()*rand()%100 - 50;
    	rand_exp(goal, 0);
    	puts("");
    	fprintf(stderr, "testcase %d: %d\n", ++cases, goal);
	}
    return 0;
}
