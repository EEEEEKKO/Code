#include <bits/stdc++.h>
using namespace std;

int a[300005];//fÎª¸¨ÖúÊı×é 
long long ct=0; 
int f[300005];
void px(int l,int r){
    if(l>=r){
	 return;
	}
	else{
		int mid=(l+r)/2;
    	px(l,mid);
    	px(mid+1,r);
    	int ll = l,rr = mid+1;
    	int i = l;    
    	while(rr<=r && ll<=mid){
    		if(a[ll]<=a[rr]){
    			f[i++]=a[ll++];
			}
			else{
				f[i++]=a[rr++];
				ct+=mid+1-ll;
				//printf("%lld",ct);
			}
		}
		while(ll <= mid){
			f[i++] = a[ll++];
		}
		while(rr <= r){
			f[i++] = a[rr++];
		}
		for(i=l;i <= r;i++){
			a[i]=f[i];
		}
	}
}
int main(){
	int i;
	int n=0;
	scanf("%d",&n); 
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	//printf("%lld\n",a[n]);
	ct=0;
	px(1,n);
	printf("%lld\n",ct);
}


