#include<bits/stdc++.h>

using namespace std;

const int mxn = 3e5+5;
int cnt = 1;

typedef struct mission{
	int s;
	int e;
}MISSION;

MISSION m[mxn];

bool compare(MISSION a, MISSION b){
	return a.e < b.e;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d%d", &m[i].s, &m[i].e);
	}
	sort(m,m+n,compare);
//	for(int i = 0; i < n; i++) printf("%d\n", m[i].s);
	int k = 0;
		int i;
		for(i = k + 1; i < n; i++){
			if(m[k].e <= m[i].s){
				cnt++;
				break;
			}
		}
		k = i;
	}
	printf("%d\n", cnt);
}
