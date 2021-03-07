#include<bits/stdc++.h>

using namespace std;

double h2[10];
int h2_size = 0;

void swap(double *a, double *b){
	double t = *a;*a = *b;*b = t;
}

void insert_2(double val){//大根堆存小数 
	h2[++h2_size] = val;
	int now = h2_size, next;
	while(now > 1){
		next = now >> 1;
		if(h2[now] >= h2[next]) break;
		swap(&h2[now],&h2[next]);
		now = next;
	}
}

double get_top_2(){
	double out = h2[1];
	h2[1] = h2[h2_size--];
	int now = 1,next;
	while(now*2 <= h2_size){
		next = now << 1;
		if(next < h2_size && h2[next] < h2[next+1]) next++;
		if(h2[now] >= h2[next]) return out;
		swap(&h2[now],&h2[next]);
		now = next;
	}
	return out;
}

int main(){
	int n;
	cin >> n;
	for(int i = 1; i<= n; i++){
		double x;
		cin >> x;
		insert_2(x);
	}
	for(int i = 1; i <= n; i++){
		cout << get_top_2() << " ";
	}
}
