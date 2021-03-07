#include<bits/stdc++.h>
using namespace std;

void Cal(vector<int> &a,vector<int> &b, vector<int> &ans,int &la,int &lb,int &lc){
	for(int i = 1; i <= la; i++){
		for(int j = 1; j <= lb; j++){
			ans[i+j-1] += a[i]*b[j];
		}
	}
	for(int i = 1; i <= lc; i++){
		ans[i+1] += ans[i]/10,ans[i] %= 10;
	}
	while(ans[lc] == 0) lc--;
}

int main(){
	string s1,s2;
	cin >> s1 >> s2;
	int la = s1.length(),lb = s2.length(),lc = la+lb;
	vector<int> a(la+1,0),b(lb+1,0),ans(lc+2,0);
	for(int i = 1; i <= la; i++){
		a[i] = s1[la-i] - '0';
	}
	for(int i = 1; i <= lb; i++){
		b[i] = s2[lb-i] - '0';
	}
	Cal(a,b,ans,la,lb,lc);
	for(int i = lc; i >= 1; i--){
		cout << ans[i];
	}
	puts("");
}