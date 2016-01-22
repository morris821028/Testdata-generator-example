#include <bits/stdc++.h>
#include <random>
using namespace std;
void load_dict(set<string> &dict) {
	ifstream fin("dict/dict2.txt");
	string word;
	while (fin >> word)
		dict.insert(word);
}
void generate_dict(set<string> &dict) {
	for (int i = 0; i < 2016; i++) {
		int len = rand()%127 + 1;
		string word = "";
		for (int j = 0; j < len; j++)
			word += rand()%10 + '0';
		dict.insert(word);
	}
}
int main() {
	set<string> dict;
//	load_dict(dict);
	generate_dict(dict);
	freopen("in.txt", "w", stdout);
    srand(time(NULL));
    int testcase = 1;
    while (testcase--) {
    	int spec = 5, cmds = 2000;
    	set<int> keys;
    	printf("%d\n", spec);
    	printf("%d\n", cmds);
    	int mmm[10] = {1, 2, 6};
    	for (int i = 0; i < cmds; i++) {
//    		int cmd = rand()%4 + 1, mid = rand()%2;
//    		if (cmd == 3 && rand()%10)
//    			cmd = 2;
//    		if (cmd == 1 && rand()%10)
//    			cmd = 2;
//    		if (spec == 4 && cmd == 4)
//    			cmd = 5;
//    		if (spec == 4 && cmd == 1)
//    			cmd = 5;
			int cmd = rand()%3, mid = rand()%2;
			cmd = mmm[cmd];
			if (cmd == 1 & rand()%20)
				cmd = 6;
    		if (cmd == 1) {
    			printf("%d %d\n", cmd, mid);
    		} else if (cmd == 2) {
    			set<string>::iterator it = dict.begin();
    			advance(it, rand()%dict.size());
    			int key;
    			while (true) {
    				key = (rand() * rand())%100000;
    				if (keys.size() == 1024 & keys.count(key) == 0) {
    					set<int>::iterator it = keys.begin();
    					int v = rand()%keys.size();
    					advance(it, v);
    					key = *it;
    					break;
    				}
    				keys.insert(key);
    				if (keys.size() < 1024)
    					break;
				}
    			printf("%d %d %d %s\n", cmd, mid, key, it->c_str());
    		} else if (cmd  == 3) {
    			if (keys.size() != 0) {
    				set<int>::iterator it = keys.begin();
    				int v = rand()%keys.size();
    				advance(it, v);
    				printf("%d %d %d\n", cmd, mid, *it);
    			} else {
    				printf("%d %d %d\n", cmd, mid, -1);
				}
			} else if (cmd == 4) {
				set<string>::iterator it = dict.begin();
    			advance(it, rand()%dict.size());
				printf("%d %d %s\n", cmd, mid, it->c_str());
			} else if (cmd == 5) {
				printf("%d %d\n", cmd, mid);
			} else if (cmd == 6) {
				if (keys.size() != 0) {
    				set<int>::iterator it = keys.begin();
    				int v = rand()%keys.size();
    				advance(it, v);
    				printf("%d %d %d\n", cmd, mid, *it);
    			} else {
    				printf("%d %d %d\n", cmd, mid, -1);
				}
			}
		}
	}
    return 0;
}
