#include<bits/stdc++.h>

using namespace std;

const int mxn = 3e5 + 5;
int head[mxn], vis[mxn];
int cnt = 0, flag = 1;
int n, m,stx,sty;
int ans = 0, len = 0;
int minn = 3e5 + 5;

struct Edge {
	int to, next;
}edge[mxn];

void add(int u, int v) {
	edge[cnt].to = v;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}

void dfs(int x) {
	vis[x] = 1;
	int temp = ++len;
	for (int i = head[x]; i != -1; i = edge[i].next) {
		int tt = edge[i].to;
		if (vis[tt] == 0) dfs(tt);
		else{
			ans = len;
			flag = 0;
			return;
		}
	}
	vis[x] = 0;
	len = temp;
}
		

int main() {
	scanf("%d%d", &n,&m);
	memset(head, -1, sizeof(head));
	memset(vis, 0, sizeof(vis));
	scanf("%d%d",&stx,&sty);
	if (stx == sty) {
		minn = 1;
		flag = 0;
	}
	add(stx,sty);
	for (int i = 1; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		if(a == b){
			minn = min(minn,i+1);
			flag = 0;
		}
		add(a, b);
	}
	dfs(stx);
	if(flag == 0){
		ans = min(minn,ans);
		printf("%d\n",ans);
	}
	if (flag) printf("%d\n", -1);
}

