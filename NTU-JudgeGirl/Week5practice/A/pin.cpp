#include <bits/stdc++.h>
using namespace std;
double frandom() {
	int v = 32768>>2;
	return (double)(rand()%20) / v;
}
double mrandom() {
	return (rand() * rand())%500;
}
int main() {
	freopen("in.txt", "w", stdout);
	FILE *fout = fopen("out.txt", "w");
    srand(time(NULL));
    int testdata = 200;
    while (testdata--) {
    	double x0, x1;
    	double a, b, c;
    	x1 = frandom();
    	x0 = mrandom() + x1;
    	a = 1, b = - (x0 + x1), c = x0 * x1;
    	if (x0 > x1)	swap(x0, x1);
    	printf("%.20lf %.20lf %.50g\n", a, b, c);
    	fprintf(fout, "%.20lf %.20lf\n", x0, x1);
	}
	
    fclose(fout);
    return 0;
}
