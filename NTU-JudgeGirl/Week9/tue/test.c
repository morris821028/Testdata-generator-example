#include <stdio.h>

#define haszero(v) (((v) - 0x0101010101010101LLU) & ~(v) & 0x8080808080808080LLU)
#define hasone(v) haszero(~v)
#define mtranspose(x, t) t = (x ^ (x >> 7)) & 0x00AA00AA00AA00AALLU; \
   x = x ^ t ^ (t << 7); \
   t = (x ^ (x >> 14)) & 0x0000CCCC0000CCCCLLU; \
   x = x ^ t ^ (t << 14); \
   t = (x ^ (x >> 28)) & 0x00000000F0F0F0F0LLU; \
   x = x ^ t ^ (t << 28);
#define VERT(x, y) ((x)*8+(y))
void printBlock(unsigned long long const *block) {
	for (int i = 0; i < 8; i++, puts("")) {
		for (int j = 0; j < 8; j++)
			printf("%llu", (*block)>>(VERT(i, j))&1);
	}
}
#undef VERT

int main() {
#define VERT(x, y) ((x)*8+(y))
	char s[1666];
	while (1) {
		unsigned long long g = 0, t;
		for (int i = 0; i < 8; i++) {
			scanf("%s", s);
			for (int j = 0; j < 8; j++)
				if (s[j] == '1')
				g |= 1LLU<<VERT(i, j);
		}
		mtranspose(g, t);
		printBlock(&g);
		printf("%llX\n", hasone(g));
		t = hasone(g);
		printBlock(&t);
		printf("%llX\n", __builtin_ctzll(hasone(g))>>3);
	}
	return 0;
#undef VERT
}
/*

00000000
00000000
00000000
00000000
00000000
00000000
00000000
11111111

00000000
11111111
00000000
00000000
00000000
00000000
11111111
00000000

00000000
00000000
11111111
00000000
00000000
00000000
11111111
00000000

11111111
00000000
11111111
00000000
00000000
00000000
11111111
00000000
*/
