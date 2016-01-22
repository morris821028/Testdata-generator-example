#include <bits/stdc++.h>
using namespace std;

typedef struct Node {
    int label;
    struct Node *left, *right;
} Node;
Node nodes[32767];

int n, m;
set<int> S;
void printDfs(Node *u) {
	if (u == NULL) {
		printf("-1 ");
		return ;
	}
	S.insert(u->label);
	printf("%d ", u->label);
	printDfs(u->left);
	printDfs(u->right);
}
Node* build(int l, int r) {
	if (l > r)	return NULL;
	int mid = rand()%(r-l+1)+l;
	Node *u = &nodes[mid];
	u->left = build(l, mid-1);
	u->right = build(mid+1, r);
	return u;
}
int main() {
	freopen("in.txt", "w", stdout);
    srand(time(NULL));
    int testcase = 1;
    while (testcase--) {
    	n = 10000, m = 0;
    	set<int> M;
    	for (int i = 0; i < 2000; i++)
    		M.insert(rand()*rand());
    	for (int i = 0; i < n; i++) {
    		int x = rand()%M.size();
    		set<int>::iterator it = M.begin();
    		advance(it, x);
    		nodes[i].label = *it;	
		}
    	Node *root = build(0, n-1);
    	printDfs(root);
    	puts("");
    	int q = rand()%1000 + 1000;
//    	q = S.size();
    	printf("%d\n", q);
//    	for (set<int>::iterator it = S.begin();
//			it != S.end(); it++) {
//    		printf("%d\n", *it);
//		}
    	for (int i = 0; i < q; i++) {
    		int x = rand()%S.size();
    		set<int>::iterator it = S.begin();
    		advance(it, x);
    		printf("%d\n", *it);
		}
	}
    return 0;
}

