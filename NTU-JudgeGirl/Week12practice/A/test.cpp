#include <bits/stdc++.h>
using namespace std;

int main() {
	for (int i = 1; i < 20; i++)
		printf("%lf\n", (double) i * (pow(2, 1.f / i) -1));
	return 0;
}

