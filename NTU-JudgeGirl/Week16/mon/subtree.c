#include "subtree.h"

#include <stdio.h>
#include <stdlib.h>

static int dfs(Node *u, int k, int **p) {
	if (u == NULL)
		return 0;
	int lh = dfs(u->left, k, p);
	int rh = dfs(u->right, k, p);
	if (lh && rh && u->label != k) {
		(*p)[0] = u->label;
		(*p)++;
	}
	return lh || rh || u->label == k;
}
int getNode(Node *root, int label[], int k) {
	int *p = label;
	dfs(root, k, &p);
	return p - label;
}
