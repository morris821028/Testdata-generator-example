#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define NMAX (27 + 4 * 99999)

int Q[4 * 99999];
char C[NMAX]; int B[NMAX]; int S[NMAX];
int n;
int z[26];

int find(int x) {
	return B[x] == x ? x : (B[x] = find(B[x]));
}

static inline void New(char c) {
	n++;
	C[n] = c;
	B[n] = n;
	S[n] = 1;
	z[c - 'a'] = n;
}

int main() {
	for(int i = 0; i < 26; i++) New('a' + i);
	int l = 99999, r = l - 1;
	for(int c; ; ) {
		c = getchar();
		if(!islower(c)) break;
		Q[++r] = 1 + c - 'a';
	}
	for(int lines = 0; ; lines++) {
		printf("line : %d\n", lines);
		char cmd[24];
		scanf("%s", cmd);
		if(strcmp(cmd, "replace") == 0) {
			char a, b;
			scanf(" %c %c", &a, &b);
			if(a == b) continue;
			int x = a - 'a', y = b - 'a';
			int xx = z[x], yy = z[y];
			if(S[xx] <= S[yy]) {
				B[xx] = yy;
				S[yy] += S[xx];
			} else {
				B[yy] = xx;
				S[xx] += S[yy];
				C[xx] = b;
				z[y] = xx;
			}
			New(a);
		} else if(strcmp(cmd, "remove") == 0) {
			char c;
			scanf(" %c", &c);
			B[z[c - 'a']] = 0;
			New(c);
		} else if(strcmp(cmd, "addhead") == 0) {
			char c;
			scanf(" %c", &c);
			Q[--l] = z[c - 'a'];
		} else if(strcmp(cmd, "addtail") == 0) {
			char c;
			scanf(" %c", &c);
			Q[++r] = z[c - 'a'];
		} else {
			if(strcmp(cmd, "end") == 0) {
				for(; l <= r; l++) {
					int c = find(Q[l]);
					if(c != 0) putchar(C[c]);
				}
				putchar('\n');
			} else {
				printf("invalid command %s\n", cmd);
			}
			break;
		}
	}
	return 0;
}


