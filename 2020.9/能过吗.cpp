#include<bits/stdc++.h>

using namespace std;

const long long mod = 2147483647;

int wood[2019];
long long dp[2019][2019]; 
long long ans = 0;

int main(){
    int n;
    memset(dp, 0, sizeof(dp));
    scanf("%d%d", &n, &wood[0]);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &wood[i]);
    }
    dp[0][wood[0]] = 1, dp[1][wood[0]] = 1;
    int temp;
    for (int i = 2; i <= n; i++){
        for (int j = 1; j <= n + 1; j++){
            if (j > wood[i - 1]){
                temp = j;                         
                wood[0] = wood[i - 1];
            }
            else{
                temp = wood[i - 1];
                wood[0] = j;
            }
            if (temp > wood[i]) dp[i][temp] = (dp[i][temp] + dp[i - 1][j]) % mod;   
            if (wood[0] < wood[i])dp[i][wood[0]] = (dp[i][wood[0]] + dp[i - 1][j]) % mod;
        }
    }
    for (int i = 1; i <= n + 1; i++) ans += dp[n][i];
    printf("%lld\n", ans%mod);
}
