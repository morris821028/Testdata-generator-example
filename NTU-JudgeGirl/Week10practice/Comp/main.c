#include <stdio.h>

int h(int y) {
	if (y < 2)
		return -1;
	return 2 + h(y-1) - h(y-2);
}
int g(int z) {
	if (z <= 2)
		return z*z - 1;
	return 2;
}
int f(int x) {
	int hh = h(x), gg;
	if (x > hh)
		return f(x-1) - h(x);
	if (x < hh) {
		gg = g(x);
		return f(gg) - gg;
	}
	return 1;
}
int main() {
	int x;
	while (scanf("%d", &x) == 1)
		printf("%d\n", f(x));
	return 0;
}
