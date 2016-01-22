#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int testcase = 1;
    while (testcase--) {
    	int n = 50000;
    	printf("%d\n", n+1);
    	for (int i = 0; i < n+1; i++)
    		printf("%d%c", rand()%n+1, i == n ? '\n' : ' ');
	}
    return 0;
}
