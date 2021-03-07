#include<bits/stdc++.h>

using namespace std;

int hcard[200005];
int pcard[200005];
int pp[200005];
int cnt = 0;

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &hcard[i]);
	}
	memset(pcard,0,sizeof(pcard));
	memset(pp,0,sizeof(pp));
	for(int i = 1; i <= n; i++){
		int temp;
		scanf("%d", &temp);
		pcard[temp] = i;
	}
	int k;
	int kk;
	int pos;
	if(pcard[1] > 0){
		for( k = 2; k <= n; k++){
			if(pcard[k] != pcard[k-1] + 1){	break;}
		}
		if(pcard[k - 1] == n){
			for(pos = k; pos <= n; ++pos)
				if(pcard[pos] > pos - k) break; 
			if(pos > n){
				cnt = n - k + 1;
				printf("%d\n",  cnt);
				return 0;
			}
		}
	}
	int maxn = 0;
	for(int i = 1; i <= n; i++){
		maxn = max(pcard[i]+n+1-i,maxn);
	}
	cnt = maxn;
	printf("%d\n", cnt);
}
	
