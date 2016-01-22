#include "complex.h"
#include <stdio.h>

void init(complex *c, float a, float b) {
	c->x = a, c->y = b;
}
void complex_print(complex *c) {
	printf("%.3f%+.3fi\n", c->x, c->y);
}
complex complex_add(complex *x, complex *y) {
	complex c;
	init(&c, x->x+y->x, x->y+y->y);
	return c;
}
complex complex_sub(complex *x, complex *y) {
	complex c;
	init(&c, x->x-y->x, x->y-y->y);
	return c;
}
complex complex_mul(complex *x, complex *y) {
	complex c;
	init(&c, x->x * y->x - x->y * y->y, x->x * y->y + x->y * y->x);
	return c;
}
