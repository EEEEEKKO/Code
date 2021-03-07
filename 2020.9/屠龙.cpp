	#include<bits/stdc++.h>
	
	using namespace std;
	
	const int mxn = 2e5 + 5;
	long long attack = 0, money = 0;
	
	typedef struct dragon{
		int power;
		int exp;
		int cnt;
	}DRA;
	
	DRA drap[mxn];
	DRA dram[mxn];
	
	bool compare(DRA a, DRA b){
		return a.power < b.power;
	}
	
	bool cc(DRA a, DRA b){
		return a.cnt > b.cnt;
	}
	
	int main(){
		int n;
		scanf("%d", &n);
		int plus = 0, minus = 0;
		for(int i = 0; i < n; i++){
			int p, e;
			scanf("%d%d", &p, &e);
			if(e < 0){
				dram[minus].power = p;
				dram[minus].exp = e;
				dram[minus].cnt = p + e;
				minus++;
			}
			else{
				drap[plus].power = p;
				drap[plus].exp = e;
				plus++;
			}
		}
		sort(drap,drap+plus,compare);
		for(int i = 0; i < plus; i++){
			if(attack < drap[i].power){
				money += drap[i].power - attack;
				attack = drap[i].power;
				attack += drap[i].exp;
			}
			else{
				attack += drap[i].exp;
			}
		}
		sort(dram,dram+minus,cc);
	//	for(int i = 0; i < minus; i++){
	//		cout << dram[i].power << endl;
	//	}
		for(int i = 0; i < minus; i++){
			if(attack < dram[i].power){
				money += dram[i].power - attack;
				attack = dram[i].power;
				attack += dram[i].exp;
			}
			else{
				attack += dram[i].exp;
			} 
		}
		printf("%lld\n", money);
	}
