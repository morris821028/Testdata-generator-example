#include <bits/stdc++.h>
#include <random>
using namespace std;

float frandom() {
	return (float) rand() / RAND_MAX;
}
int main() {
	freopen("in.txt", "w", stdout);
    srand(time(NULL));
    int testcase = 1;
    while (testcase--) {
		for (int i = 0; i < 1000; i++) {
			float x, y, p, q;
			x = frandom() + rand()%100 - 50, y = frandom() + rand()%100 - 50;
			p = frandom() + rand()%100 - 50, q = frandom() + rand()%100 - 50;
			printf("%d %f %f %f %f\n", rand()%3, x, y, p, q);
		}
	}
    return 0;
}
