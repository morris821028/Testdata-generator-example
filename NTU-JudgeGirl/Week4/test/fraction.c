#include "fraction.h"

long long gcd(long long x, long long y) {
    int t;
    while (x%y)    t = x, x = y, y = t%y;
    return y;
}
Frac normal(long long a, long long b) {
	Frac z;
	long long g = gcd(a, b);
	a /= g, b /= g;
	if (b < 0)	a = -a, b = -b;
	z.a = a, z.b = b;
	return z;
}
Frac add(Frac x, Frac y) {
    return normal(x.a * y.b + y.a * x.b, x.b * y.b);
}
Frac subtract(Frac x, Frac y) {
    return normal(x.a * y.b - y.a * x.b, x.b * y.b);
}
Frac multipy(Frac x, Frac y) {
    return normal(x.a * y.a, x.b * y.b);
}
Frac divide(Frac x, Frac y) {
    return normal(x.a * y.b, x.b * y.a);
}
