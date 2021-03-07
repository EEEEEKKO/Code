#include<bits/stdc++.h> 
using namespace std;
typedef long long LL;
const LL mod = 2147483647;

int s[2020];
LL dp[2020][2020],ans = 0; 

int main(){
    int n;
    scanf("%d", &n);
    memset(dp, 0, sizeof dp);
    int k = 0,temp;
    while (k <= n) scanf("%d", &s[k]),k++;
    dp[0][s[0]] = 1,dp[1][s[0]] = 1;
    for (int i = 2; i <= n; i++){
        for (int j = 1; j <= n + 1; j++){
            if (j > s[i - 1]) temp = j ,s[0] = s[i - 1];
            else temp = s[i - 1],s[0] = j;
            if (temp > s[i]) dp[i][temp] = (dp[i][temp] + dp[i - 1][j]) % mod;     
            if (s[0] < s[i])dp[i][s[0]] = (dp[i][s[0]] + dp[i - 1][j]) % mod;
        }
    }
    for (int i = 1; i < n + 2; i++) ans += dp[n][i];
    printf("%lld\n", ans%mod);
}
