#include <bits/stdc++.h>
#include <random>
using namespace std;
int main() {
	ifstream fin("ing/inactive.txt");
	set<string> dict;
	string word;
	while (fin >> word)
		dict.insert(word);
	freopen("in.txt", "w", stdout);
    srand(time(NULL));
    int testcase = 1;
    while (testcase--) {
    	int spec = 4, cmds = 50000, n = 16;
    	printf("%d\n", spec);
    	printf("%d %d\n", n, cmds);
    	int mm[8] = {1, 5, 4, 2, 3};
    	set<string> S[1024], S2[1024];
    	for (int i = 0; i < cmds; i++) {
    		int cmd = mm[rand()%5], mid = rand()%n;
    		printf("%d %d ", cmd, mid);
    		if (cmd == 1) {			// addActive
    			if (S[mid].size() == 2) {
    				if (rand()%5) {
    					set<string>::iterator it = S[mid].begin();
    					advance(it, rand()%S[mid].size());
    					printf("%s %d\n", it->c_str(), rand()%10);
    				} else {
    					set<string>::iterator it = dict.begin();
    					advance(it, rand()%dict.size());
    					printf("%s %d\n", it->c_str(), rand()%10);
					}
				} else {
    				set<string>::iterator it = dict.begin();
    				advance(it, rand()%dict.size());
    				S[mid].insert(*it);
    				printf("%s %d\n", it->c_str(), rand()%10);
    			}
			} else if (cmd == 5) {		// totalWeight
				printf("\n");
			} else if (cmd == 4) {		// maxIngredient
				printf("\n");
			} else if (cmd == 2) {		// addInactive
				if (S2[mid].size() == 5) {
					if (rand()%5) {
    					set<string>::iterator it = S2[mid].begin();
    					advance(it, rand()%S2[mid].size());
    					printf("%s %d\n", it->c_str(), rand()%10);
    				} else {
    					set<string>::iterator it = dict.begin();
    					advance(it, rand()%dict.size());
    					printf("%s %d\n", it->c_str(), rand()%10);
					}
				} else {
    				set<string>::iterator it = dict.begin();
    				advance(it, rand()%dict.size());
    				S2[mid].insert(*it);
    				printf("%s %d\n", it->c_str(), rand()%10);
    			}
			} else if (cmd == 3) {
				printf("\n");
			}
		}
	}
    return 0;
}
