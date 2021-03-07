#include<bits/stdc++.h>

using namespace std;

const int mxn = 3e5 + 5;
int vis[mxn],root[mxn];
int flag = 0;


struct Things {
	int pos;
	int to;
	Things(){}
	Things(int pos, int to){
		this->pos = pos; this->to = to;
	}
};

queue<Things> q[mxn];

int dfs(int og, int border) {
	vis[og] = 1;
	root[og] = 1;
	int size = q[og].size();
	for (int i = 0; i < size; i++) {
		Things tt = q[og].front();
		q[og].pop();
		if (tt.pos > border) continue;
		if (root[tt.to]) {
			flag = 1;
			return 1;
		}
		if (vis[tt.to]) continue;
		if (dfs(tt.to, border)) {
			flag = 1;
			return 1;
		}
	}
	root[og] = 0;
	return 0;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int origin,visit;
		scanf("%d%d", &origin, &visit);
		q[origin].push(Things(i+1,visit));
	}
	int l = 0, mid,r;
	for (r = m + 1; r > l + 1;) {
		memset(vis, 0, sizeof(vis));
		memset(root,0,sizeof(root));
		mid = (r + l) >> 1;
		int k = 0;
		for (int i = 1; i <= m; i++) {
			if (vis[i]) continue;
			if (dfs(i, mid)) k = 1;
		}
		if (k) r = mid;
		else l = mid;
	}
	if (flag) printf("%d\n", r);
	else printf("-1\n");
}

