#include<bits/stdc++.h>

using namespace std;

const int mxn = 2e6 + 5;
int head[mxn],vis[mxn],q[mxn];
int cnt = 0, flag = 1;
int ans[mxn];

struct Edge {
	int to, next;
}edge[mxn];

void add(int u, int v) {
	edge[cnt].to = v;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}

void bfs(int start, int endf, int ende) {
	vis[start] = 1;
	int h = 0, tail = 0;
	q[tail] = start;
	ans[start] = 1;
	tail++;
	while (h < tail) {
		for (int i = head[q[h]]; i != -1; i = edge[i].next) {
			int tt = edge[i].to;
			if (q[h] == endf && tt == ende) {
				ans[tt] = ans[q[h]] + 1;
				printf("%d\n", ans[tt]);
				flag = 0;
				return;
			}
			else {
				if (vis[tt] == 0) {
					q[tail] = tt;
					vis[tt] = 1;
					ans[tt] = ans[q[h]] + 1;
					tail++;
				}
			}
		}
		h++;
	}
}


int main() {
	int m;
	scanf("%d", &m);
	memset(head, -1, sizeof(head));
	memset(ans,0,sizeof(ans));
	memset(vis,0,sizeof(vis));
	for (int i = 0; i < m; i++) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		if(a != d) add(a, d);
	}
	int st[4];
	for (int i = 0; i < 4; i++) scanf("%d", &st[i]);
	int ed[4];
	for (int i = 0; i < 4; i++) scanf("%d", &ed[i]);
	int k = 0;
	for(int i = 0; i < 4; i++){
		if(st[i] == ed[i]) k++;
	}
	if(k == 4){
		printf("%d\n", 1);
		return 0;
	}
	bfs(st[3], ed[0], ed[3]);
	if (flag) printf("%d\n",-1 );
	return 0;
}

