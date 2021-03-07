#include<bits/stdc++.h>
#define INF 200002
using namespace std;

int n,k;
vector<double> a;

bool Cut(double x){
	int num = 0;
	for(int i = 0; i < n; i++){
		num+= static_cast<int>(a[i]/x);
	}
	return num >= k ? true:false;
}

int main(){
	cin >> n >> k;
	double tmp;
	for(int i = 0; i < n; i++){
		cin >> tmp;
		a.push_back(tmp);
	}
	double l = 0, r = INF;
	double mid = (l+r)/2;
	for(int i = 0; i < 100; i++){
		if(Cut(mid)) l = mid;
		else r = mid;
		mid = (l+r)/2;
	}
	printf("%.2f\n",floor(r*100)/100);
}

