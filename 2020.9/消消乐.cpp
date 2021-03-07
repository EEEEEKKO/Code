#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
#define mp(x, y) make_pair(x, y)

const int N = 12;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int n, m, g[N][N];
bool vis[N][N];

inline bool valid(int x, int y){ return x >= 0 && x <= n && y >= 0 && y <= m; }

stack<pair<pii, pii>> ans;
stack<pair<int, pair<pii, int>>> stk;

int cnt;
void count(int x, int y, int col){
	cnt++;
	vis[x][y] = true;
	for(int i = 0; i < 4; i++){
		int tx = x + dx[i], ty = y + dy[i];
		if(valid(tx, ty) && !vis[tx][ty] && g[tx][ty] == col)
			count(tx, ty, col);
	}
}
void eliminate(int step, int x, int y, int col){
	stk.push(mp(step, mp(mp(x, y), g[x][y])));
	g[x][y] = 0;
	vis[x][y] = true;
	for(int i = 0; i < 4; i++){
		int tx = x + dx[i], ty = y + dy[i];
		if(valid(tx, ty) && !vis[tx][ty] && g[tx][ty] == col)
			eliminate(step, tx, ty, col);
	}
}
void dfs(int step, int sum){
	if(sum == 0){
		printf("%d\n", (int)ans.size());
		vector<pair<pii, pii>> v;
		while(!ans.empty()){
			v.push_back(ans.top());
			ans.pop();
		}
		reverse(v.begin(), v.end());
		for(auto &k : v)
			printf("%d %d %d %d\n", k.first.first, k.first.second, k.second.first, k.second.second);
		exit(0);
	}
	for(int x = 1; x <= n; x++){
		for(int y = 1; y <= m; y++){
			if(!g[x][y])	continue;
			for(int i = 1; i < 3; i++){
				int tx = x + dx[i], ty = y + dy[i];
				if(!valid(tx, ty))	continue;
				if(!g[tx][ty])	continue;
				int newsum = sum;
				swap(g[tx][ty], g[x][y]);
				bool ok = false;

				cnt = 0; memset(vis, 0, sizeof vis); count(tx, ty, g[tx][ty]);
				if(cnt >= 3){ memset(vis, 0, sizeof vis);
					eliminate(step, tx, ty, g[tx][ty]); newsum -= cnt; ok = true; }
				cnt = 0; memset(vis, 0, sizeof vis); count(x, y, g[x][y]);
				if(cnt >= 3){ memset(vis, 0, sizeof vis);
					eliminate(step, x, y, g[x][y]); newsum -= cnt; ok = true; }
				
				if(ok){
					ans.push(mp(mp(x, y), mp(tx, ty)));
					dfs(step + 1, newsum);
					while(!stk.empty() && stk.top().first == step){
						auto cur = stk.top().second;
						g[cur.first.first][cur.first.second] = cur.second;
						stk.pop();
					}
					ans.pop();
				}
				swap(g[tx][ty], g[x][y]);
			}
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);
	int sum = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			scanf("%d", &g[i][j]), sum += (g[i][j] != 0);
	dfs(1, sum);
}