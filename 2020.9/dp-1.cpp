#include <bits/stdc++.h>

using namespace std;

const int mxn = 2e3 + 5;
const long long  bor = 2147483647;
long long  dp[mxn][mxn][2];
int wood[mxn];
//dp[i][j][0]和dp[i][j][1]分别表示第i个小木条的非箭头端点在j，朝左或朝右的方案数

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        scanf("%d", &wood[i]);
    }
    memset(dp, 0, sizeof(dp));
    dp[1][wood[0]][1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = wood[i] + 1; j <= n + 1; j++) {
            dp[i][j][0] += dp[i - 1][j][0];
            if (dp[i][j][0] >= bor) dp[i][j][0] -= bor;
        }
        if (wood[i - 1] > wood[i]) {
            for (int j = 1; j < wood[i - 1]; j++) {
                dp[i][wood[i - 1]][0] += dp[i - 1][j][1];
                if (dp[i][wood[i - 1]][0] >= bor) dp[i][wood[i - 1]][0] -= bor;
            }
        }
        for (int j = 1; j < wood[i]; j++) {
            dp[i][j][1] += dp[i - 1][j][1];
        }
        if (wood[i - 1] < wood[i]) {
            for (int j = wood[i - 1] + 1; j <= n + 1; j++) {
                dp[i][wood[i - 1]][1] += dp[i - 1][j][0];
                if (dp[i][wood[i - 1]][1] >= bor) dp[i][wood[i - 1]][1] -= bor;
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n + 1; i++) {
        ans = (ans + dp[n][i][0] + dp[n][i][1]) % bor;
    }
    printf("%lld\n", ans);
    return 0;
}
