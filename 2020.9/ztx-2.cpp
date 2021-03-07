#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
const long long mod = 2147483647;

int s[2019];
long long dp[2019][2019]={0};  //先设置初始化 

int main()
{
 int i,j,n,k,t;
 long long result = 0; 
 i=1;
 scanf("%d%d", &n, &k);
 while(i<=n)
 {
  scanf("%d",&s[i]);
  i++;
 }
 dp[0][k] = 1;
 dp[1][k] = 1;
 for (i=2;i<=n;i++)
 {
  for (j=1;j<=n+1;j++)
  {
    if(j>s[i-1])
	{
     t=j;                         //要找最大和最小 
     k=s[i-1];
    }
  else
  {
   t=s[i-1];
   k=j;
  }
   if (t>s[i])
    dp[i][t] = (dp[i][t] + dp[i - 1][j]) % mod;   //一定记得要取模 
   if (k<s[i])
    dp[i][k] = (dp[i][k] + dp[i - 1][j]) % mod;

  }
 }
 i = 1; 
 while(i<n+2)
 {
  result+=dp[n][i];
  i++;
 } 
 result%= mod;
 printf("%lld\n",result);
 return 0;
}
