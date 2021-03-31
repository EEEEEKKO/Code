#include<bits/stdc++.h>
const int INF = 0x7fffffff;
using namespace std;

vector<vector<int>> m(105,vector<int>(105));
vector<vector<int>> s(105,vector<int>(105));
vector<int> q(105);
int n;

void print_M(int i, int j){
    if(i == j){
        cout << 'A' << i;
        return;
    }
    cout << '(';
    print_M(i,s[i][j]);
    print_M(s[i][j]+1,j);
    cout << ')';
}

int M_mult(){
    for(int i = 1; i <= n; i++) m[i][i] = 0;
    for(int r = 1; r <= n-1; r++){
        for(int i = 1; i <= n-r; i++){
            int j = i+r;
            s[i][j] = i;
            m[i][j] = m[i][i] + m[i+1][j] + q[i-1]*q[i]*q[j];
            for(int k = i+1; k < j; k++){
                int tmp = m[i][k] + m[k+1][j] + q[i-1]*q[k]*q[j];
                if(m[i][j] > tmp){
                    m[i][j] = tmp;
                    s[i][j] = k;
                }
            }
        }
    }
    cout << m[1][n] << endl;
    print_M(1,n);
    cout << endl;
}
int main(){
    cin >> n;
    if(n == 1){
        cout << 0 << endl;
        cout << "(A1)" << endl;
        return 0;
    }
    for(int i = 0; i <= n; i++){
        cin >> q[i];
    }
    M_mult();
    system("pause");
}