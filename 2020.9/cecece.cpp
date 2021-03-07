#include<bits/stdc++.h>
#define mxn 200005
#define LL long long

using namespace std;

int n, rt,t = 0;
int a[mxn], flag[mxn];
int d[mxn], siz[mxn], ans[mxn];
vector<int> q[mxn];

void dfs_sort(int x) {
	siz[x] = 1;
	t++;
	d[x] = t;
	int temp = q[x].size();
	for (int i = 0; i < temp; i++) {
		dfs_sort(q[x][i]);
		siz[x] += siz[q[x][i]];
	}
}

void dfs_sagain(int x) {
	if (flag[x]) sort(ans + d[x], ans + d[x] + siz[x]);
	else {
		for (int i = 0; i < q[x].size(); i++) {
			dfs_sagain(q[x][i]);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		rt ^= i;
	}
	for (int i = 1; i <= n; i++) scanf("%d", &flag[i]);
	for (int i = 1; i < n; i++) {
		int father, son;
		scanf("%d%d", &father, &son);
		q[father].push_back(son);
		rt ^= son;
	}
	for (int i = 1; i <= n; i++) {
		if (q[i].size() > 1) {
			sort(q[i].begin(), q[i].end());
		}
	}
	dfs_sort(rt);
	for (int i = 1; i <= n; i++) ans[d[i]] = a[i];
	dfs_sagain(rt);
	printf("[");
	for (int i = 1; i <= n; i++) {
		if (i == n) printf("%d]\n", ans[i]);
		else printf("%d,", ans[i]);
	}
}
