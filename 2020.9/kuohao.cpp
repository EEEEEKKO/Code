#include<bits/stdc++.h>

using namespace std;

char brack[1000005];
long long int lef[1000005];
long long int righ[1000005];
long long int cnt = 0, mid = 0;

void elicom(int n){
	long long int len = strlen(brack);
	if(brack[0] == ')' && brack[len-1] == '(') return;
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
	if(L * R) return;
	if(L) lef[L]++;
	if(R) righ[R]++;
	if(L == 0 && R == 0) mid++;
}

int main(){
	long long int n;
	memset(lef,0,sizeof(lef));
	memset(righ,0,sizeof(righ));
	memset(brack,0,sizeof(brack));
	scanf("%d", &n);
	char ch = getchar();
	for(int i = 0; i < n; i++){
		scanf("%s", brack);
		elicom(i);
	}
	for(int i = 0; i < n; i++){
		cnt += min(lef[i],righ[i]);
	}
	printf("%lld\n", cnt + mid/2);
}
	
	
