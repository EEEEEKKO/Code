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
	int flag = 1;
	memset(pcard,0,sizeof(pcard));
	memset(pp,0,sizeof(pp));
	for(int i = 1; i <= n; i++){
		int temp;
		scanf("%d", &temp);
		pp[i] = temp;
		if(temp == flag) flag++;
		else flag = 1;
		pcard[temp] = i;
	}
	int pos;
	if(pcard[1] == n || flag > 1){
		pos = pcard[1];
		int k = 1;
		for(int i = 1; i < pos; i++){
			if(pcard[flag] <= k){
				flag++;
				k++;
			}
			else break;
		}
		if(flag == n+1){ cnt = pos - 1; printf("%d\n", cnt); return 0;}
	}
/*	if(pcard[1]){
		cnt += pcard[1];
	}
	int k = n;
	for(int i = n; i >= 1 ; i--){
		if(pp[i]){
			k = i;
			break;
		}
	}
	int kk = k;
	for(int i = k; i >= 1; i--){
		if(pp[i - 1] == 0 || pp[i] < pp[i-1]){
			kk = i;
			break;
		}
	}
	int kkk = kk;
	for(int i = kk - 1; i >= 1; i--){
		if(pp[i]){
			kkk = i;
			break;
		}
	}
	cout << k <<endl;
	cout << kk <<endl;
	cout << kk << endl;
	cout << n <<endl;
	cout << pcard[1] << endl;
	cnt += kkk + n - pcard[1];*/
	int maxn = 0;
	for(int i = 1; i <= n; i++){
		maxn = max(pcard[i]+n+1-i,maxn);
	}
	cnt = maxn;
	printf("%d\n", cnt);
}
	
