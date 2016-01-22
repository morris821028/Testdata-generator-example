#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <bits/stdc++.h>
using namespace std;

typedef double Float;
bool Quadratic(Float A, Float B, Float C, 
					Float *t0, Float *t1) {
	Float discrim = B*B - 4.f*A*C;
	if (discrim < 0.)	return false;
	Float rootDiscrim = sqrt(discrim), q;
	if (B < 0)	q = -.5f*(B - rootDiscrim);
	else		q = -.5f*(B + rootDiscrim);
	*t0 = q / A;
	*t1 = C / q;
	if (*t0 > *t1) {
		Float t;
		t = *t0, *t0 = *t1, *t1 = t;
	}
	return true;
}
bool findroot(Float A, Float B, Float C,
			Float *t0, Float *t1) {
	Float a[4] = {C, B, A, 0}, root[20];
	int n = 2, m = 2;
	for (int i = 0; i < m; i++) {
		Float b[4] = {};
		for (int j = 0; j < n; j++)
			b[j] = a[j+1]*(j+1);
		double x = 200000, tx;
		for (int it = 0; it < 10000; it++) {
			double fx = 0, ffx = 0;
			for (int j = n; j >= 0; j--) {
				fx = fx * x + a[j];
				ffx = ffx * x + b[j];
			}
			x = x - fx / ffx;
		}
		root[i] = x;
		root[i+1] = C / x * A;
		break;
		for (int j = n; j >= 0; j--)
			a[j] = a[j] + a[j+1]*x;
		for (int j = 0; j <= n; j++)
			a[j] = a[j+1];
		n--;
	}
	*t0 = root[0], *t1 = root[1];
	if (*t0 > *t1) {
		Float t;
		t = *t0, *t0 = *t1, *t1 = t;
	}
}
int main() {
	Float a, b, c;
	while (cin >> a >> b >> c) {
		Float t0, t1;
//		bool f = Quadratic(a, b, c, &t0, &t1);
//		
//		printf("%.20lf %.20lf\n", t0, t1);
		findroot(a, b, c, &t0, &t1);
		printf("%.20lf %.20lf\n", t0, t1);
	}
	return 0;
}
/*
1 1.786737589984535 2.054360090947453e-8
94906265.625 189812534 94906268.375
1 200   -0.000015
1 2000 -0.00000015
*/
