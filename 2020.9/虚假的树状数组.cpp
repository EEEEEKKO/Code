#include<bits/stdc++.h>
#define N 200005
#define LL long long
#define mod
#define pr pair<int,int>
#define mp(x,y) make_pair(x,y)
using namespace std;

LL read(){
    char c=getchar();
    LL f=1,t=0;
    while(c>'9'||c<'0') f=(c=='-')?-1:1,c=getchar();
    while(c>='0'&&c<='9') t=t*10+c-'0',c=getchar();
    return t*f;
}

int n,rt,cnt,a[N],tag[N];
int dfn[N],sz[N],seg[N];
vector<int> vc[N];

void dfs1(int x){ //第一遍dfs求dfs序 
	sz[x]=1,dfn[x]=++cnt;
	int m=vc[x].size();
	for(int i=0;i<m;i++) 
		dfs1(vc[x][i]),sz[x]+=sz[vc[x][i]]; 
}

void dfs2(int x){ //第二遍dfs进行排序 
	int m=vc[x].size();
	if(tag[x]) sort(seg+dfn[x],seg+dfn[x]+sz[x]); //若有标记则不考虑子树内的点 
	else for(int i=0;i<m;i++) dfs2(vc[x][i]); 
}

int main(){
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) tag[i]=read(),rt^=i;
	for(int i=1,x,y;i<n;i++) x=read(),y=read(),vc[x].push_back(y),rt^=y;
	for(int i=1;i<=n;i++) if(vc[i].size()>1) sort(vc[i].begin(),vc[i].end());
	dfs1(rt);
	for(int i=1;i<=n;i++) seg[dfn[i]]=a[i];
	dfs2(rt),printf("[");
	for(int i=1;i<n;i++) printf("%d,",seg[i]);
	return printf("%d]\n",seg[n]),0;
}
/*
7
12 1 10 8 8 11 2
0 0 0 0 1 0 0
2 3
2 4
2 5
3 1
3 6
5 7
*/
