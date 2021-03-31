#include<bits/stdc++.h>
using namespace std;
const int mxn = 1000000000;
const int N = 305;
int l[N][N],r[N][N],w[N][N];
int lc[N],rc[N]; // lc顺时针，rc逆时针
int t[N],m[N];

void init(int n){
    lc[0] = rc[n] = 0;
    for(int i = 1; i < n; i++) lc[i] = lc[i-1] + t[i-1];
    for(int i = n-1; i >= 0; i--) rc[i] = rc[i+1] + t[i];//即从此处顺时针转回原点
    for(int i = 0; i < n; i++){
        w[i][i] = m[i];
        for(int j = i+1; j < n; j++){
            w[i][j] = w[i][j-1] + m[j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            i == j? l[i][j] = r[i][j] = 0 : l[i][j] = r[i][j] = mxn;
        }
    }
}

int main(){
    int n;
    while(cin >> n && n != 0){
        t[n] = m[n] = 0;
        for(int i = 0; i < n; i++){
            cin >> m[i] >> t[i];
        }
        init(++n);
        for(int k = 1; k < n; k++){
            for(int i = 0; i + k < n; i++){
                int j = i + k;
                l[i][j] = min(l[i+1][j] + t[i]*w[i+1][j], r[i+1][j] + (rc[j] + lc[i])*w[i+1][j]);
                r[i][j] = min(r[i][j-1] + t[j-1]*w[i][j-1], l[i][j-1] + (lc[i] + rc[j])*w[i][j-1]);
            }
        }
        cout << min(l[0][n-1],r[0][n-1]) << endl;
    }
}