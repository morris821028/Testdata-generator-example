#include <bits/stdc++.h>
#include <random>
using namespace std;
double frandom() {
	return (double)(rand()%10) / 2;
}
double mrandom() {
	return (rand() * rand())%10;
}
int main() {
	freopen("10.in", "w", stdout);
    srand(time(NULL));
    int testcase = 1;
    while (testcase--) {
    	int g[4][4] = {}, n = 4;
    	for (int i = 0; i < n; i++)
    		for (int j = 0; j < n; j++)
    			g[i][j] = i*4+j+1;
    	g[3][3] = 0;
    	int ox = 3, oy = 3;
//    	for (int it = 0; it < 100; it++) {
//    		int a, b, c, d;
//    		while (true) {
//    			a = rand()%n, b = rand()%n;
//    			c = rand()%n, d = rand()%n;
//    			swap(g[a][b], g[c][d]);
//    			break;
//			}
//		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (g[i][j] == 0)
					ox = i, oy = j;
    	vector<int> A;
    	const int dx[] = {0, 0, 1, -1};
    	const int dy[] = {1, -1, 0, 0};
    	int step = rand()%10 + 10;
    	for (int i = 0; i < step; i++) {
    		while (true) {
    			int td = rand()%4;
    			int tx = ox + dx[td], ty = oy + dy[td];
    			if (tx < 0 || ty < 0 || tx >= n || ty >= n)
    				continue;
    			A.push_back(g[tx][ty]);
    			swap(g[tx][ty], g[ox][oy]);
    			ox = tx, oy = ty;
    			break;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				printf("%d%c", g[i][j], " \n"[j==n-1]);
		}
		reverse(A.begin(), A.end());
		for (int i = 0; i < A.size(); i++) {
			printf("%d ", A[i]);
			if (rand()%3 == 0)
				printf("%d ", rand()%15+1);
		}
		puts("0");
	}
    return 0;
}
