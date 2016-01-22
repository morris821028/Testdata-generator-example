#include <bits/stdc++.h>
using namespace std;

// $ awk '{ sub("\r$", ""); print }' out.txt > output.txt
char randLetter() {
	if (rand()%2)
		return rand()%26 + 'a';
	return rand()%26 + 'A';
}
char randChar() {
	return rand()%('z' - ' ' + 1) + ' ';
}
int main() {
//	freopen("in.txt", "w", stdout);
    srand(time(NULL));
    int testcase = 1;
    while (testcase--) {
    	FILE *fout = fopen("in.dat", "w");
    	int lines = 32;
    	for (int it = 0; it < lines; it++) {
    		int n = rand()%32 + 32, has = 0;
    		for (int i = 0; i < n; i++) {
    			if (rand()%5 == 0) {
    				fprintf(fout, " "), has = 0;
    			} else if (rand()%2 == 0) {
    				fprintf(fout, "%c", randLetter()), has = 1;
    			} else {
    				fprintf(fout, "%c", randChar()), has = 1;
				}
    		}	
    		fputs("\n", fout);
		}
	}
    return 0;
}

