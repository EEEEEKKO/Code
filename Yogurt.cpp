#include<bits/stdc++.h>
using namespace std;

int S,n,C,Y;

int main(){
    cin >> n >> S;
    cin >> C >> Y;
    long long sum = 0;
    sum += C*Y;
    int pre = C + S;
    for(int i = 1; i < n; i++){
        cin >> C >> Y;
        C = min(pre,C);
        pre = C+S;
        sum += C*Y;
    }
    cout << sum << endl;
}
