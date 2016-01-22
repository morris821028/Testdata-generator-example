#include <stdio.h>

int main() {
	int A[100000] = {}, ret = 0, n, x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (ret == 0)	ret = x;
	}
	printf("%d\n", ret);
	return 0;
}
