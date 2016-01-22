#include <bits/stdc++.h>
#include "account.h"
using namespace std;

Account assign(int a, int b, int c, int d) {
	Account ret = {a, b, c, d};
	return ret;
}

int main() {
	freopen("in.txt", "w", stdout);
    srand(time(NULL));
    int testcase = 1;
    while (testcase--) {
    	FILE *fout = fopen("in.bin", "wb");
    	int n = 30000;
		Account *A = (Account*) malloc(sizeof(Account) * n);
		
		int AA[100], ZZ[100];
		for (int i = 0; i < 100; i++)
			AA[i] = rand()*rand()+20, ZZ[i] = rand()*rand()+20;
		int aid = 0;
		for (int i = 0; i < n; i++) {
			A[i].accountNum = aid;
			A[i].balance = (rand()%100+60);
//			A[i].zipcode = rand()%900 + 100;
//			A[i].age = rand()%30 + 12;
			A[i].age = AA[rand()%100];
			A[i].zipcode = ZZ[rand()%100];
			aid += rand()%100+1;
		}

		random_shuffle(A, A+n);
		fwrite(A, sizeof(Account), n, fout);
		fclose(fout);
	}
    return 0;
}
