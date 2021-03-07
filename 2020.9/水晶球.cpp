#include<bits/stdc++.h>

using namespace std;

const int mxn = 1e5 + 5;
int maxn = -1;
int flag[2];

typedef struct crystal{
	int lll;
	int ll;
	int l;
	int pos;
}CRY;

CRY cry[mxn];

bool compare(CRY a, CRY b){
	if(a.lll == b.lll){
		if(a.ll == b.ll){
			return a.l > b.l;
		}
		return a.ll > b.ll;
	}
	return a.lll > b.lll;
}

int main(){
	int n;
	scanf("%d", &n);
	memset(flag,0,sizeof(flag));
	for(int i = 0; i < n; i++){
		int a[3];
		scanf("%d%d%d", &a[0],&a[1],&a[2]);
		sort(a,a+3);
		cry[i].l = a[0], cry[i].ll = a[1], cry[i].lll = a[2];
		cry[i].pos = i + 1;
	}
	sort(cry,cry+n,compare);
	int maxn = -1;
	int sinmax = -1;
	int p;
	for(int i = 0; i < n; i++){
		if(sinmax < cry[i].l){
			sinmax = cry[i].l;
			p = cry[i].pos;
		}
	}
	maxn = sinmax;
	for(int i = 0; i < n - 1; i++){
//		if(2 * cry[i].l <= maxn) break;
			if(cry[i].lll == cry[i+1].lll && cry[i].ll == cry[i+1].ll){
				int temp = cry[i].l + cry[i+1].l; 
				temp = min(temp, cry[i].ll);
				if(maxn < temp){
					maxn = temp;
					flag[0] = cry[i].pos;
					flag[1] = cry[i+1].pos;
				}
			}
	}
	if(maxn <= sinmax){
		printf("%d\n", 1);
		printf("%d\n", p);
	}
	else{
		printf("%d\n", 2);
		if(flag[0] > flag[1]){
			int temp = flag[0];
			flag[0] = flag[1];
			flag[1] = temp;
		}
		printf("%d %d\n", flag[0], flag[1]);
	}
}
