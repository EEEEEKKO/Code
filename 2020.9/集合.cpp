#include<stdio.h>
#include<stdlib.h>

typedef struct students{
	double px, py;
	int pos;
	double ans;
}STU;

STU stu[500005];
double sumsum = 0;

double fabs(double x){
	if(x >= 0) return x;
	else return -x;
}

double min(double x, double y){
	if(x >= y) return y;
	else return x;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int k = 1; k <= T; k++){
		int n;
		scanf("%d", &n);
		double sumx = 0, sumy = 0;
		for(int i = 0; i < n; i++){
			scanf("%lf%lf", &stu[i].px, &stu[i].py);
			sumx += stu[i].px;
			sumy += stu[i].py;
		}
		double midx = sumx/n;
		double midy = sumy/n;
		double sum = 5e9;
		for(int i = 0; i < n; i++){
			stu[i].ans = fabs(stu[i].px-midx) + fabs(stu[i].py-midy);
			sum = min(stu[i].ans, sum);
		}
		for(int i = 0; i < n; i++){
			if(stu[i].ans == sum){
				midx = stu[i].px;
				midy = stu[i].py;
				break;
			}
		}
		printf("Case :%d\n", k);
		for(int i = 0; i < n; i++){
			stu[i].ans = fabs(stu[i].px-midx) + fabs(stu[i].py-midy);
			sumsum += stu[i].ans;
			printf("%.4lf\n", sumsum);
		}
	}
}
				
		
