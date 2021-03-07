#include<bits/stdc++.h>

using namespace std;

struct words{
	int cnt;
	unsigned char cn[5];
}wd[65536];

int main(){
	unsigned string utf[3];
	int ucode;
	memset(utf,0,sizeof(utf));
	memset(wd,0,sizeof(wd));
	while(scanf("%c", &utf[0]) != EOF){
		if((utf[0] >> 4) >= 12 && (utf[0] >> 4) < 14){
			scanf("%c", &utf[1]);
			ucode = ((utf[0] & 31) << 6) + (utf[0] & 63);
			for(int i = 0; i < 2; i++){
				wd[ucode].cn[i] = utf[i];
			}
			wd[ucode].cn[2] = '\0';
			wd[ucode].cnt++;
		}
		if((utf[0] >> 4) == 14){
			scanf("%c%c", &utf[1], &utf[2]);
			ucode = ((utf[0] & 15) << 12) + ((utf[1] & 63) << 6) + (utf[2] & 63);
			for(int i = 0; i < 3; i++){
				wd[ucode].cn[i] = utf[i];
			}
			wd[ucode].cn[3] = '\0';
			wd[ucode].cnt++;
		}
	}
	int flag = 0;
	for(int i = 0; i < 65535; i++){
		if(wd[i].cnt > 1){
			printf("%s 0x%04x %d\n", wd[i].cn, i, wd[i].cnt);
			flag = 1;
		}
	}
	if(!flag) printf("No repeat!\n");
}
	
