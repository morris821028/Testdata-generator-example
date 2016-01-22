#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <bits/stdc++.h>
using namespace std;
typedef double Float;
bool General(Float A, Float B, Float C, 
			Float *t0, Float *t1) {
	Float discrim = B*B - 4.f*A*C;
	if (discrim < 0.)	return false;
	Float rootDiscrim = sqrt(discrim), q;
	*t0 = (-B + rootDiscrim)*.5f / ( A);
	*t1 = (-B - rootDiscrim)*.5f / ( A);
	if (*t0 > *t1) {
		Float t;
		t = *t0, *t0 = *t1, *t1 = t;
	}
	return true;		  	
}
int main() {
	Float a, b, c;
	while (cin >> a >> b >> c) {
		Float t0, t1;
		bool f = General(a, b, c, &t0, &t1);
		printf("%.20lf %.20lf\n", t0, t1);
	}
	return 0;
}

