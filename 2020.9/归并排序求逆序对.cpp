#include<bits/stdc++.h>

using namespace std;

const int mxn = 3e5 + 5;
int n; 
int a[mxn];
long long ans = 0;

void mergesort(int l, int mid, int r){
	int t[mxn];
	int i = l, j = mid + 1;
	int k = 0;
	while(i <= mid && j <= r){
		if(a[i] <= a[j])	t[k++] = a[i++];
		else{
			t[k++] = a[j++];
			ans += mid - i + 1;
		}
	}
	while(i <= mid){
		t[k++] = a[i++];
	}
	while(j <= r){
		t[k++] = a[j++];
	}
	for(int m = 0; m < k; m++){
		a[l+m] = t[m];
	}
}
	

void merge(int l, int r){
	if(l >= r) return;
	int mid = (l+r) >> 1;
	merge(l,mid);
	merge(mid+1,r);
	mergesort(l, mid, r);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	merge(1,n);
	printf("%lld\n", ans);
}

