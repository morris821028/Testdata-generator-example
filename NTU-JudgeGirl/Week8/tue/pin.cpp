#include <bits/stdc++.h>
#include <random>
using namespace std;
double frandom() {
	return (double)(rand()%10) / 2;
}
double mrandom() {
	return (rand() * rand())%10;
}
set<string> S;
int main() {
	freopen("in.txt", "w", stdout);
    srand(time(NULL));

    while (S.size() < 50000) {    
		char s[1024];
		int n = rand()%16 + 2;
    	for (int i = 0; i < n; i++)
    		s[i] = rand()%26 + 'a';
    	s[n] = '\0';
		S.insert(s);
		fprintf(stderr, "%d\n", S.size());
	}
    vector<string> A;
	for (set<string>::iterator it = S.begin();
		it != S.end(); it++) {
		A.push_back(*it);
	}
	printf("%d\n", A.size());
	for (int i = 0; i < A.size(); i++)
		puts(A[i].c_str());
	int n = 1000;
	printf("%d\n", n);
	for (int i = 0; i < n; i++) {
		string x;
		while (true) {
			x = A[rand()*rand()%A.size()];
			if (x.length() >= 2)
				break;
		}
		int tt = rand()%3;
		if (tt == 0) {
			x.erase(x.begin() + rand()%x.length());
		} else if (tt == 1) {
			x.insert(x.begin() + rand()%x.length(), 1, rand()%26 + 'a');
		} else {
			x[rand()%x.length()] = rand()%26 + 'a';
		}
		cout << x << endl;
	}
    return 0;
}
