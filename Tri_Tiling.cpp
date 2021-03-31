#include<bits/stdc++.h>
using namespace std;
const int mod = 9973;
typedef long long int LL;
LL n;
LL temp[2][2];
LL res[2][2],a[2][2] = {{4,-1},{1,0}};
void mul(LL (&a)[2][2], LL b[2][2])//矩阵乘法
{   
    memset(temp,0,sizeof(temp));
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            for(int k=0;k<2;k++){       
                temp[i][j]=(temp[i][j]+a[i][k]*b[k][j]%mod)%mod;
                if(temp[i][j] <= 0) temp[i][j]+=mod;
            }
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            a[i][j]=temp[i][j];
    return;
}
void fun(int nn)
{
    memset(res,0,sizeof(res));
    a[0][0] = 4,a[0][1] = -1, a[1][0] = 1,a[1][1] = 0;
    for(int i=0;i<2;i++)
        res[i][i]=1;
    while(nn){
        if(nn&1) mul(res,a);
        mul(a,a);
        nn>>=1;
    }
    return;
}

int main(){

    while((cin>>n)){
        if(n == -1) break;
        else if(n == 0) cout << 1 << endl;
        else if(n == 2) cout << 3 << endl;
        else if(n % 2) cout << 0 << endl;
        else{
            n /= 2;
            fun(n-1);
            LL ret = (res[0][0]*3+res[0][1]) % mod;
            cout << ret << endl;
        }
    }
}