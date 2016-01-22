#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>
#define L(rt) (rt<<1)
#define R(rt) (rt<<1|1)
#define ll long long
#define eps 1e-6
using namespace std;

const int maxn=105;
int n,cnt,bestn;
int G[maxn][maxn];
int vis[maxn];
void dfs(int u)
{
    if(u>n)
    {
        if(cnt>bestn) bestn=cnt;
        return;
    }
    bool ok=true;
    for(int i=0;i<u;i++)
    if(vis[i]&&!G[i][u])
    {
        ok=false;
        break;
    }
    if(ok)
    {
        vis[u]=true;
        cnt++;
        dfs(u+1);
        vis[u]=false;
        cnt--;
    }
    if(cnt+n-u>bestn) dfs(u+1);
}
int main()
{
    while(scanf("%d",&n) == 1)
    {
        for(int i=1;i<=n;i++) {
        	for (int j = 1; j <= n; j++)
        		scanf("%d", &G[i][j]);
		}
        cnt=bestn=0;
        memset(vis,false,sizeof(vis));
        dfs(1);
        printf("%d\n",bestn);
    }
}

/*
7
0100110
1010110
0101000
0000100
1101011
1100101
0000110

5
01101
10111
11011
01101
11110
*/
