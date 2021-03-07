#include<bits/stdc++.h>

using namespace std;

const int MAXN = 5e5 + 5;
long long n, a[MAXN];
long long dp[MAXN], st, ed, ans;

queue<long long> q;

int main(){
		scanf("%lld", &n);
		memset(a, 0, sizeof(a));
		memset(dp, 0, sizeof(dp));
		ed = 0, ans = 0, st = 0;
		for(int i = 1; i <= n; i++){
			scanf("%lld", &a[i]);
			q.push(a[i]);
		}
		for(int i = 1; i <= n; i++){ 
			if(dp[i-1] + q.front() == q.front() && i != 1) break;
			dp[i] = max(dp[i-1] + q.front(), q.front());
			if(ans < dp[i]){
				ans = dp[i];
				ed = i;
			}
			if(ans > dp[i] && i != 1) break;
			q.pop();
		}
		q.pop();
		cout << "ed" << ed <<endl;
		memset(dp,0,sizeof(dp));
		long long ans2 = 0;
		int ed2 = ed,st2;
		for(int i = ed + 1; i <= n; i++){
			if(dp[i-1] + q.front() == q.front() && i != ed+1) break;
			dp[i] = max(dp[i-1] + q.front(),q.front());
			if(ans2 < dp[i]){
				ans2 = dp[i];
				ed2 = i;
			}
			if(ans > dp[i] && i != 1) break;
			q.pop();
		}
		memset(dp,0,sizeof(dp));
		long long ans3 = 0;
		int ed3 = ed2,st3;
		for(int i = ed2 + 1; i <= n; i++){
			if(dp[i-1] + q.front() == q.front() && i != ed2 + 1) break;
			dp[i] = max(dp[i-1] + q.front(),q.front());
			if(ans3 < dp[i]){
				ans3 = dp[i];
				ed3 = i;
			}
			if(ans > dp[i] && i != 1) break;
			q.pop();
		}
		cout << ans << endl;
		cout << ans2 << endl;
		cout << ans3 << endl;
		printf("%lld\n",ans + ans2 + ans3);		
}
