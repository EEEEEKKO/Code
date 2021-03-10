#include<bits/stdc++.h>
using namespace std;

vector<int> y;

int find(int l,int r){
    int index = y[l];
    while(l < r){
        while(y[r] >= index && l < r) r--;
        swap(y[l],y[r]);
        while(y[l] <= index && l < r) l++;
        swap(y[l],y[r]);
    }
    y[l] = index;
    return l;
}

int get_mid(int left, int right, int k){
    if(left == right) return y[left];
    int i = find(left,right),j = i-left+1;
    if(k <= j){
        return get_mid(left,i,k);
    }else{
        return get_mid(i+1,right,k-j);
    }
}


int main(){
    int tx,ty;
    while(scanf("%d,%d",&tx,&ty)!=EOF){
        y.push_back(ty);
    }
    int n = y.size();
    int mid = get_mid(0,n-1,n/2+1);
    cout << mid << endl;
}