#include<bits/stdc++.h>  

using namespace std;

typedef long long LL;
const int mxn = 5e5 + 5;

LL dp[mxn][6][2], a[mxn];

int main() {
	int n;
	long long ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%lld", &a[i]);
	}
	memset(dp, 0, sizeof(dp));
	dp[0][0][0] = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= 3; j++){
			dp[i][j][0] = max(dp[i - 1][j][0],dp[i-1][j][1]);
			if (j >= 1) dp[i][j][1] = max(dp[i - 1][j - 1][0] + a[i - 1], dp[i - 1][j - 1][1] + a[i - 1]);
			dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j][1] + a[i - 1]);
		}
	}
	ans = max(dp[n][3][0],dp[n][3][1]);
	cout << ans << endl;
}
