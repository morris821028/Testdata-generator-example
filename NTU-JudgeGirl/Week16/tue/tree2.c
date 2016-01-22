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
	Node *A = (Node*) malloc(sizeof(Node) * n);
	for (int i = 0; i < n; i++) {
		A[i].label = array[i];
		A[i].left = A[i].right = NULL;
		if (i*2+1 < n)
			A[i].left = &A[i*2+1];
		if (i*2+2 < n)
			A[i].right = &A[i*2+2];
	}
	return A;
}
