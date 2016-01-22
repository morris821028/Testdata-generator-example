#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("in.txt", "w", stdout);
    srand(time(NULL));
    int testcase = 2;
    while (testcase--) {
		int n = 50000;
		printf("%d\n", n+10);
		int st = 0;
		for (int i = 0; i < n; i++) {
//			int l = rand()*rand(), r = rand()*rand();
//			if (l > r)	swap(l, r);
//			if (l == r)	r++;
//			if (l > r)	swap(l, r);
			int l = st, r = st + rand()%1000+1;
			printf("%d %d\n", l, r);
			st = r;
		}
		for (int i = 0; i < 10; i++) {
			int l = rand()*rand(), r = rand()*rand();
			if (l > r)	swap(l, r);
			if (l == r)	r++;
			if (l > r)	swap(l, r);			
			printf("%d %d\n", l, r);
		}
		if (testcase)
			puts("");
	}
    return 0;
}

