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
	Node **B = (Node**) malloc(sizeof(Node*) * n);
	for (int i = 0; i < n; i++)
		B[i] = (Node *) malloc(sizeof(Node));
	for (int i = 0; i < n; i++) {
		B[i]->label = array[i];
		B[i]->left = B[i]->right = NULL;
		if (i*2+1 < n)
			B[i]->left = B[i*2+1];
		if (i*2+2 < n)
			B[i]->right = B[i*2+2];
	}
	Node *root = B[0];
	free(B);
	return root;
}
