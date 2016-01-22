#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("in.txt", "w", stdout);
    srand(time(NULL));
    int testcase = 1;
    while (testcase--) {
		int n, r, w;
		int A[128];
		n = 50;
		r = rand()%10 + 10;
		w = rand()%r + 1;
		printf("%d %d %d\n", n, r, w);
		for (int i = 0; i < n; i++) {
			string ans = "";
			int mask = rand()%31+1;
			for (int j = 0; j < 5; j++)
				if ((mask>>j)&1)
					ans = ans + (char) (j + 'A');
			printf("%s%c", ans.c_str(), i == n-1 ? '\n' : ' ');
			A[i] = mask;
		}
		int m = rand()%10 + 1000;
		printf("%d\n", m);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				string ans = "";
				int mask = A[j];
				int it = rand()%5;
				for (int k = 0; k < it; k++)
					mask = (mask-1)&A[j];
//				if (mask == 0)	mask = rand()%31 + 1;
				for (int k = 0; k < 5; k++)
					if ((mask>>k)&1)
						ans = ans + (char) (k + 'A');
				for (int k = 0; k < ans.length(); k++) {
					if (rand()%2)
						ans[k] = tolower(ans[k]);
				}
				random_shuffle(ans.begin(), ans.end());
				if (mask == 0)
					ans = "N/A";
				printf("%s%c", ans.c_str(), j == n-1 ? '\n' : ' ');
			}
		}
	}
    return 0;
}

