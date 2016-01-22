#include "subtree.h"

#include <stdio.h>
#include <stdlib.h>

static int n = 0;
static int dfs(Node *u, int k, int label[]) {
	int lh, rh;
	lh = u->left != NULL && dfs(u->left, k, label);
	rh = u->right != NULL && dfs(u->right, k, label);
	if (lh && rh && u->label != k)
		label[n++] = u->label;
	return lh || rh || u->label == k;
}
int getNode(Node *root, int label[], int k) {
	n = 0;
	root != NULL && dfs(root, k, label);
	return n;
}
