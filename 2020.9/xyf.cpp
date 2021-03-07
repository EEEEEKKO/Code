#include<bits/stdc++.h>

using namespace std;

const int N = 3000005;

int n, st, ed;
vector<int> edge[N];
int ans[N];

inline bool bfs(){
	queue<int> q;
	q.push(st);
	ans[st] = 1;
	while(!q.empty()){
		int cur = q.front(); q.pop();
		for(auto &to : edge[cur]){
			if(ans[to])	continue;
			ans[to] = ans[st] + 1;
			if(to == ed){
				printf("%d\n", ans[to] + 1);
				return true;
			}
			q.push(to);
		}
	}
	return false;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int a, b; scanf("%d%*d%*d%d", &a, &b);
		edge[a].emplace_back(b);
	}
	int a[10], b[10];
	scanf("%d%d%d%d%d%d%d%d", &a[1], &a[2], &a[3], &a[4], &b[1], &b[2], &b[3], &b[4]);
	if(a[1] == b[1] && a[2] == b[2] && a[3] == b[3] && a[4] == b[4])
		return puts("1"), 0;
	st = a[4], ed = b[1];
	if(!bfs())	puts("-1");
	return 0;
}
