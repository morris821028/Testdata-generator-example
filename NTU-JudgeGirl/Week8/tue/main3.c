#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX 100000
#define LMAX 100

struct Trie {
	int sid;
	struct Trie *nxt[26];
};
typedef struct Trie Trie;

static int N;
static char *D[NMAX];
static Trie *R;

static int A;
static int B[NMAX];

static void dfs(const char *q, const Trie *t, int flag) {
	if(*q == '\0' && t->sid >= 0) {
		B[A++] = t->sid;
	}
	if(*q != '\0' && t->nxt[*q - 'a'] != NULL) {
		dfs(q + 1, t->nxt[*q - 'a'], flag);
	}
	if(flag != 0) {
		for(int i = 0; i < 26; i++) {
			if(t->nxt[i] != NULL) dfs(q, t->nxt[i], flag - 1);
		}
		if(*q != '\0') {
			dfs(q + 1, t, flag - 1);
			for(int i = 0; i < 26; i++) {
				if(*q != 'a' + i && t->nxt[i] != NULL) {
					dfs(q + 1, t->nxt[i], flag - 1);
				}
			}
		}
	}
}

static int cmp(const void *a, const void *b) {
	return *((int*)a) - *((int*)b);
}

static void solve() {
	int M; char Q[LMAX + 1];
	for(scanf("%d", &M); --M >= 0; ) {
		scanf("%s", Q);
		const char *q = Q;
		const Trie *t = R;
		while(*q != '\0' && t->nxt[*q - 'a'] != NULL) t = t->nxt[*q++ - 'a'];
		if(*q == '\0' && t->sid >= 0) {
			printf(">%s\n", Q);
		} else {
			A = 0;
			dfs(Q, R, 1);
			if(A == 0) {
				printf("!%s\n", Q);
			} else {
				qsort(B, A, sizeof(int), cmp);
				for(int i = 0; i < A; i++) {
					putchar(i == 0 ? '?' : ' ');
					fputs(D[B[i]], stdout);
				}
				putchar('\n');
			}
		}
	}
}

static Trie* New() {
	Trie *p = malloc(sizeof(Trie));
	p->sid = -1;
	memset(p->nxt, 0x00, sizeof(p->nxt));
	return p;
}

static void build() {
	R = New();
	for(int i = 0; i < N; i++) {
		Trie *p = R;
		for(const char *c = D[i]; *c != '\0'; c++) {
			Trie **t = &p->nxt[*c - 'a'];
			if(*t == NULL) *t = New();
			p = *t;
		}
		p->sid = i;
	}
}

static void input() {
	scanf("%d", &N);
	char *p = malloc(N * (LMAX + 1));
	for(int i = 0; i < N; i++) {
		D[i] = p;
		scanf("%s", p);
		while(*p != '\0') p++;
		p++;
	}
}

int main() {
	input();
	build();
	solve();
	return 0;
}


