#include <bits/stdc++.h>
#include "fs.h"
using namespace std;

// $ awk '{ sub("\r$", ""); print }' out.txt > output.txt
char randLetter() {
	if (rand()%2)
		return rand()%26 + 'a';
	return rand()%26 + 'A';
}
int main() {
//	freopen("in.txt", "w", stdout);
    srand(time(NULL));
    int testcase = 1;
    while (testcase--) {
    	FILE *fout = fopen("in.dat", "wb");
    	int n = 1024;
    	Account fs[1024];
//		set<string> S;
//		for (int i = 0; i < n; i++) {
//			while (true) {
//				string s;
//				int makeErr = rand()%2;
////				makeErr = 0;
//				for (int j = rand()%32 + 4; j > 0; j--) {
//					s = s + randLetter();
//					if (rand()%8 == 0)
//						s += ' ';
//					if (makeErr && rand()%8 == 0)
//						s += rand()%100+1;
//				}
//				if (S.count(s) == 0) {
//					fs[i].balance = rand()%100 - 50;
//					strcpy(fs[i].name, s.c_str());
//					fs[i].gender = rand()%4 - 2;
//					S.insert(s);
//					break;
//				}
//			}
//			printf("%d %s %d\n", fs[i].balance, fs[i].name, fs[i].gender);
//		}
		
		memset(fs, 0, sizeof(fs));
		Account A = {
			.balance = 50,
			.name = {'p', 'a', 'n', 'g', '\0'},
			.gender = 1
		};
		Account B = {
			.balance = 100,
			.name = {'f', 'e', 'n', 'g', '\0'},
			.gender = 0
		};
		n = 2;
		fs[0] = A;
		fs[1] = B;
		
		fwrite(fs, sizeof(Account), n, fout);
	}
    return 0;
}

