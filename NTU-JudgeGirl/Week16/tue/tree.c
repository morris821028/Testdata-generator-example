#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static Node* build(int idx, int A[], int n) {
	if (idx >= n)	return NULL;
	Node *u = (Node *) malloc(sizeof(Node));
	u->label = A[idx];
	u->left = build(idx*2+1, A, n);
	u->right = build(idx*2+2, A, n);
	return u;
}
Node* construct(int array[], int n) {
	return build(0, array, n);
}
