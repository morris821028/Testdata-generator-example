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
    	FILE *fout = fopen("sample.dat", "wb");
    	fprintf(fout, "Anybody should be fine if it was just to ease loneliness\n");
    	fprintf(fout, "Because the stars in the night sky seems like falling, I cant lie to myself\n");
    	fprintf(fout, "One more time, please dont' change the season\n");
    	fprintf(fout, "One more time to the time when we fool around\n");
	}
    return 0;
}

