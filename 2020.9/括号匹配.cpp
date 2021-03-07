#include<bits/stdc++.h>

using namespace std;

char brack[100005];
long long int lef[100005];
long long int righ[100005];
long long int cnt = 0, mid = 0;

void elicom(int n){
	long long int len = strlen(brack);
	//if(brack[0] == ')' && brack[len-1] == '(') return;
	long long int L = 0, R = 0;
	for(int i = 0; i < len; i++){
		if(brack[i] == '('){
			L++;
		}
		if(brack[i] == ')'){
			if(L) L--;
			else R++;
		}
	}
	if(L*R) return;
	if(L) lef[L]++;
	if(R) righ[R]++;
	if(L == 0 && R == 0) mid++;
	if(L){
		if(righ[L]){
			righ[L]--;
			lef[L]--;
			cnt++;
		}
	}
	if(R){
		if(lef[R]){
			lef[R]--;
			righ[R]--;
			cnt++;
		}
	}
}

int main(){
	long long int n;
	memset(lef,0,sizeof(lef));
	memset(righ,0,sizeof(righ));
	scanf("%d", &n);
	char ch = getchar();
	for(int i = 0; i < n; i++){
		scanf("%s", brack);
		elicom(i);
	}
	printf("%lld\n", cnt + mid/2);
}
	
	
