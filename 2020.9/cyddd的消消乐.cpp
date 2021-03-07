#include<bits/stdc++.h>
#define mp(x,y) make_pair(x,y)

using namespace std;

typedef pair<int,int> pos;
stack<pair<pos,pos>> ans;
stack<pair<int, pair<pos, int>>> change;

const int mxn = 15;
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
int n,m,cnt,bingo[mxn][mxn];
int vis[mxn][mxn];

void dfs(int num, int k);

int main(){
	scanf("%d%d",&n,&m);
	int num = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%d",&bingo[i][j]);
			if(bingo[i][j] != 0) num++;
		}
	}
	dfs(num,1);
}

int can(int x, int y){
	if(x >= 0 && x <= n && y >= 0 && y <= m)return 1;
	else return 0;
}

void binn(int p, int x, int y, int k){
	change.push(mp(k,mp(mp(x,y),bingo[x][y])));
	bingo[x][y] = 0; vis[x][y] = 1;
	for(int i = 0; i < 4; i++){
		int tx = x + dx[i];
		int ty = y + dy[i];
		if(can(tx,ty) && vis[tx][ty] == 0 && bingo[tx][ty] == p)
			binn(p,tx,ty,k);
	}
}

void count(int p, int x, int y){
	vis[x][y] = 1;cnt++;
	for(int i = 0; i < 4; i++){
		int tx = x + dx[i];
		int ty = y + dy[i];
		if(can(tx,ty) && vis[tx][ty] == 0 && bingo[tx][ty] == p)
			count(p,tx,ty);
	}

}

void print(){
	printf("%d\n", (int)ans.size());
	vector<pair<pos, pos>> outt;
	while(!ans.empty()){
		outt.push_back(ans.top());
		ans.pop();
	}
	reverse(outt.begin(), outt.end());
	for(auto &f : outt)
		printf("%d %d %d %d\n", f.first.first, f.first.second, f.second.first, f.second.second);

}

void dfs(int num, int k){
	if(num == 0){
		print();
		exit(0);
	}
	for(int x = 1; x <= n; x++){
		for(int y = 1; y <= m; y++){
			if(bingo[x][y] == 0) continue;
			for(int i = 1; i <= 2; i++){
				int tx = x + dx[i];
				int ty = y + dy[i];
				if(!can(tx,ty) || bingo[tx][ty] == 0 )continue;
				int nownum = num;
				swap(bingo[tx][ty],bingo[x][y]);
				int flag = 0;
				memset(vis,0,sizeof vis);
				cnt = 0;count(bingo[tx][ty],tx,ty);
				if(cnt >= 3){
					memset(vis,0,sizeof vis);
					binn(bingo[tx][ty],tx,ty,k);
					nownum -= cnt;
					flag = 1;
				}
				memset(vis,0,sizeof vis);
				cnt = 0;count(bingo[x][y],x,y);
				if(cnt >= 3){
					memset(vis,0,sizeof vis);
					binn(bingo[x][y],x,y,k);
					nownum -= cnt;
					flag = 1;
				}
				if(flag){
					ans.push(mp(mp(x,y),mp(tx,ty)));
					dfs(nownum,k+1);
					while(!change.empty() && change.top().first == k){
						auto temp = change.top().second;
						bingo[temp.first.first][temp.first.second] = temp.second;
						change.pop();
					}
					ans.pop();
				}
				swap(bingo[tx][ty],bingo[x][y]);
			}
		}
	}
}

