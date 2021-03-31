#include<bits/stdc++.h>
using namespace std;
int n;
int x[105],dp[105];

int main(){
    cin >> n;
    cin >> x[1];
    for(int i = 2; i <= n; i++){
        scanf(",%d",&x[i]);
    }
    dp[1] = x[1];
    int len = 1;
    for(int i = 2; i <= n; i++){
        if(x[i] >= dp[len]){
            dp[++len] = x[i];
        }else{
            int l = 1, r = len;
            while(l <= r){
                int mid = (l+r) >> 1;
                if(dp[mid] <= x[i]) l = mid+1;
                else r = mid - 1;
            }
            dp[l] = x[i];
        }
    }
    cout << len << endl;
}