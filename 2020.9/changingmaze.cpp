#include<bits/stdc++.h>

using namespace std;

const int mxn = 200 + 10;
char mapx[mxn][mxn];
int stx, sty;
int edx, edy;
int vis[mxn][mxn][65];
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };
int k, n, m, T;
int flag = 0;

struct point{
	int x, y, time;
	point() {}
	point(int x, int y, int time) {
		this->x = x; this->y = y; this->time = time;
	}
};

bool can(int x,int y){
	if(0 <= x && x < n && 0 <= y && y < m && mapx[x][y] != '#') return true;
	else return false;
}

void bfs(int x, int y) {
	queue<point> q;
	q.push(point(x, y, 0));
	vis[x][y][0] = 1;
	while (!q.empty()) {
		point now = q.front();
		if (now.x == edx && now.y == edy) {
			printf("%d\n", now.time);
			flag = 1;
			return;
		}
		else {
			for (int i = 0; i < 4; i++) {
				int tx = now.x + dx[i];
				int ty = now.y + dy[i];
				if (can(tx,ty) && (mapx[tx][ty] != '*' || (now.time+1)%k == 0) && vis[tx][ty][(now.time + 1) % k] == 0){
					vis[tx][ty][(now.time + 1) % k] = 1;
					q.push(point(tx, ty, now.time + 1));
				}
			}
		}
		q.pop();
	}
	while(!q.empty()) q.pop(); 
}


int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &n, &m, &k);
		memset(vis, 0, sizeof(vis));
		flag = 0;
		for (int i = 0; i < n; i++) {
			scanf("%s",&mapx[i]);
			for(int j = 0; j < m; j++){
				if(mapx[i][j] == 'S'){
					stx = i;
					sty = j;
				}
				if(mapx[i][j] == 'E'){
					edx = i;
					edy = j;
				}
			}
		}
/*		for(int i = 0; i < n; i++){
			printf("%s\n", mapx[i]);
		}
		cout << edx << " " << edy <<endl;*/
		bfs(stx, sty);
		if (flag == 0) puts("-1\n");
	}
	system("pause");
}
