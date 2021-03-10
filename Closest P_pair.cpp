#include<bits/stdc++.h>
using namespace std;

const int N = 100005;
const int mxn = 0x7fffffff;
int n;

struct Point{
    double x,y;
}p[N],tmp[N];

bool cmp_x(const Point &a,const Point &b){
    return a.x < b.x;
}

bool cmp_y(const Point &a, const Point &b){
    return a.y < b.y;
}

double get_dis(const Point &a, const Point &b){
    double dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

double find_mindis(int l, int r){
    double ret(mxn);
    if(l == r) return ret;
    int mid = (l+r) >> 1;
    ret = min(find_mindis(l,mid),find_mindis(mid+1,r));
    int cnt(0);
    for(int i = mid; i >= l && p[mid].x - p[i].x < ret; i--) tmp[cnt++] = p[i];
    for(int i = mid+1; i <=r && p[i].x - p[mid].x < ret; i++) tmp[cnt++] = p[i];
    sort(tmp,tmp+cnt,cmp_y);
    for(int i = 0; i < cnt; i++){
        for(int j = i+1; j < cnt && tmp[j].y-tmp[i].y < ret; j++){
            ret = min(ret,get_dis(tmp[i],tmp[j]));
        }
    }
    return ret;
}

int main(){
    while(cin >> n && n){
        for(int i = 0; i < n; i++)
            cin >> p[i].x >> p[i].y;
        sort(p,p+n,cmp_x);
        double dis = find_mindis(0,n-1)/2.0;
        cout << fixed << setprecision(2) << dis << endl;
    }
}